#ifndef TOKEN_TYPE_HPP
#define TOKEN_TYPE_HPP

namespace Copper{

    enum class TokenType{
        Plus, Minus, Multiply, Divide, LeftParen, RightParen, Equal, FloatPoint, //Default math's tokens
        Number, Identifier, 
        Invalid, None, Semicolon, End,
        Quotes, SingleQuotes, 

        //Zones
        RightBrace, LeftBrace, 

        //KeyWords
        Function,
        INT, FLOAT, STRING, CHAR, BOOLEAN
    };

}

#endif