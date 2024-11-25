#include "Lexer/Lexer.hpp"

namespace Copper{

    Token Lexer::NextToken(){
        while(pos < text.size()){
            char cChar = text[pos]; //cChar stands for current char

            if(std::isspace(cChar)){
                pos++;
                continue;
            }

            //handling number
            if (std::isdigit(cChar) || cChar == '.' || 
                (cChar == '-' && (pos == 0 || text[pos - 1] == '(' || text[pos - 1] == '+' || text[pos - 1] == '-')) ||
                (cChar == '+' && (pos == 0 || text[pos - 1] == '('))){
                    std::string num;
                    bool hasDecimal = false;

                    if(cChar == '-' || cChar == '+'){
                        num += cChar;
                        pos++;
                        if(pos < text.size()){
                            cChar = text[pos];
                        }
                    }

                    while(pos < text.size() && (std::isdigit(text[pos]) || cChar == '.')){
                        if(text[pos] == '.'){
                            if(hasDecimal){
                               throw std::runtime_error("Invalid number format!"); 
                            }
                            hasDecimal = true;
                        }
                        num += cChar;
                        pos++;
                        if(pos < text.size()){
                            cChar = text[pos];
                        }
                    }

                    return {TokenType::Number, num};
                }

            //handling key words and identifier
            if(std::isalpha(cChar) || cChar == '_'){
                std::string identifier;
                while(pos < text.size() && (std::isalpha(text[pos]) || text[pos] == '_')){
                    identifier += text[pos];
                    pos++;
                }

                if(identifier == "func"){
                    return {TokenType::Function, "func"};
                }
                //data types
                else if(identifier == "int"){
                    return {TokenType::INT, "int"};
                }
                else if(identifier == "float"){
                    return {TokenType::FLOAT, "float"};
                }
                else if(identifier == "bool"){
                    return {TokenType::BOOLEAN, "bool"};
                }
                else if(identifier == "string"){
                    return {TokenType::STRING, "string"};
                }
                else if(identifier == "char"){
                    return {TokenType::CHAR, "char"};
                }
                //identifier
                else{
                    return {TokenType::Identifier, identifier};
                }
            }

            //handle operations and symbols
            switch (cChar)
            {
            case '+': pos++; return {TokenType::Plus, "+"};
            case '-': pos++; return {TokenType::Minus, "-"};
            case '*': pos++; return {TokenType::Multiply, "*"};
            case '/': pos++; return {TokenType::Divide, "/"};
            case '(': pos++; return {TokenType::LeftParen, "("};
            case ')': pos++; return {TokenType::RightParen, ")"};
            case '{': pos++; return {TokenType::RightBrace, "{"};
            case '}': pos++; return {TokenType::LeftBrace, "}"};
            case ';': pos++; return {TokenType::CommandEnd, ";"};
            case '"':{
                std::string textVal;
                pos++;
                while(pos < text.size() && text[pos] != '"'){
                    textVal += text[pos];
                    pos++;
                }

                if(pos < text.size() && text[pos] == '"'){
                    pos++;
                    return {TokenType::Text, textVal};
                }
                else{
                    throw std::runtime_error("Unterminated string at position: " + std::to_string(pos) + "!");
                }
            }
            case '\'':{
                pos++;
                std::string charVal;
                charVal += text[pos];
                pos++;
                if(pos < text.size() && text[pos] == '\''){
                    pos++;
                    return {TokenType::SingleCharText, charVal};
                }
                else{
                    throw std::runtime_error("Unterminated char at position: " + std::to_string(pos) + "!");
                }
            }
            }

            //if everything is false
            return {TokenType::Invalid, std::to_string(cChar)};
        }
        return {TokenType::End, ""};
    }

}