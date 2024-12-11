#ifndef VAR_VAL_OPERATORS_HPP
#define VAR_VAL_OPERATORS_HPP

#include <iostream>
#include <string>

#include "LangDefs/DataTypes.hpp"
#include "LangDefs/TopDataTypes.hpp"

#define VARVAL_OP_ACTION(typeL, subtype, LHSt, ACTION, typeR, RHS, postfixR) \
    if (const typeR* rhs_##postfixR = std::get_if<typeR>(&RHS)) { \
        if constexpr (std::is_same_v<typeL, typeR>) { \
            return typeL(LHSt->value ACTION rhs_##postfixR->value); \
        } else { \
            return typeL(LHSt->value ACTION static_cast<subtype>(rhs_##postfixR->value)); \
        } \
    }\

inline const VarVal VarValSum(const VarVal& lhs, const VarVal& rhs){
    //numbers
    if(const Herbata::HerbataINT* lhs_int = std::get_if<Herbata::HerbataINT>(&lhs)){ //int
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, +, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, +, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, +, Herbata::HerbataSHORT,  rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, +, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, +, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, +, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataUINT* lhs_uint = std::get_if<Herbata::HerbataUINT>(&lhs)){ //uint
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, +, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, +, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, +, Herbata::HerbataSHORT,  rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, +, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, +, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, +, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataSHORT* lhs_short = std::get_if<Herbata::HerbataSHORT>(&lhs)){ //short
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, +, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, +, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, +, Herbata::HerbataSHORT,  rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, +, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, +, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, +, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataLONG* lhs_long = std::get_if<Herbata::HerbataLONG>(&lhs)){ //long
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, +, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, +, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, +, Herbata::HerbataSHORT, rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, +, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, +, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, +, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataFLOAT* lhs_float = std::get_if<Herbata::HerbataFLOAT>(&lhs)){ //float
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, +, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, +, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, +, Herbata::HerbataSHORT, rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, +, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, +, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, +, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataDOUBLE* lhs_double = std::get_if<Herbata::HerbataDOUBLE>(&lhs)){ //double
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, +, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, +, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, +, Herbata::HerbataSHORT, rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, +, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, +, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, +, Herbata::HerbataDOUBLE, rhs, double)
    }

    //string building
    else if(const Herbata::HerbataSTRING* lhs_str = std::get_if<Herbata::HerbataSTRING>(&lhs)){ //string
        if(const Herbata::HerbataSTRING* rhs_str = std::get_if<Herbata::HerbataSTRING>(&rhs)){ //string and string
            return Herbata::HerbataSTRING(lhs_str->value + rhs_str->value);
        }
        else if(const Herbata::HerbataCHAR* rhs_char = std::get_if<Herbata::HerbataCHAR>(&rhs)){ //string and char
            return Herbata::HerbataSTRING(lhs_str->value + std::string(1, rhs_char->value));
        }
    }

    else if(const Herbata::HerbataCHAR* lhs_char = std::get_if<Herbata::HerbataCHAR>(&lhs)){ //char
        if(const Herbata::HerbataINT* rhs_int = std::get_if<Herbata::HerbataINT>(&rhs)){ //char and int
            return Herbata::HerbataCHAR(lhs_char->value + rhs_int->value);
        }
    }
    
    throw std::runtime_error("Unsupported types for getting sum");
}

inline const VarVal VarValDif(const VarVal& lhs, const VarVal& rhs){
    //numbers
    if(const Herbata::HerbataINT* lhs_int = std::get_if<Herbata::HerbataINT>(&lhs)){ //int
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, -, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, -, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, -, Herbata::HerbataSHORT,  rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, -, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, -, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, -, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataUINT* lhs_uint = std::get_if<Herbata::HerbataUINT>(&lhs)){ //uint
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, -, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, -, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, -, Herbata::HerbataSHORT,  rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, -, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, -, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, -, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataSHORT* lhs_short = std::get_if<Herbata::HerbataSHORT>(&lhs)){ //short
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, -, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, -, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, -, Herbata::HerbataSHORT,  rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, -, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, -, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, -, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataLONG* lhs_long = std::get_if<Herbata::HerbataLONG>(&lhs)){ //long
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, -, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, -, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, -, Herbata::HerbataSHORT, rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, -, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, -, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, -, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataFLOAT* lhs_float = std::get_if<Herbata::HerbataFLOAT>(&lhs)){ //float
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, -, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, -, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, -, Herbata::HerbataSHORT, rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, -, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, -, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, -, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataDOUBLE* lhs_double = std::get_if<Herbata::HerbataDOUBLE>(&lhs)){ //double
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, -, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, -, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, -, Herbata::HerbataSHORT, rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, -, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, -, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, -, Herbata::HerbataDOUBLE, rhs, double)
    }

    throw std::runtime_error("Unsupported types for getting difference");
}

inline const VarVal VarValProd(const VarVal& lhs, const VarVal& rhs){
    //numbers
    if(const Herbata::HerbataINT* lhs_int = std::get_if<Herbata::HerbataINT>(&lhs)){ //int
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, *, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, *, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, *, Herbata::HerbataSHORT,  rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, *, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, *, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, *, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataUINT* lhs_uint = std::get_if<Herbata::HerbataUINT>(&lhs)){ //uint
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, *, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, *, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, *, Herbata::HerbataSHORT,  rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, *, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, *, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, *, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataSHORT* lhs_short = std::get_if<Herbata::HerbataSHORT>(&lhs)){ //short
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, *, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, *, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, *, Herbata::HerbataSHORT,  rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, *, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, *, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, *, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataLONG* lhs_long = std::get_if<Herbata::HerbataLONG>(&lhs)){ //long
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, *, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, *, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, *, Herbata::HerbataSHORT, rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, *, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, *, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, *, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataFLOAT* lhs_float = std::get_if<Herbata::HerbataFLOAT>(&lhs)){ //float
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, *, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, *, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, *, Herbata::HerbataSHORT, rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, *, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, *, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, *, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataDOUBLE* lhs_double = std::get_if<Herbata::HerbataDOUBLE>(&lhs)){ //double
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, *, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, *, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, *, Herbata::HerbataSHORT, rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, *, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, *, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, *, Herbata::HerbataDOUBLE, rhs, double)
    }

    throw std::runtime_error("Unsupported types for getting product of numbers");
}

inline const VarVal VarValQuot(const VarVal& lhs, const VarVal& rhs){
    //numbers
   if(const Herbata::HerbataINT* lhs_int = std::get_if<Herbata::HerbataINT>(&lhs)){ //int
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, /, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, /, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, /, Herbata::HerbataSHORT,  rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, /, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, /, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataINT, int, lhs_int, /, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataUINT* lhs_uint = std::get_if<Herbata::HerbataUINT>(&lhs)){ //uint
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, /, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, /, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, /, Herbata::HerbataSHORT,  rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, /, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, /, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataUINT, unsigned int, lhs_uint, /, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataSHORT* lhs_short = std::get_if<Herbata::HerbataSHORT>(&lhs)){ //short
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, /, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, /, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, /, Herbata::HerbataSHORT,  rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, /, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, /, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataSHORT, short int, lhs_short, /, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataLONG* lhs_long = std::get_if<Herbata::HerbataLONG>(&lhs)){ //long
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, /, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, /, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, /, Herbata::HerbataSHORT, rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, /, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, /, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataLONG, long int, lhs_long, /, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataFLOAT* lhs_float = std::get_if<Herbata::HerbataFLOAT>(&lhs)){ //float
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, /, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, /, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, /, Herbata::HerbataSHORT, rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, /, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, /, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataFLOAT, float, lhs_float, /, Herbata::HerbataDOUBLE, rhs, double)
    }

    else if(const Herbata::HerbataDOUBLE* lhs_double = std::get_if<Herbata::HerbataDOUBLE>(&lhs)){ //double
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, /, Herbata::HerbataINT, rhs, int)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, /, Herbata::HerbataUINT, rhs, uint)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, /, Herbata::HerbataSHORT, rhs, short)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, /, Herbata::HerbataLONG, rhs, long)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, /, Herbata::HerbataFLOAT, rhs, float)
        VARVAL_OP_ACTION(Herbata::HerbataDOUBLE, double, lhs_double, /, Herbata::HerbataDOUBLE, rhs, double)
    }

    throw std::runtime_error("Unsupported types for getting quotient of numbers");
}

inline const VarVal VarValMakeNegative(const VarVal& value){
    return VarValProd(value, Herbata::HerbataINT(-1));
}

inline const VarVal ConvertVarValToCorrectType(const Herbata::DataType& gType, const VarVal& value, const Herbata::DataType& tType) { //gType stands for given type and tType stands for target type
    VarVal result;
    
    if(!((IS_NUMBER_TYPE(gType) && IS_NUMBER_TYPE(tType)) || //number to number
        (IS_STRING_OR_CHAR_TYPE(gType) && IS_STRING_OR_CHAR_TYPE(tType)) || //string or char to string or char
        (gType == Herbata::DataType::CHAR && (IS_NUMBER_TYPE(tType) && !IS_DECIMAL_NUMBER_TYPE(tType))) || //char to number
        ((IS_NUMBER_TYPE(gType) && !IS_DECIMAL_NUMBER_TYPE(gType)) && tType == Herbata::DataType::CHAR) || // number to char
        (IS_NUMBER_TYPE(gType) && tType == Herbata::DataType::BOOLEAN) // number to boolean
    )){
        throw std::runtime_error("Implicit conversion cannot be performed");
    }

    if(IS_NUMBER_TYPE(gType) && IS_NUMBER_TYPE(tType)){ //number to number
        result = std::visit([&tType](const auto& arg) -> const VarVal{
            using T = std::decay_t<decltype(arg.value)>;
            Herbata::HerbataNumberType<T> number(arg.value);
            
            return std::visit([&tType](const auto& v) -> const VarVal{
                switch(tType){
                    case Herbata::DataType::INT:     return Herbata::HerbataINT(static_cast<int>(v));
                    case Herbata::DataType::UINT:    return Herbata::HerbataUINT(static_cast<unsigned int>(v));
                    case Herbata::DataType::SHORT:   return Herbata::HerbataSHORT(static_cast<short int>(v));
                    case Herbata::DataType::LONG:    return Herbata::HerbataLONG(static_cast<long int>(v));
                    case Herbata::DataType::FLOAT:   return Herbata::HerbataFLOAT(static_cast<float>(v));
                    case Herbata::DataType::DOUBLE:  return Herbata::HerbataDOUBLE(static_cast<double>(v));

                    default: throw std::runtime_error("Implicit conversion cannot be performed");
                }
            }, number.getValue());
        }, value);
    }

    else if(IS_STRING_OR_CHAR_TYPE(gType) && IS_STRING_OR_CHAR_TYPE(tType)){ //string or char to string or char

    }

    else if(gType == Herbata::DataType::CHAR && (IS_NUMBER_TYPE(tType) && !IS_DECIMAL_NUMBER_TYPE(tType))){ // char to number

    }

    else if((IS_NUMBER_TYPE(gType) && !IS_DECIMAL_NUMBER_TYPE(gType)) && tType == Herbata::DataType::CHAR){ // number to char

    }

    else if(IS_NUMBER_TYPE(gType) && tType == Herbata::DataType::BOOLEAN){ //number to boolean

    }

    return result;
}

#endif