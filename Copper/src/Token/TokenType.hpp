#ifndef TOKEN_TYPE_HPP
#define TOKEN_TYPE_HPP

namespace Copper{

    enum class TokenType{
        Plus, Minus, Multiply, Divide, LeftParen, RightParen, FloatPoint, //Default math's tokens
        Number, Identifier, 
        Invalid, None, CommandEnd, End, ValueSetter,
        Text, SingleCharText, 

        //Zones
        RightBrace, LeftBrace, 

        //KeyWords
        INT, FLOAT, STRING, CHAR, BOOLEAN,

        //Logic
        TRUE, FALSE,
    };

}

#endif