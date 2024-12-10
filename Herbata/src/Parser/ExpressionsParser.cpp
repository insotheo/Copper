#include "Parser/Parser.hpp"

namespace Herbata{

    VarVal Parser::ParseExpression(){
        return expression();
    }

    VarVal Parser::factor(){
        if(token.type == TokenType::Number){
            double num = std::stod(token.value);
            goNext();
            return Herbata::HerbataDOUBLE(num);
        }
        if(token.type == TokenType::Text){
            std::string text = token.value;
            goNext();
            return text;
        }
        if(token.type == TokenType::SingleCharText){
            std::string justChar = std::string(1, token.value[0]);
            goNext();
            return Herbata::HerbataINT((int)justChar[0]);
        }

        if(token.type == TokenType::Plus || token.type == TokenType::Minus){
            std::string sign = token.value;
            goNext();
            double value = std::get<Herbata::HerbataFLOAT>(factor()).value;
            return Herbata::HerbataDOUBLE((sign == "-") ? -value : value);
        }

        if(token.type == TokenType::Identifier){
            std::string identifier = token.value;
            goNext();
            return m_VarsManager.GetVariable(identifier)->GetValue();
        }

        //TODO: Functions

        if(token.type == TokenType::LeftParen){
            goNext(); //left paren
            VarVal result = expression();
            goNext(); //right paren
            return result;
        }

        throw std::runtime_error("Invalid syntax!");
    }

    VarVal Parser::term(){
        VarVal result = factor();
        while(token.type == TokenType::Multiply || token.type == TokenType::Divide){
            if(token.type == m_expressionStopToken){
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


    VarVal Parser::expression(){
        VarVal result = term();
        while(token.type == TokenType::Plus || token.type == TokenType::Minus){
            if(token.type == m_expressionStopToken){
                return result;
            }

            if(token.type == TokenType::Plus){
                goNext();
                result = VarValSum(result, term());
            }
            else{
                goNext();
                result = VarValDif(result, term());
            }
        }
        return result;
    }

}