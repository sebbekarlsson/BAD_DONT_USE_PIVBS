#ifndef STRINGTOOLS_H
#define STRINGTOOLS_H


bool isQuoted(std::string str) {
    return str.find_first_of('"') == 0 &&
        str.find_last_of('"') != 0;
}

std::string strReplace(std::string ori, std::string _new, std::string str) {
    while(str.find(ori) != std::string::npos) {
        str.replace(
            str.find(ori),
            std::string(ori).size(),
            _new
            );
    }

    return str;
}

std::string unquote(std::string str) {
    return strReplace("\"", "", str);
}


#endif
