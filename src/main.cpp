#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "lexing.h"


int main (int argc, char ** argv) {
    If i;
    Else e;
    Define d;
    Print p;

    L_LIB.push_back(&i);
    L_LIB.push_back(&e);
    L_LIB.push_back(&d);
    L_LIB.push_back(&p);

    std::ifstream infile(argv[1]);

    for(std::string line; getline(infile, line);) {
        std::istringstream iss(line);
        std::string word;

        while(iss >> word) {
            Token * t = NULL;
            char ** argz = NULL;

            for (auto it = begin (L_LIB); it != end (L_LIB); ++it) {
                std::string n = word;
                n = n.substr(0, n.find("(", 0));
                
                Token * tt = &**it;
                if (tt->name == n) {
                    t = &**it;
                }
            }
            
            if (t == NULL) { continue; }
            
            std::cout << "FOUND TOKEN [ " << t->name << " ]" << std::endl;
            t->execute(argz);    
        }
    }

    return 0;
}
