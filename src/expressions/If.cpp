#include "If.h"


If::If() : Token() {
    this->name = "If";
    this->closing_name = "End If";
}

void If::execute(std::vector<std::string> argz) {}
