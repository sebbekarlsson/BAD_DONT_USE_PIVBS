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

    while(argz[1].find("\"") != std::string::npos) {
        argz[1].replace(
                argz[1].find("\""),
                std::string("\"").size(),
                ""
                );
    }
    memory->defineVar(argz[0], argz[1]);
}
