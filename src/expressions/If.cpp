#include "If.h"


If::If(Memory *memory, std::vector<Token*> *L_LIB) : Token(memory, L_LIB) {
    this->name = "If";
    this->closing_name = "End If";
}

void If::execute(std::vector<std::string> argz) {}
