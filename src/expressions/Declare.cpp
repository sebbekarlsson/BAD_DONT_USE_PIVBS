#include "Declare.h"


Declare::Declare(Memory *memory, std::vector<Token*> *L_LIB) : Token (memory, L_LIB) {
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

    std::istringstream iss2(argz[1]);
    std::string word;
    Token * rightHandToken;

    while(iss2 >> word) {
        rightHandToken = findToken(word, L_LIB);
    }

    if (rightHandToken != NULL) {
        std::string _unparsedArgs = extractArguments(argz[1]);
        std::vector<std::string> elems;

        if (_unparsedArgs.find(",") != std::string::npos) {
            std::stringstream ss;
            ss.str(_unparsedArgs);
            std::string item;
            while (std::getline(ss, item, ',')) {
                while(item.find(" ") != std::string::npos) {
                    item.replace(
                            item.find(" "),
                            std::string(" ").size(),
                            ""
                            );
                }

                if (isQuoted(item)) {
                    elems.push_back(unquote(item));
                } else {
                    elems.push_back(this->memory->getVar(item));
                }
            }
        }

        if (elems.size() > 0) {
            rightHandToken->execute(elems);
            std::cout << argz[1] << std::endl;
            argz[1] = rightHandToken->returnValue;
        } else {
            if (isQuoted(_unparsedArgs)) {
                elems.push_back(unquote(_unparsedArgs));
            } else {
                elems.push_back(this->memory->getVar(_unparsedArgs));
            }
            rightHandToken->execute(elems);
            argz[1] = rightHandToken->returnValue;
        }
        
        inlineCall = true;
    }
    
    memory->defineVar(argz[0], argz[1]);
}
