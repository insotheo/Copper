#include "Parser/Parser.hpp"

namespace Copper{

    Token ct; //ct stands for current token
    size_t ci; //ci stands for current index
    std::vector<Token> tokens;

    Token Parser::ParseExpression(const ExpressionType& type){
        if(type == ExpressionType::AfterAssignment){
            while(token.type != TokenType::CommandEnd){
                tokens.push_back(token);
                goNext();
            }
        }

        return ExecuteExpression();
    }


    Token getNextToken(){
        if(ci < tokens.size()){
            ci++;
            return tokens[ci];
        }
        return Token{TokenType::End, ""};
    };


    Token Parser::ExecuteExpression(){
        Token result;

        if(tokens.size() == 1){
            return tokens[0];
        }
        result = expression();

        return result;
    }


    Token Parser::expression(){
        Token res = term();
        while (ct.type == TokenType::Plus || ct.type == TokenType::Minus) {
            Token op = ct; //store operator
            ct = getNextToken(); // get the next token
            Token nextTerm = term(); // calculate the next term
            if (op.type == TokenType::Plus) {
                res.value = std::to_string(std::stod(res.value) + std::stod(nextTerm.value)); // add
            } else if (op.type == TokenType::Minus) {
                res.value = std::to_string(std::stod(res.value) - std::stod(nextTerm.value)); // subtract
            }
        }
        return res;
    }

    Token Parser::factor(){
        Token res;
        if (ct.type == TokenType::Number) {
            res = ct; // if it's a number, return it
            ct = getNextToken();
        } else if (ct.type == TokenType::LeftParen) {
            ct = getNextToken(); // consume '('
            res = expression(); // evaluate the expression inside the parentheses
            if (ct.type != TokenType::RightParen) {
                return Token{TokenType::Invalid, "Error: Expected right parenthesis"};
            }
            ct = getNextToken(); // consume ')'
        } else {
            return Token{TokenType::Invalid, "Error: Invalid factor"};
        }
        return res;
    }

    Token Parser::term(){
        Token res = factor();
        while (ct.type == TokenType::Multiply || ct.type == TokenType::Divide) {
            Token op = ct; // store the operator
            ct = getNextToken(); // get the next token (either a factor or an invalid token)
            Token nextFactor = factor(); // calculate the next factor
            if (op.type == TokenType::Multiply) {
                res.value = std::to_string(std::stod(res.value) * std::stod(nextFactor.value)); // multiply
            } else if (op.type == TokenType::Divide) {
                if (std::stod(nextFactor.value) == 0) {
                    return Token{TokenType::Invalid, "Error: Division by zero"};
                }
                res.value = std::to_string(std::stod(res.value) / std::stod(nextFactor.value)); // divide
            }
        }
        return res;
    }

}