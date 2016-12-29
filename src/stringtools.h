#ifndef STRINGTOOLS_H
#define STRINGTOOLS_H


bool isQuoted(std::string str) {
    return str.find_first_of('"') == 0 &&
        str.find_last_of('"') != 0;
}

bool isNumeric(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
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

Token * findToken(std::string word, std::vector<Token*> L_LIB) {
    Token * t = NULL;

    for (auto it = begin (L_LIB); it != end (L_LIB); ++it) {
        std::string n = word;
        n = n.substr(0, n.find("(", 0));

        Token * tt = &**it;
        if (tt->name == n) {
            t = &**it;
        }
    }

    return t;
}


std::string extractArguments(std::string line) {
    std::string unparsedArgs;

    unsigned first;
    unsigned last;

    first = line.find_first_of("(");
    last = line.find_last_of(")");
    if (first < 1000 && last < 1000) {
        unparsedArgs = line.substr(first+1, (last-1) - first);
    }

    return unparsedArgs;
}

#endif
