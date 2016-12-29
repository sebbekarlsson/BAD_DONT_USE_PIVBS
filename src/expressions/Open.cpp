#include "Open.h"


Open::Open(Memory *memory, std::vector<Token*> *L_LIB) : Token (memory, L_LIB) {
    this->name = "Open";
}

void Open::execute (std::vector<std::string> argz) {
    ResourceManager::load(argz[0]);
    this->returnValue = ResourceManager::get(argz[0]);
}
