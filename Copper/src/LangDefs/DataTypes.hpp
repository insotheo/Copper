#ifndef DATA_TYPES_HPP
#define DATA_TYPES_HPP

#include <iostream>
#include <string>
#include <variant>

#include "Token/TokenType.hpp"

typedef std::variant<int, unsigned int, short int, long int, float, double, std::string, char, bool> VarVal; // VarVal stands for Variable's Value

namespace Copper{
    
    enum DataType{
        INT, UINT, SHORT, LONG, FLOAT, DOUBLE, STRING, CHAR, BOOLEAN
    };
}

inline Copper::DataType TokenToDataType(const Copper::TokenType& ttype){
    switch (ttype)
    {
        case Copper::TokenType::INT: return Copper::DataType::INT;
        case Copper::TokenType::UINT: return Copper::DataType::UINT;
        case Copper::TokenType::SHORT: return Copper::DataType::SHORT;
        case Copper::TokenType::LONG: return Copper::DataType::LONG;
        case Copper::TokenType::FLOAT: return Copper::DataType::FLOAT;
        case Copper::TokenType::DOUBLE: return Copper::DataType::DOUBLE;
        case Copper::TokenType::STRING: return Copper::DataType::STRING;
        case Copper::TokenType::CHAR: return Copper::DataType::CHAR;
        case Copper::TokenType::BOOLEAN: return Copper::DataType::BOOLEAN;

        default: throw std::runtime_error("Unexpected data type");
    }
}

inline bool IsDataType(const Copper::TokenType& ttype){
    if(
        ttype == Copper::TokenType::INT ||
        ttype == Copper::TokenType::UINT ||
        ttype == Copper::TokenType::SHORT ||
        ttype == Copper::TokenType::LONG ||
        ttype == Copper::TokenType::FLOAT ||
        ttype == Copper::TokenType::DOUBLE ||
        ttype == Copper::TokenType::STRING ||
        ttype == Copper::TokenType::CHAR ||
        ttype == Copper::TokenType::BOOLEAN
    ){
        return true;
    }
    return false;
}

#endif