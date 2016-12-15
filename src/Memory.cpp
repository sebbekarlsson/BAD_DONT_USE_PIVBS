#include "Memory.h"


void Memory::defineVar(std::string key, std::string value) {
    if (this->vars.find(key) == vars.end()) {
        this->vars[key] = value;
    } else {
        this->vars[key] = value;
    }
}

std::string Memory::getVar(std::string key) {
    if (this->vars.count(key) == 0) {
        std::cerr <<
            "[ERROR]: Trying to assign undeclared variable: " << key <<
            " - Please use 'Dim'"
            << std::endl;
        exit(1);
    }
    return this->vars[key];
}
