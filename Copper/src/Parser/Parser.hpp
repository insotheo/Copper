#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>

#include "Token/TokenType.hpp"
#include "Lexer/Lexer.hpp"

namespace Copper{

    class Parser{
    public:
        Parser(const Lexer& lexer): lexer(lexer){}

        void ParseExpression();

    private:
        Lexer lexer;
    };

}

#endif