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
        m_VarsManager.print(); //DBG ONLY
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
        m_VarsManager.CreateVariable(ident, type);
    }

}