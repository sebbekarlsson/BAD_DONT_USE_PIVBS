#include "Echo.h"


Echo::Echo(Memory *memory) : Token (memory) {
    this->name = "Wscript.Echo";
}

void Echo::execute(std::vector<std::string> argz) {
    std::cout << argz[0] << std::endl;
}
