#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "lexing.h"


int main (int argc, char ** argv) {
    L_LIB.push_back(*new If());
    L_LIB.push_back(*new Else());

    std::ifstream infile(argv[1]);

    for(std::string line; getline(infile, line);) {
        std::istringstream iss(line);
        std::string word;

        while(iss >> word) {
            Token * t = NULL;
            for (auto it = begin (L_LIB); it != end (L_LIB); ++it) {
                if (it->name == word) {
                    t = &*it;
                }
            }
            
            if (t == NULL) { continue; }
            
            std::cout << t->name << std::endl;
        }
    }

    return 0;
}
