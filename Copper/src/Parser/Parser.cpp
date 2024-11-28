#include "Parser/Parser.hpp"

namespace Copper{

    void Parser::Parse(){
        token = lexer.NextToken();

        while(token.type != TokenType::End){
            if(token.type == TokenType::Invalid){
                throw std::runtime_error("Invalid token: '" + (std::string)token.value + "'");
            }
            else if(token.type == TokenType::CommandEnd){
                goNext();
            }
            else{
                ParseStatement();
                goNext();
            }
        }
        std::cout << m_vars.size() << "\n";
    }

    void Parser::ParseStatement(){
        if(token.type == TokenType::INT 
        || token.type == TokenType::FLOAT 
        || token.type == TokenType::STRING 
        || token.type == TokenType::CHAR 
        || token.type == TokenType::BOOLEAN)
        {
            ParseDeclaration();
        }
    }

    void Parser::ParseExpression(){

    }

    void Parser::ParseAssignment(){

    }

    void Parser::ParseDeclaration(){
        TokenType dataType = token.type; //getting data type
        goNext();
        if(token.type != TokenType::Identifier){
            throw std::runtime_error("Identifier expected insted of \"" + token.value + "\"!");
        }
        std::string identifier = token.value;

        //check if its not function declaration
        goNext();
        if(token.type != TokenType::RightParen){
            ParseVariableDeclaration(identifier, TokenToDataType(dataType));
        }
    }

    void Parser::ParseVariableDeclaration(const std::string& ident, const DataType& type){
        switch (type)
        {
        case DataType::INT: m_vars.emplace_back(std::pair(std::move(ident), Variable<int>(type, 0))); break;
        case DataType::FLOAT: m_vars.emplace_back(std::pair(std::move(ident), Variable<float>(type, 0.0f))); break;
        case DataType::STRING: m_vars.emplace_back(std::pair(std::move(ident), Variable<std::string>(type, ""))); break;
        case DataType::CHAR: m_vars.emplace_back(std::pair(std::move(ident), Variable<char>(type, ' '))); break;
        case DataType::BOOLEAN: m_vars.emplace_back(std::pair(std::move(ident), Variable<bool>(type, false))); break;
        }
    }

}