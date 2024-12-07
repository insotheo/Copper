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
    if(const Copper::CopperINT* lhs_int = std::get_if<Copper::CopperINT>(&lhs)){ //int
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, +, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, +, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, +, Copper::CopperSHORT,  rhs, short)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, +, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, +, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, +, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperUINT* lhs_uint = std::get_if<Copper::CopperUINT>(&lhs)){ //uint
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, +, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, +, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, +, Copper::CopperSHORT,  rhs, short)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, +, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, +, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, +, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperSHORT* lhs_short = std::get_if<Copper::CopperSHORT>(&lhs)){ //short
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, +, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, +, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, +, Copper::CopperSHORT,  rhs, short)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, +, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, +, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, +, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperLONG* lhs_long = std::get_if<Copper::CopperLONG>(&lhs)){ //long
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, +, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, +, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, +, Copper::CopperSHORT, rhs, short)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, +, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, +, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, +, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperFLOAT* lhs_float = std::get_if<Copper::CopperFLOAT>(&lhs)){ //float
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, +, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, +, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, +, Copper::CopperSHORT, rhs, short)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, +, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, +, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, +, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperDOUBLE* lhs_double = std::get_if<Copper::CopperDOUBLE>(&lhs)){ //double
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, +, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, +, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, +, Copper::CopperSHORT, rhs, short)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, +, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, +, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, +, Copper::CopperDOUBLE, rhs, double)
    }

    //string building
    else if(const Copper::CopperSTRING* lhs_str = std::get_if<Copper::CopperSTRING>(&lhs)){ //string
        if(const Copper::CopperSTRING* rhs_str = std::get_if<Copper::CopperSTRING>(&rhs)){ //string and string
            return Copper::CopperSTRING(lhs_str->value + rhs_str->value);
        }
        else if(const Copper::CopperCHAR* rhs_char = std::get_if<Copper::CopperCHAR>(&rhs)){ //string and char
            return Copper::CopperSTRING(lhs_str->value + std::string(1, rhs_char->value));
        }
    }

    else if(const Copper::CopperCHAR* lhs_char = std::get_if<Copper::CopperCHAR>(&lhs)){ //char
        if(const Copper::CopperINT* rhs_int = std::get_if<Copper::CopperINT>(&rhs)){ //char and int
            return Copper::CopperCHAR(lhs_char->value + rhs_int->value);
        }
    }
    
    throw std::runtime_error("Unsupported types for getting sum");
}

inline const VarVal VarValDif(const VarVal& lhs, const VarVal& rhs){
    //numbers
    if(const Copper::CopperINT* lhs_int = std::get_if<Copper::CopperINT>(&lhs)){ //int
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, -, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, -, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, -, Copper::CopperSHORT,  rhs, short)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, -, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, -, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, -, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperUINT* lhs_uint = std::get_if<Copper::CopperUINT>(&lhs)){ //uint
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, -, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, -, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, -, Copper::CopperSHORT,  rhs, short)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, -, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, -, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, -, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperSHORT* lhs_short = std::get_if<Copper::CopperSHORT>(&lhs)){ //short
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, -, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, -, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, -, Copper::CopperSHORT,  rhs, short)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, -, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, -, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, -, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperLONG* lhs_long = std::get_if<Copper::CopperLONG>(&lhs)){ //long
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, -, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, -, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, -, Copper::CopperSHORT, rhs, short)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, -, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, -, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, -, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperFLOAT* lhs_float = std::get_if<Copper::CopperFLOAT>(&lhs)){ //float
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, -, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, -, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, -, Copper::CopperSHORT, rhs, short)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, -, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, -, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, -, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperDOUBLE* lhs_double = std::get_if<Copper::CopperDOUBLE>(&lhs)){ //double
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, -, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, -, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, -, Copper::CopperSHORT, rhs, short)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, -, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, -, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, -, Copper::CopperDOUBLE, rhs, double)
    }

    throw std::runtime_error("Unsupported types for getting difference");
}

inline const VarVal VarValProd(const VarVal& lhs, const VarVal& rhs){
    //numbers
    if(const Copper::CopperINT* lhs_int = std::get_if<Copper::CopperINT>(&lhs)){ //int
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, *, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, *, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, *, Copper::CopperSHORT,  rhs, short)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, *, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, *, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, *, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperUINT* lhs_uint = std::get_if<Copper::CopperUINT>(&lhs)){ //uint
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, *, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, *, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, *, Copper::CopperSHORT,  rhs, short)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, *, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, *, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, *, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperSHORT* lhs_short = std::get_if<Copper::CopperSHORT>(&lhs)){ //short
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, *, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, *, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, *, Copper::CopperSHORT,  rhs, short)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, *, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, *, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, *, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperLONG* lhs_long = std::get_if<Copper::CopperLONG>(&lhs)){ //long
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, *, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, *, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, *, Copper::CopperSHORT, rhs, short)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, *, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, *, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, *, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperFLOAT* lhs_float = std::get_if<Copper::CopperFLOAT>(&lhs)){ //float
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, *, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, *, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, *, Copper::CopperSHORT, rhs, short)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, *, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, *, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, *, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperDOUBLE* lhs_double = std::get_if<Copper::CopperDOUBLE>(&lhs)){ //double
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, *, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, *, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, *, Copper::CopperSHORT, rhs, short)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, *, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, *, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, *, Copper::CopperDOUBLE, rhs, double)
    }

    throw std::runtime_error("Unsupported types for getting product of numbers");
}

inline const VarVal VarValQuot(const VarVal& lhs, const VarVal& rhs){
    //numbers
   if(const Copper::CopperINT* lhs_int = std::get_if<Copper::CopperINT>(&lhs)){ //int
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, /, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, /, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, /, Copper::CopperSHORT,  rhs, short)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, /, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, /, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperINT, int, lhs_int, /, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperUINT* lhs_uint = std::get_if<Copper::CopperUINT>(&lhs)){ //uint
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, /, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, /, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, /, Copper::CopperSHORT,  rhs, short)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, /, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, /, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperUINT, unsigned int, lhs_uint, /, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperSHORT* lhs_short = std::get_if<Copper::CopperSHORT>(&lhs)){ //short
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, /, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, /, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, /, Copper::CopperSHORT,  rhs, short)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, /, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, /, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperSHORT, short int, lhs_short, /, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperLONG* lhs_long = std::get_if<Copper::CopperLONG>(&lhs)){ //long
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, /, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, /, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, /, Copper::CopperSHORT, rhs, short)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, /, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, /, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperLONG, long int, lhs_long, /, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperFLOAT* lhs_float = std::get_if<Copper::CopperFLOAT>(&lhs)){ //float
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, /, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, /, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, /, Copper::CopperSHORT, rhs, short)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, /, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, /, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperFLOAT, float, lhs_float, /, Copper::CopperDOUBLE, rhs, double)
    }

    else if(const Copper::CopperDOUBLE* lhs_double = std::get_if<Copper::CopperDOUBLE>(&lhs)){ //double
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, /, Copper::CopperINT, rhs, int)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, /, Copper::CopperUINT, rhs, uint)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, /, Copper::CopperSHORT, rhs, short)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, /, Copper::CopperLONG, rhs, long)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, /, Copper::CopperFLOAT, rhs, float)
        VARVAL_OP_ACTION(Copper::CopperDOUBLE, double, lhs_double, /, Copper::CopperDOUBLE, rhs, double)
    }

    throw std::runtime_error("Unsupported types for getting quotient of numbers");
}

inline const VarVal ConvertVarValToCorrectType(const Copper::DataType& gType, const VarVal& value, const Copper::DataType& tType) { //gType stands for given type and tType stands for target type
    VarVal result;
    
    if(!((IS_NUMBER_TYPE(gType) && IS_NUMBER_TYPE(tType)) || //number to number
        (IS_STRING_OR_CHAR_TYPE(gType) && IS_STRING_OR_CHAR_TYPE(tType)) || //string or char to string or char
        (gType == Copper::DataType::CHAR && (IS_NUMBER_TYPE(tType) && !IS_DECIMAL_NUMBER_TYPE(tType))) || //char to number
        ((IS_NUMBER_TYPE(gType) && !IS_DECIMAL_NUMBER_TYPE(gType)) && tType == Copper::DataType::CHAR) || // number to char
        (IS_NUMBER_TYPE(gType) && tType == Copper::DataType::BOOLEAN) // number to boolean
    )){
        throw std::runtime_error("Implicit conversion cannot be performed");
    }

    if(IS_NUMBER_TYPE(gType) && IS_NUMBER_TYPE(tType)){ //number to number
        
    }

    else if(IS_STRING_OR_CHAR_TYPE(gType) && IS_STRING_OR_CHAR_TYPE(tType)){ //string or char to string or char

    }

    else if(gType == Copper::DataType::CHAR && (IS_NUMBER_TYPE(tType) && !IS_DECIMAL_NUMBER_TYPE(tType))){ // char to number

    }

    else if((IS_NUMBER_TYPE(gType) && !IS_DECIMAL_NUMBER_TYPE(gType)) && tType == Copper::DataType::CHAR){ // number to char

    }

    else if(IS_NUMBER_TYPE(gType) && tType == Copper::DataType::BOOLEAN){ //number to boolean

    }

    return result;
}

#endif