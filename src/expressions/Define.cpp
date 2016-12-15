#include "Define.h"


Define::Define(Memory *memory) : Token (memory) {
    this->name = "Dim";
}

void Define::execute (std::vector<std::string> argz) {
    
    for (auto it = begin (argz); it != end (argz); ++it) {
        memory->defineVar(*it, "NULL");
    }
}
