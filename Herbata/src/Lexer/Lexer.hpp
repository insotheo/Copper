#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <unordered_map>

#include "Token/Token.hpp"

namespace Herbata{

    class Lexer{
    public:
        Lexer(const std::string& text) : text(text), pos(0){}
        
        Token NextToken();

    private:
        std::string text;
        size_t pos;
    };

}

#endif