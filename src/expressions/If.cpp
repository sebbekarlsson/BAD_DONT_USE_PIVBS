#include "If.h"


If::If(Memory *memory) : Token(memory) {
    this->name = "If";
    this->closing_name = "End If";
}

void If::execute(std::vector<std::string> argz) {}
