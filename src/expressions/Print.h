#ifndef PRINT_H
#define PRINT_H
#include "Token.h"


class Print : public Token {
    public:
        void execute(std::vector<std::string> argz);

        Print();
};

#endif
