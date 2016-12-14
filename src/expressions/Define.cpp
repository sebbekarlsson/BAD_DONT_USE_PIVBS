#include "Define.h"


Define::Define(Memory *memory) : Token (memory) {
    this->name = "Dim";
}

void Define::execute (std::vector<std::string> argz) {
    memory->defineVar(argz[0], "NULL");
}
