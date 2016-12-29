#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include "Memory.h"
#include "lexing.h"
#include "stringtools.h"


int main (int argc, char ** argv) {
    Memory memory;

    If* L_if = new If(&memory, &L_LIB);
    Else* L_else = new Else(&memory, &L_LIB);
    Define* L_define = new Define(&memory, &L_LIB);
    Declare* L_declare = new Declare(&memory, &L_LIB);
    Print* L_print = new Print(&memory, &L_LIB);
    Echo* L_echo = new Echo(&memory, &L_LIB);
    Open* L_open = new Open(&memory, &L_LIB);

    L_LIB.push_back(&*L_if);
    L_LIB.push_back(&*L_else);
    L_LIB.push_back(&*L_define);
    L_LIB.push_back(&*L_declare);
    L_LIB.push_back(&*L_print);
    L_LIB.push_back(&*L_echo);
    L_LIB.push_back(&*L_open);

    std::ifstream infile(argv[1]);

    for(std::string line; getline(infile, line);) {
        std::istringstream iss(line);
        std::string word;
        std::vector<std::string> executionArgs;
        std::string unparsedArgs = "";
        std::string first_char = "";
        first = 0;
        last = 0;
        call = false;
        statement = false;
        argsParseDone = false;
        inlineCall = false;
        
        /* Ignore line if starts with comment */
        if (line.size() > 1) {
            first_char = line.at(0);
            if(first_char == "'") {
                continue;
            }
        }
        
        /* Parse function-call arguments */
        first = line.find_first_of("(");
        last = line.find_last_of(")");
        if (first < 1000 && last < 1000) {
            unparsedArgs = line.substr(first+1, (last-1) - first);
            first = 0;
            last = 0;
            call = true;
        }

        while(iss >> word) {
            Token * t = findToken(word, L_LIB);
            if (t == NULL) { continue; }
            
            /* Parse assignments */
            if (t->name == "=") {
                std::vector<std::string> elemz;
                std::stringstream sss;
                sss.str(line);
                std::string ztem;
                int eCount = 0;
                while (std::getline(sss, ztem, '=')) {
                    std::stringstream ss;
                    std::string item;
                    ss.str(ztem);
                    std::string realztem = "";

                    while (std::getline(ss, item, '+')) {
                        item = strReplace(" \"", "\"", item);
                        
                        if (isQuoted(item)) {
                            realztem += unquote(item);
                        } else if (item.find("(") == std::string::npos)  {
                            item = strReplace(" ", "", item);

                            if (!isNumeric(item)) {
                                std::string varValue = memory.getVar(item);
                                if (isNumeric(varValue) && realztem != "") {
                                    realztem = std::to_string(std::stoi(varValue) + std::stoi(realztem)); 
                                } else {
                                    realztem += varValue;
                                }
                            } else {
                                if (realztem != "") {
                                    realztem = std::to_string(std::stoi(item) + std::stoi(realztem));
                                } else {
                                    realztem += item; 
                                }
                            }
                        }

                        if (eCount == 0) { realztem = item; }
                    }
                    
                    if (!isQuoted(realztem)) {
                        realztem = strReplace(" ", "", realztem);
                    }

                    if (realztem == "") { realztem = ztem; }
                    
                    executionArgs.push_back(realztem);
                    eCount++;
                }

                statement = true;
            }
            
            /* Parse tokens, (Dim, If, Else.. etc) */
            first = line.find_first_of(" ");
            if (first < 1000 && !call && !statement) {
                unparsedArgs = line.substr(first+1, (line.size()-1) - first);
                statement = true;
            }

            if (unparsedArgs != "") {
                /* Check if trying to access variable */

                if (unparsedArgs.at(0) == '"') {
                    if (unparsedArgs.back() == '"') {
                        unsigned first = unparsedArgs.find_first_of('"');
                        unsigned last = unparsedArgs.find_last_of('"');

                        if (first < 1000 && last < 1000) {
                            /* Not a variable */

                            unparsedArgs = unparsedArgs.substr(first+1, (last-1) - first);
                        }
                    } else {
                        std::stringstream ss;
                        ss.str(unparsedArgs);
                        std::string item;
                        unparsedArgs = "";

                        while (std::getline(ss, item, '+')) {
                            if (isQuoted(item)) {
                                unparsedArgs += unquote(item);
                            } else {
                                unparsedArgs += memory.getVar(strReplace(" ", "", item));
                            }
                        }
                    }
                } else {
                    /* Probably a variable */

                    if (t->name != L_define->name && !argsParseDone && !statement) {
                        unparsedArgs = memory.getVar(unparsedArgs);
                    }
                }

                if (statement) {
                    /* Parse statement data */

                    if (unparsedArgs.find(",") != std::string::npos && !argsParseDone) {
                        std::vector<std::string> elems;
                        std::stringstream ss;
                        ss.str(unparsedArgs);
                        std::string item;
                        while (std::getline(ss, item, ',')) {
                            while(item.find(" ") != std::string::npos) {
                                item.replace(
                                        item.find(" "),
                                        std::string(" ").size(),
                                        ""
                                        );
                            }
                            elems.push_back(item);
                        }

                        executionArgs = elems;
                    }
                }

                executionArgs.push_back(unparsedArgs);
            }
            
            if (!inlineCall) {
                t->execute(executionArgs);
            } 
        }
    }

    return 0;
}
