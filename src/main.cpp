#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>
#include "lexing.h"


int main (int argc, char ** argv) {
    If L_if;
    Else L_else;
    Define L_define;
    Print L_print;
    Echo L_echo;

    L_LIB.push_back(&L_if);
    L_LIB.push_back(&L_else);
    L_LIB.push_back(&L_define);
    L_LIB.push_back(&L_print);
    L_LIB.push_back(&L_echo);

    std::ifstream infile(argv[1]);

    for(std::string line; getline(infile, line);) {
        std::istringstream iss(line);
        std::string word;
        std::vector<std::string> argz;
        std::string fargs = "";

        unsigned first = line.find_first_of("(");
        unsigned last = line.find_last_of(")");

        if (first < 1000 && last < 1000)
            fargs = line.substr(first+1, (last-1) - first);

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

            if (fargs != "") {
                argz.push_back(fargs);
            }

            t->execute(argz);    
        }
    }

    return 0;
}
