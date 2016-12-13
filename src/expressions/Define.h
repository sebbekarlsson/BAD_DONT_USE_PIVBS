#ifndef DEFINE_H
#define DEFINE_H
#include "Token.h"


class Define : public Token {
    public:
        void execute(char ** argz);

        Define();
};

#endif
