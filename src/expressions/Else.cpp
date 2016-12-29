#include "Else.h"


Else::Else(Memory *memory, std::vector<Token*> *L_LIB) : Token (memory, L_LIB) {
    this->name = "Else";
}

void Else::execute(std::vector<std::string> argz) {}
