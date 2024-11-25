#include "Parser/Parser.hpp"

namespace Copper{

    void Parser::ParseExpression(){
        Token token = lexer.NextToken();

        while(token.type != TokenType::End){
            if(token.type == TokenType::Invalid){
                throw std::runtime_error("Invalid token: '" + (std::string)token.value + "'");
            }

            if(token.type == TokenType::SingleCharText){
                std::cout << token.value << "\n";
            }

            token = lexer.NextToken();
        }

    }

}