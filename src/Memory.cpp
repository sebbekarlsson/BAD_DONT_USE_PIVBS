#include "Memory.h"


void Memory::defineVar(std::string key, std::string value) {
    if (this->vars.find(key) == vars.end()) {
        this->vars[key] = value;
    } else {
        this->vars[key] = value;
    }
}

std::string Memory::getVar(std::string key) {
    return this->vars[key];
}
