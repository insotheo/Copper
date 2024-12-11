#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <utility>
#include <memory>
#include <variant>

#include "Token/TokenType.hpp"
#include "Lexer/Lexer.hpp"
#include "LangDefs/Variable.hpp"
#include "LangDefs/DataTypes.hpp"
#include "LangDefs/VarValOperators.hpp"

namespace Herbata{

    class Parser{
    public:
        Parser(const Lexer& lexer): m_lexer(lexer) {}

        void Parse();

    private:
        Lexer m_lexer;
        Token token;

        inline void goNext() {token = m_lexer.NextToken();}

        void ParseStatement();
        void ParseAssignment(const std::string& identifier);

        //Parsing expressions
        TokenType m_expressionStopToken = TokenType::None;
        VarVal ParseExpression();
        VarVal factor();
        VarVal term();
        VarVal expression();

        //Declarations parsing
        void ParseVariableDeclaration();

        VariablesManager m_VarsManager;
    };

}

#endif