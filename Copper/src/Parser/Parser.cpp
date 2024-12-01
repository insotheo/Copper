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

    void Parser::ParseAssignment(){
        Token token = ParseExpression(ExpressionType::AfterAssignment);
    }

    void Parser::ParseAssignment(const std::string& identifier){
        Token token = ParseExpression(ExpressionType::AfterAssignment);
        m_VarsManager.GetVariable(identifier)->SetValue(&token);
    }

    void Parser::ParseDeclaration(){
        TokenType dataType = token.type; //getting data type
        goNext();

        if(token.type != TokenType::Identifier){
            throw std::runtime_error("Identifier expected insted of \"" + token.value + "\"!");
        }
        std::string identifier = token.value;

        goNext();
        if(token.type == TokenType::CommandEnd || token.type == TokenType::ValueSetter){
            ParseVariableDeclaration(identifier, TokenToDataType(dataType), token.type == TokenType::ValueSetter);
        }
        else if(token.type == TokenType::RightParen){
            //func decl
        }
    }

    void Parser::ParseVariableDeclaration(const std::string& ident, const DataType& type, bool withInit){
        m_VarsManager.CreateVariable(ident, type);
        if(withInit){
            goNext();
            ParseAssignment(ident);
        }
    }

}