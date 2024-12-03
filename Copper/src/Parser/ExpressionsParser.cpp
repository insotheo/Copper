#include "Parser/Parser.hpp"

namespace Copper{

    VarVal Parser::ParseExpression(const TokenType& stopToken){
        return expression(stopToken);
    }

    VarVal Parser::factor(){
        if(token.type == TokenType::Number){
            float num = std::stof(token.value);
            goNext();
            return num;
        }

        if(token.type == TokenType::Plus || token.type == TokenType::Minus){
            std::string sign = token.value;
            goNext();
            float value = std::get<float>(factor());
            return (sign == "-") ? -value : value;
        }

        if(token.type == TokenType::Identifier){
            std::string identifier = token.value;
            goNext();
            return m_VarsManager.GetVariable(identifier)->GetValue();
        }

        throw std::runtime_error("Invalid syntax!");
    }

    VarVal Parser::term(const TokenType& stopToken){
        VarVal result = factor();
        while(token.type == TokenType::Multiply || token.type == TokenType::Divide){
            if(token.type == stopToken){
                return result;
            }

            if(token.type == TokenType::Multiply){
                goNext();
                result = VarValProd(result, factor());
            }
            else{
                goNext();
                result = VarValQuot(result, factor());
            }
        }
        return result;
    }


    VarVal Parser::expression(const TokenType& stopToken){
        VarVal result = term(stopToken);
        while(token.type == TokenType::Plus || token.type == TokenType::Minus){
            if(token.type == stopToken){
                return result;
            }

            if(token.type == TokenType::Plus){
                goNext();
                result = VarValSum(result, term(stopToken));
            }
            else{
                goNext();
                result = VarValDif(result, term(stopToken));
            }
        }
        return result;
    }

}