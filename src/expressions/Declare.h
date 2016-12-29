#ifndef DECLARE_H
#define DECLARE_H
#include "Token.h"
#include <iostream>
#include <sstream>


class Declare : public Token {
    public:
        void execute(std::vector<std::string> argz);

        Declare(Memory *memory, std::vector<Token*> *L_LIB);
};

#endif
