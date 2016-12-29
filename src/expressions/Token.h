#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <vector>
#include "../Memory.h"


bool isQuoted(std::string str);
bool isNumeric(const std::string& s);
std::string strReplace(std::string ori, std::string _new, std::string str);
std::string unquote(std::string str);
std::string extractArguments(std::string line);

extern bool inlineCall;

class Token {
    public:
        std::string name;
        std::string closing_name;
        std::string returnValue;
        Memory * memory;
        std::vector<Token*> * L_LIB;
        Token * findToken(std::string word, std::vector<Token*> * L_LIB);
        
        virtual void execute(std::vector<std::string> argz) = 0;

        Token(Memory *memory, std::vector<Token*> *L_LIB);
};

#endif
