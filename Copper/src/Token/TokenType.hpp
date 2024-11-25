#ifndef TOKEN_TYPE_HPP
#define TOKEN_TYPE_HPP

namespace Copper{

    enum class TokenType{
        Plus, Minus, Multiply, Divide, LeftParen, RightParen, Equal, FloatPoint, //Default math's tokens
        Number, Identifier, 
        Invalid, None, CommandEnd, End,
        Text, SingleCharText, 

        //Zones
        RightBrace, LeftBrace, 

        //KeyWords
        INT, FLOAT, STRING, CHAR, BOOLEAN
    };

}

#endif