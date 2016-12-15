#include "Declare.h"


Declare::Declare(Memory *memory) : Token (memory) {
    this->name = "=";
}

void Declare::execute (std::vector<std::string> argz) {
    if (this->memory->vars.count(argz[0]) == 0) {
        std::cerr <<
            "[ERROR]: Trying to assign undeclared variable: " << argz[0] <<
            " - Please use 'Dim'"
            << std::endl;
        exit(1);
    }

    if (isQuoted(argz[0])) {
        argz[0] = unquote(argz[0]);
    }

    if (isQuoted(argz[1])) {
        argz[1] = unquote(argz[1]);
    }

    memory->defineVar(argz[0], argz[1]);
}
