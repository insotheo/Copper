#ifndef TOKEN_TYPE_HPP
#define TOKEN_TYPE_HPP

namespace Copper{

    enum class TokenType{
        Plus, Minus, Multiply, Divide, LeftParen, RightParen, Equal, //Default math's tokens
        Number, Literal, 
        Invalid, None, Semicolon,

        //Zones
        RightBrace, LeftBrace, 

        //KeyWords
        Function,
        OUTPUT,
        INT, FLOAT, STRING, CHAR, BOOLEAN
    };

}

#endif