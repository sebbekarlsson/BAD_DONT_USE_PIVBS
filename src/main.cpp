#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include "Memory.h"
#include "lexing.h"


int main (int argc, char ** argv) {
    Memory memory;

    If* L_if = new If(&memory);
    Else* L_else = new Else(&memory);
    Define* L_define = new Define(&memory);
    Declare* L_declare = new Declare(&memory);
    Print* L_print = new Print(&memory);
    Echo* L_echo = new Echo(&memory);

    L_LIB.push_back(&*L_if);
    L_LIB.push_back(&*L_else);
    L_LIB.push_back(&*L_define);
    L_LIB.push_back(&*L_declare);
    L_LIB.push_back(&*L_print);
    L_LIB.push_back(&*L_echo);

    std::ifstream infile(argv[1]);

    for(std::string line; getline(infile, line);) {
        std::istringstream iss(line);
        std::string word;
        std::vector<std::string> argz;
        std::string fargs = "";
        std::string first_char = "";
        unsigned first = 0;
        unsigned last = 0;
        bool call = false;
        bool expr = false;

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
            fargs = line.substr(first+1, (last-1) - first);
            first = 0;
            last = 0;
            call = true;
        }

        while(iss >> word) {
            Token * t = NULL;

            for (auto it = begin (L_LIB); it != end (L_LIB); ++it) {
                std::string n = word;
                n = n.substr(0, n.find("(", 0));

                Token * tt = &**it;
                if (tt->name == n) {
                    t = &**it;
                }
            }
            if (t == NULL) { continue; }
            
            /* Parse assignments */
            if (t->name == "=") {
                std::vector<std::string> elemz;
                std::stringstream sss;
                sss.str(line);
                std::string ztem;
                while (std::getline(sss, ztem, '=')) {
                    while(ztem.find(" ") != std::string::npos) {
                        ztem.replace(
                                ztem.find(" "),
                                std::string(" ").size(),
                                ""
                                );
                    }
                    argz.push_back(ztem);
                }

                expr = true;
            }
            
            /* Parse expressions, (Dim, If, Else.. etc) */
            first = line.find_first_of(" ");
            if (first < 1000 && !call) {
                fargs = line.substr(first+1, (line.size()-1) - first);
                expr = true;
            }

            if (fargs != "") {

                /* Check if trying to access variable */
                if (fargs.at(0) == '"' && fargs.back() == '"') {
                    unsigned first = fargs.find_first_of('"');
                    unsigned last = fargs.find_last_of('"');

                    if (first < 1000 && last < 1000) {
                        fargs = fargs.substr(first+1, (last-1) - first);
                        /* Not a variable */
                    }
                } else {
                    /* Probably a variable */
                    if (t->name != "Dim") {
                        fargs = memory.getVar(fargs);
                    }
                }

                if (expr) {
                    /* Parse expression data */
                    if (fargs.find(",") != std::string::npos) {
                        std::vector<std::string> elems;
                        std::stringstream ss;
                        ss.str(fargs);
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
                        
                        argz = elems;
                    }
                }

                argz.push_back(fargs);
            }

            t->execute(argz);    
        }
    }

    return 0;
}
