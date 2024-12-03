#ifndef DATA_TYPES_HPP
#define DATA_TYPES_HPP

#include <iostream>
#include <string>
#include <variant>

#include "Token/TokenType.hpp"

typedef std::variant<int, float, std::string, char, bool> VarVal; // VarVal stands for Variable's Value

namespace Copper{
    
    enum DataType{
        INT, FLOAT, STRING, CHAR, BOOLEAN
    };

}

inline Copper::DataType TokenToDataType(const Copper::TokenType& ttype){
    switch (ttype)
    {
        case Copper::TokenType::INT: return Copper::DataType::INT;
        case Copper::TokenType::FLOAT: return Copper::DataType::FLOAT;
        case Copper::TokenType::STRING: return Copper::DataType::STRING;
        case Copper::TokenType::CHAR: return Copper::DataType::CHAR;
        case Copper::TokenType::BOOLEAN: return Copper::DataType::BOOLEAN;

        default: throw std::runtime_error("Unexpected data type");
    }
}

#endif