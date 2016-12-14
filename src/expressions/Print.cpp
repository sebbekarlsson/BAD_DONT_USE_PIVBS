#include "Print.h"


Print::Print(Memory *memory) : Token (memory) {
    this->name = "response.write";
}

void Print::execute(std::vector<std::string> argz) {
    std::cout << argz[0] << std::endl;
}
