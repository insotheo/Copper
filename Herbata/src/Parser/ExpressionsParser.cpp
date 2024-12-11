#include "Parser/Parser.hpp"

namespace Herbata{

    VarVal Parser::ParseExpression(){
        return expression();
    }

    VarVal Parser::factor() {
        if (token.type == TokenType::Number) {
            const long long num = std::strtoll(token.value.c_str(), NULL, 10);
            if (num >= SHRT_MIN && num <= SHRT_MAX) {
                goNext();
                return Herbata::HerbataSHORT(static_cast<short>(num));
            } else if (num >= INT_MIN && num <= INT_MAX) {
                goNext();
                return Herbata::HerbataINT(static_cast<int>(num));
            } else {
                goNext();
                return Herbata::HerbataLONG(static_cast<long long>(num));
            }
            
            const long long* num_p = &num;
            delete num_p;
        }
        else if (token.type == TokenType::DecimalNumber) {
            const double num = std::strtod(token.value.c_str(), NULL);
            goNext();
            return Herbata::HerbataDOUBLE(num);
        }
        
        if (token.type == TokenType::Text) {
            const std::string text = token.value;
            goNext();
            return text;
        }

        if (token.type == TokenType::SingleCharText) {
            const std::string justChar = std::string(1, token.value[0]);
            goNext();
            return Herbata::HerbataINT(static_cast<int>(justChar[0]));
        }

        if (token.type == TokenType::Plus || token.type == TokenType::Minus) {
            const char sign = token.value[0];
            goNext();
            const VarVal value = factor();
            return (sign == '-') ? VarValMakeNegative(value) : value;
        }

        if (token.type == TokenType::Identifier) {
            const std::string identifier = token.value;
            goNext();
            return m_VarsManager.GetVariable(identifier)->GetValue();
        }

        if (token.type == TokenType::LeftParen) {
            goNext(); // left paren
            VarVal result = expression();
            goNext(); // right paren
            return result;
        }
        
        throw std::runtime_error("Invalid syntax!");
    }

    VarVal Parser::term(){
        VarVal result = factor();
        while(token.type == TokenType::Multiply || token.type == TokenType::Divide || token.type == TokenType::Modulo){
            if(token.type == m_expressionStopToken){
                return result;
            }

            if(token.type == TokenType::Multiply){
                goNext();
                result = VarValProd(result, factor());
            }
            else if(token.type == TokenType::Divide){
                goNext();
                result = VarValQuot(result, factor());
            }
            else{ //Modulo
                goNext();
                result = VarValMod(result, factor());
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