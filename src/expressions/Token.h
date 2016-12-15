#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <vector>
#include "../Memory.h"


bool isQuoted(std::string str);
std::string strReplace(std::string ori, std::string _new, std::string str);
std::string unquote(std::string str);


class Token {
    public:
        std::string name;
        std::string closing_name;
        Memory * memory;
        
        virtual void execute(std::vector<std::string> argz) = 0;

        Token(Memory *memory);
};

#endif
