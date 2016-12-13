#include "Print.h"


Print::Print() : Token () {
    this->name = "response.write";
}

void Print::execute(char ** argz) {
    std::cout << argz << std::endl;
}
