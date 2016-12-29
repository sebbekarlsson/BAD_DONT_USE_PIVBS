#ifndef OPEN_H
#define OPEN_H
#include "Token.h"
#include <ResourceManager.h>


class Open : public Token {
    public:
        void execute(std::vector<std::string> argz);

        Open(Memory *memory, std::vector<Token*> *L_LIB);
};

#endif
