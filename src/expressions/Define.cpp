#include "Define.h"


Define::Define(Memory *memory, std::vector<Token*> *L_LIB) : Token (memory, L_LIB) {
    this->name = "Dim";
}

void Define::execute (std::vector<std::string> argz) {
    
    for (auto it = begin (argz); it != end (argz); ++it) {
        memory->defineVar(*it, "NULL");
    }
}
