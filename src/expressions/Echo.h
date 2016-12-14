#ifndef ECHO_H
#define ECHO_H
#include "Token.h"


class Echo : public Token {
    public:
        void execute(std::vector<std::string> argz);

        Echo();
};

#endif
