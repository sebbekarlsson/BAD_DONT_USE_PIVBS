#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <vector>
#include "../Memory.h"


class Token {
    public:
        std::string name;
        std::string closing_name;
        Memory * memory;
        
        virtual void execute(std::vector<std::string> argz) = 0;

        Token(Memory *memory);
};

#endif
