#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>


class Token {
    public:
        std::string name;
        std::string closing_name;
        
        virtual void execute(char ** argz) = 0;

        Token();
};

#endif
