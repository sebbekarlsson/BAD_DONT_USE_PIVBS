#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <vector>


class Token {
    public:
        std::string name;
        std::string closing_name;
        
        virtual void execute(std::vector<std::string> argz) = 0;

        Token();
};

#endif
