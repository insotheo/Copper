#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "Token/TokenType.hpp"
#include "Lexer/Lexer.hpp"

namespace Copper{

    class Parser{
    public:
        Parser(const Lexer& lexer): lexer(lexer){}

        void Parse();

    private:
        Lexer lexer;
        Token token;

        inline void goNext() {token = lexer.NextToken();}

        void ParseStatement();
        void ParseExpression();
        void ParseAssignment();
        void ParseDeclaration();

    };

}

#endif