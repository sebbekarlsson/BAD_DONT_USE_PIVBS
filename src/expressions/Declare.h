#ifndef DECLARE_H
#define DECLARE_H
#include "Token.h"


class Declare : public Token {
    public:
        void execute(std::vector<std::string> argz);

        Declare(Memory *memory);
};

#endif
