#include "Parser/Parser.hpp"

namespace Copper{

    void Parser::Parse(){
        goNext();

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
        else if(token.type == TokenType::Identifier){
            std::string identifier = token.value;
            goNext();
            if(token.type == TokenType::ValueSetter){
                ParseAssignment(identifier);
            }
        }
    }

    void Parser::ParseAssignment(const std::string& identifier){
        goNext();
        m_expressionStopToken = TokenType::CommandEnd;
        VarVal value = ParseExpression();
        m_expressionStopToken = TokenType::None;
        m_VarsManager.GetVariable(identifier)->SetValue(value);
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