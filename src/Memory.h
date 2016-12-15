#ifndef MEMORY_H
#define MEMORY_H
#include <iostream>
#include <map>


class Memory {
    public:
        std::map<std::string, std::string> vars;

        void defineVar(std::string key, std::string value);
        std::string getVar(std::string key);

        //Memory();
};

#endif
