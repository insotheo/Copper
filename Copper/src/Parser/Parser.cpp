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
        goNext();
        std::cout << token.value << "\n";
    }

}