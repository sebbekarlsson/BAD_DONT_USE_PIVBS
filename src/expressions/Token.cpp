#include "Token.h"


Token::Token (Memory *memory, std::vector<Token*> *L_LIB) {
    this->memory = memory;
    this->L_LIB = L_LIB;
}

Token * Token::findToken(std::string word, std::vector<Token*> * L_LIB) {
    Token * t = NULL;

    for (auto it = begin (*L_LIB); it != end (*L_LIB); ++it) {
        std::string n = word;
        n = n.substr(0, n.find("(", 0));

        Token * tt = &**it;
        if (tt->name == n) {
            t = &**it;
        }
    }

    return t;
}
