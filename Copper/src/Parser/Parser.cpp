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
        if(token.type == TokenType::LET)
        {
            ParseVariableDeclaration();
        }
    }

    void Parser::ParseAssignment(){
        Token token = ParseExpression(ExpressionType::AfterAssignment);
    }

    void Parser::ParseAssignment(const std::string& identifier){
        Token token = ParseExpression(ExpressionType::AfterAssignment);
        m_VarsManager.GetVariable(identifier)->SetValue(&token);
    }

    void Parser::ParseVariableDeclaration(){
        goNext();
        std::string identifier;
        DataType type;

        while(token.type != TokenType::Identifier){
            if(token.type == TokenType::INT 
            || token.type == TokenType::FLOAT
            || token.type == TokenType::STRING
            || token.type == TokenType::CHAR
            || token.type == TokenType::BOOLEAN){
                type = TokenToDataType(token.type);
            }
            else{
                throw std::runtime_error("Unexpected token while declaration variable!");
            }
            goNext();
        }
        identifier = token.value;
        m_VarsManager.CreateVariable(identifier, type);
    }

}