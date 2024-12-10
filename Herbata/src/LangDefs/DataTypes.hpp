#ifndef DATA_TYPES_HPP
#define DATA_TYPES_HPP

#include <iostream>
#include <string>
#include <variant>

#include "Token/TokenType.hpp"
#include "LangDefs/TopDataTypes.hpp"

typedef std::variant<Herbata::HerbataINT, Herbata::HerbataUINT, Herbata::HerbataSHORT, Herbata::HerbataLONG, Herbata::HerbataFLOAT, Herbata::HerbataDOUBLE, Herbata::HerbataSTRING, Herbata::HerbataCHAR, Herbata::HerbataBOOLEAN> VarVal; // VarVal stands for Variable's Value

#define IS_NUMBER_TYPE(TYPE) (TYPE == Herbata::DataType::INT ||\
                             TYPE == Herbata::DataType::UINT ||\
                             TYPE == Herbata::DataType::SHORT ||\
                             TYPE == Herbata::DataType::LONG ||\
                             TYPE == Herbata::DataType::FLOAT ||\
                             TYPE == Herbata::DataType::DOUBLE)

#define IS_DECIMAL_NUMBER_TYPE(TYPE) (TYPE == Herbata::DataType::FLOAT || TYPE == Herbata::DataType::DOUBLE)

#define IS_STRING_OR_CHAR_TYPE(TYPE) (TYPE == Herbata::DataType::STRING || TYPE == Herbata::DataType::CHAR)

namespace Herbata{
    
    enum DataType{
        INT, UINT, SHORT, LONG, FLOAT, DOUBLE, STRING, CHAR, BOOLEAN
    };

}

inline Herbata::DataType TokenToDataType(const Herbata::TokenType& ttype){
    switch (ttype)
    {
        case Herbata::TokenType::INT: return Herbata::DataType::INT;
        case Herbata::TokenType::UINT: return Herbata::DataType::UINT;
        case Herbata::TokenType::SHORT: return Herbata::DataType::SHORT;
        case Herbata::TokenType::LONG: return Herbata::DataType::LONG;
        case Herbata::TokenType::FLOAT: return Herbata::DataType::FLOAT;
        case Herbata::TokenType::DOUBLE: return Herbata::DataType::DOUBLE;
        case Herbata::TokenType::STRING: return Herbata::DataType::STRING;
        case Herbata::TokenType::CHAR: return Herbata::DataType::CHAR;
        case Herbata::TokenType::BOOLEAN: return Herbata::DataType::BOOLEAN;

        default: throw std::runtime_error("Unexpected data type");
    }
}

inline bool IsDataType(const Herbata::TokenType& ttype){
    if(
        ttype == Herbata::TokenType::INT ||
        ttype == Herbata::TokenType::UINT ||
        ttype == Herbata::TokenType::SHORT ||
        ttype == Herbata::TokenType::LONG ||
        ttype == Herbata::TokenType::FLOAT ||
        ttype == Herbata::TokenType::DOUBLE ||
        ttype == Herbata::TokenType::STRING ||
        ttype == Herbata::TokenType::CHAR ||
        ttype == Herbata::TokenType::BOOLEAN
    ){
        return true;
    }
    return false;
}

inline const Herbata::DataType GetVarValType(const VarVal* value){
    if(std::holds_alternative<Herbata::HerbataINT>(*value)) return Herbata::DataType::INT;
    else if(std::holds_alternative<Herbata::HerbataUINT>(*value)) return Herbata::DataType::UINT;
    else if(std::holds_alternative<Herbata::HerbataSHORT>(*value)) return Herbata::DataType::SHORT;
    else if(std::holds_alternative<Herbata::HerbataLONG>(*value)) return Herbata::DataType::LONG;
    else if(std::holds_alternative<Herbata::HerbataFLOAT>(*value)) return Herbata::DataType::FLOAT;
    else if(std::holds_alternative<Herbata::HerbataDOUBLE>(*value)) return Herbata::DataType::DOUBLE;
    else if(std::holds_alternative<Herbata::HerbataSTRING>(*value)) return Herbata::DataType::STRING;
    else if(std::holds_alternative<Herbata::HerbataCHAR>(*value)) return Herbata::DataType::CHAR;
    else if(std::holds_alternative<Herbata::HerbataBOOLEAN>(*value)) return Herbata::DataType::BOOLEAN;
    else throw std::runtime_error("Unknown data type of the value!");
}

#endif