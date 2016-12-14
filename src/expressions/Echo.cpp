#include "Echo.h"


Echo::Echo() : Token () {
    this->name = "Wscript.Echo";
}

void Echo::execute(std::vector<std::string> argz) {
    std::cout << argz[0] << std::endl;
}
