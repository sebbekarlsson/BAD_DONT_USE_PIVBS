#ifndef PRINT_H
#define PRINT_H
#include "Token.h"


class Print : public Token {
    public:
        void execute(char ** argz);

        Print();
};

#endif
