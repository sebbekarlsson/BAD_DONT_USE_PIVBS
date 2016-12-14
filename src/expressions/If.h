#ifndef IF_H
#define IF_H
#include "Token.h"


class If : public Token {
    public:
        void execute(std::vector<std::string> argz);

        If();
};

#endif
