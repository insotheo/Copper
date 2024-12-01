#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <variant>
#include <memory>
#include <typeinfo>

#include "Token/TokenType.hpp"
#include "Lexer/Lexer.hpp"
#include "LangDefs/Variable.hpp"
#include "LangDefs/DataTypes.hpp"

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

        void ParseVariableDeclaration(const std::string& ident, const DataType& type);

        VariablesManager m_VarsManager;

    };

}

#endif