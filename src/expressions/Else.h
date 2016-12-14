#ifndef ELSE_H
#define ELSE_H
#include "Token.h"


class Else : public Token {
    public:
        void execute(std::vector<std::string> argz);

        Else();
};

#endif
