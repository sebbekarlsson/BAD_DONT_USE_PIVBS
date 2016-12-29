#include "Print.h"


Print::Print(Memory *memory, std::vector<Token*> *L_LIB) : Token (memory, L_LIB) {
    this->name = "response.write";
}

void Print::execute(std::vector<std::string> argz) {
    std::cout << argz[0] << std::endl;
}
