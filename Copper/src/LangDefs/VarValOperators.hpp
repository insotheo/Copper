#ifndef VAR_VAL_OPERATORS_HPP
#define VAR_VAL_OPERATORS_HPP

#include <iostream>
#include <string>

#include "LangDefs/DataTypes.hpp"

#define VARVAL_OP_ACTION(typeL, LHSt, ACTION, typeR, RHS, postfixR) \
    if (const typeR* rhs_##postfixR = std::get_if<typeR>(RHS)) { \
        if constexpr (std::is_same_v<typeL, typeR>) { \
            return *LHSt ACTION *rhs_##postfixR; \
        } else { \
            return *LHSt ACTION static_cast<typeL>(*rhs_##postfixR); \
        } \
    }\

inline const VarVal VarValSum(const VarVal& lhs, const VarVal& rhs){
    //numbers
    if(const int* lhs_int = std::get_if<int>(&lhs)){ //int
        VARVAL_OP_ACTION(int, lhs_int, +, int, &rhs, int)
        VARVAL_OP_ACTION(int, lhs_int, +, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(int, lhs_int, +, short int, &rhs, short)
        VARVAL_OP_ACTION(int, lhs_int, +, long int, &rhs, long)
        VARVAL_OP_ACTION(int, lhs_int, +, float, &rhs, float)
        VARVAL_OP_ACTION(int, lhs_int, +, double, &rhs, double)
    }

    else if(const unsigned int* lhs_uint = std::get_if<unsigned int>(&lhs)){ //uint
        VARVAL_OP_ACTION(unsigned int, lhs_uint, +, int, &rhs, int)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, +, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, +, short int, &rhs, short)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, +, long int, &rhs, long)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, +, float, &rhs, float)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, +, double, &rhs, double)
    }

    else if(const short int* lhs_short = std::get_if<short int>(&lhs)){ //short
        VARVAL_OP_ACTION(short int, lhs_short, +, int, &rhs, int)
        VARVAL_OP_ACTION(short int, lhs_short, +, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(short int, lhs_short, +, short int, &rhs, short)
        VARVAL_OP_ACTION(short int, lhs_short, +, long int, &rhs, long)
        VARVAL_OP_ACTION(short int, lhs_short, +, float, &rhs, float)
        VARVAL_OP_ACTION(short int, lhs_short, +, double, &rhs, double)
    }

    else if(const long int* lhs_long = std::get_if<long int>(&lhs)){ //long
        VARVAL_OP_ACTION(long int, lhs_long, +, int, &rhs, int)
        VARVAL_OP_ACTION(long int, lhs_long, +, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(long int, lhs_long, +, short int, &rhs, short)
        VARVAL_OP_ACTION(long int, lhs_long, +, long int, &rhs, long)
        VARVAL_OP_ACTION(long int, lhs_long, +, float, &rhs, float)
        VARVAL_OP_ACTION(long int, lhs_long, +, double, &rhs, double)
    }

    else if(const float* lhs_float = std::get_if<float>(&lhs)){ //float
        VARVAL_OP_ACTION(float, lhs_float, +, int, &rhs, int)
        VARVAL_OP_ACTION(float, lhs_float, +, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(float, lhs_float, +, short int, &rhs, short)
        VARVAL_OP_ACTION(float, lhs_float, +, long int, &rhs, long)
        VARVAL_OP_ACTION(float, lhs_float, +, float, &rhs, float)
        VARVAL_OP_ACTION(float, lhs_float, +, double, &rhs, double)
    }

    else if(const double* lhs_double = std::get_if<double>(&lhs)){ //double
        VARVAL_OP_ACTION(double, lhs_double, +, int, &rhs, int)
        VARVAL_OP_ACTION(double, lhs_double, +, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(double, lhs_double, +, short int, &rhs, short)
        VARVAL_OP_ACTION(double, lhs_double, +, long int, &rhs, long)
        VARVAL_OP_ACTION(double, lhs_double, +, float, &rhs, float)
        VARVAL_OP_ACTION(double, lhs_double, +, double, &rhs, double)
    }

    //string building
    else if(const std::string* lhs_str = std::get_if<std::string>(&lhs)){ //string
        if(const std::string* rhs_str = std::get_if<std::string>(&rhs)){ //string and string
            return *lhs_str + *rhs_str;
        }
        else if(const char* rhs_char = std::get_if<char>(&rhs)){ //string and char
            return *lhs_str + std::string(1, *rhs_char);
        }
    }

    else if(const char* lhs_char = std::get_if<char>(&lhs)){ //char
        if(const int* rhs_int = std::get_if<int>(&rhs)){ //char and int
            return (char)(*lhs_char + *rhs_int);
        }
    }
    
    throw std::runtime_error("Unsupported types for getting sum");
}

inline const VarVal VarValDif(const VarVal& lhs, const VarVal& rhs){
    //numbers
    if(const int* lhs_int = std::get_if<int>(&lhs)){ //int
        VARVAL_OP_ACTION(int, lhs_int, -, int, &rhs, int)
        VARVAL_OP_ACTION(int, lhs_int, -, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(int, lhs_int, -, short int, &rhs, short)
        VARVAL_OP_ACTION(int, lhs_int, -, long int, &rhs, long)
        VARVAL_OP_ACTION(int, lhs_int, -, float, &rhs, float)
        VARVAL_OP_ACTION(int, lhs_int, -, double, &rhs, double)
    }

    else if(const unsigned int* lhs_uint = std::get_if<unsigned int>(&lhs)){ //uint
        VARVAL_OP_ACTION(unsigned int, lhs_uint, -, int, &rhs, int)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, -, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, -, short int, &rhs, short)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, -, long int, &rhs, long)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, -, float, &rhs, float)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, -, double, &rhs, double)
    }

    else if(const short int* lhs_short = std::get_if<short int>(&lhs)){ //short
        VARVAL_OP_ACTION(short int, lhs_short, -, int, &rhs, int)
        VARVAL_OP_ACTION(short int, lhs_short, -, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(short int, lhs_short, -, short int, &rhs, short)
        VARVAL_OP_ACTION(short int, lhs_short, -, long int, &rhs, long)
        VARVAL_OP_ACTION(short int, lhs_short, -, float, &rhs, float)
        VARVAL_OP_ACTION(short int, lhs_short, -, double, &rhs, double)
    }

    else if(const long int* lhs_long = std::get_if<long int>(&lhs)){ //long
        VARVAL_OP_ACTION(long int, lhs_long, -, int, &rhs, int)
        VARVAL_OP_ACTION(long int, lhs_long, -, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(long int, lhs_long, -, short int, &rhs, short)
        VARVAL_OP_ACTION(long int, lhs_long, -, long int, &rhs, long)
        VARVAL_OP_ACTION(long int, lhs_long, -, float, &rhs, float)
        VARVAL_OP_ACTION(long int, lhs_long, -, double, &rhs, double)
    }

    else if(const float* lhs_float = std::get_if<float>(&lhs)){ //float
        VARVAL_OP_ACTION(float, lhs_float, -, int, &rhs, int)
        VARVAL_OP_ACTION(float, lhs_float, -, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(float, lhs_float, -, short int, &rhs, short)
        VARVAL_OP_ACTION(float, lhs_float, -, long int, &rhs, long)
        VARVAL_OP_ACTION(float, lhs_float, -, float, &rhs, float)
        VARVAL_OP_ACTION(float, lhs_float, -, double, &rhs, double)
    }

    else if(const double* lhs_double = std::get_if<double>(&lhs)){ //double
        VARVAL_OP_ACTION(double, lhs_double, -, int, &rhs, int)
        VARVAL_OP_ACTION(double, lhs_double, -, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(double, lhs_double, -, short int, &rhs, short)
        VARVAL_OP_ACTION(double, lhs_double, -, long int, &rhs, long)
        VARVAL_OP_ACTION(double, lhs_double, -, float, &rhs, float)
        VARVAL_OP_ACTION(double, lhs_double, -, double, &rhs, double)
    }

    throw std::runtime_error("Unsupported types for getting difference");
}

inline const VarVal VarValProd(const VarVal& lhs, const VarVal& rhs){
    //numbers
    if(const int* lhs_int = std::get_if<int>(&lhs)){ //int
        VARVAL_OP_ACTION(int, lhs_int, *, int, &rhs, int)
        VARVAL_OP_ACTION(int, lhs_int, *, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(int, lhs_int, *, short int, &rhs, short)
        VARVAL_OP_ACTION(int, lhs_int, *, long int, &rhs, long)
        VARVAL_OP_ACTION(int, lhs_int, *, float, &rhs, float)
        VARVAL_OP_ACTION(int, lhs_int, *, double, &rhs, double)
    }

    else if(const unsigned int* lhs_uint = std::get_if<unsigned int>(&lhs)){ //uint
        VARVAL_OP_ACTION(unsigned int, lhs_uint, *, int, &rhs, int)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, *, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, *, short int, &rhs, short)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, *, long int, &rhs, long)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, *, float, &rhs, float)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, *, double, &rhs, double)
    }

    else if(const short int* lhs_short = std::get_if<short int>(&lhs)){ //short
        VARVAL_OP_ACTION(short int, lhs_short, *, int, &rhs, int)
        VARVAL_OP_ACTION(short int, lhs_short, *, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(short int, lhs_short, *, short int, &rhs, short)
        VARVAL_OP_ACTION(short int, lhs_short, *, long int, &rhs, long)
        VARVAL_OP_ACTION(short int, lhs_short, *, float, &rhs, float)
        VARVAL_OP_ACTION(short int, lhs_short, *, double, &rhs, double)
    }

    else if(const long int* lhs_long = std::get_if<long int>(&lhs)){ //long
        VARVAL_OP_ACTION(long int, lhs_long, *, int, &rhs, int)
        VARVAL_OP_ACTION(long int, lhs_long, *, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(long int, lhs_long, *, short int, &rhs, short)
        VARVAL_OP_ACTION(long int, lhs_long, *, long int, &rhs, long)
        VARVAL_OP_ACTION(long int, lhs_long, *, float, &rhs, float)
        VARVAL_OP_ACTION(long int, lhs_long, *, double, &rhs, double)
    }

    else if(const float* lhs_float = std::get_if<float>(&lhs)){ //float
        VARVAL_OP_ACTION(float, lhs_float, *, int, &rhs, int)
        VARVAL_OP_ACTION(float, lhs_float, *, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(float, lhs_float, *, short int, &rhs, short)
        VARVAL_OP_ACTION(float, lhs_float, *, long int, &rhs, long)
        VARVAL_OP_ACTION(float, lhs_float, *, float, &rhs, float)
        VARVAL_OP_ACTION(float, lhs_float, *, double, &rhs, double)
    }

    else if(const double* lhs_double = std::get_if<double>(&lhs)){ //double
        VARVAL_OP_ACTION(double, lhs_double, *, int, &rhs, int)
        VARVAL_OP_ACTION(double, lhs_double, *, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(double, lhs_double, *, short int, &rhs, short)
        VARVAL_OP_ACTION(double, lhs_double, *, long int, &rhs, long)
        VARVAL_OP_ACTION(double, lhs_double, *, float, &rhs, float)
        VARVAL_OP_ACTION(double, lhs_double, *, double, &rhs, double)
    }

    throw std::runtime_error("Unsupported types for getting product of numbers");
}

inline const VarVal VarValQuot(const VarVal& lhs, const VarVal& rhs){
    //numbers
    if(const int* lhs_int = std::get_if<int>(&lhs)){ //int
        VARVAL_OP_ACTION(int, lhs_int, /, int, &rhs, int)
        VARVAL_OP_ACTION(int, lhs_int, /, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(int, lhs_int, /, short int, &rhs, short)
        VARVAL_OP_ACTION(int, lhs_int, /, long int, &rhs, long)
        VARVAL_OP_ACTION(int, lhs_int, /, float, &rhs, float)
        VARVAL_OP_ACTION(int, lhs_int, /, double, &rhs, double)
    }

    else if(const unsigned int* lhs_uint = std::get_if<unsigned int>(&lhs)){ //uint
        VARVAL_OP_ACTION(unsigned int, lhs_uint, /, int, &rhs, int)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, /, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, /, short int, &rhs, short)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, /, long int, &rhs, long)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, /, float, &rhs, float)
        VARVAL_OP_ACTION(unsigned int, lhs_uint, /, double, &rhs, double)
    }

    else if(const short int* lhs_short = std::get_if<short int>(&lhs)){ //short
        VARVAL_OP_ACTION(short int, lhs_short, /, int, &rhs, int)
        VARVAL_OP_ACTION(short int, lhs_short, /, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(short int, lhs_short, /, short int, &rhs, short)
        VARVAL_OP_ACTION(short int, lhs_short, /, long int, &rhs, long)
        VARVAL_OP_ACTION(short int, lhs_short, /, float, &rhs, float)
        VARVAL_OP_ACTION(short int, lhs_short, /, double, &rhs, double)
    }

    else if(const long int* lhs_long = std::get_if<long int>(&lhs)){ //long
        VARVAL_OP_ACTION(long int, lhs_long, /, int, &rhs, int)
        VARVAL_OP_ACTION(long int, lhs_long, /, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(long int, lhs_long, /, short int, &rhs, short)
        VARVAL_OP_ACTION(long int, lhs_long, /, long int, &rhs, long)
        VARVAL_OP_ACTION(long int, lhs_long, /, float, &rhs, float)
        VARVAL_OP_ACTION(long int, lhs_long, /, double, &rhs, double)
    }

    else if(const float* lhs_float = std::get_if<float>(&lhs)){ //float
        VARVAL_OP_ACTION(float, lhs_float, /, int, &rhs, int)
        VARVAL_OP_ACTION(float, lhs_float, /, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(float, lhs_float, /, short int, &rhs, short)
        VARVAL_OP_ACTION(float, lhs_float, /, long int, &rhs, long)
        VARVAL_OP_ACTION(float, lhs_float, /, float, &rhs, float)
        VARVAL_OP_ACTION(float, lhs_float, /, double, &rhs, double)
    }

    else if(const double* lhs_double = std::get_if<double>(&lhs)){ //double
        VARVAL_OP_ACTION(double, lhs_double, /, int, &rhs, int)
        VARVAL_OP_ACTION(double, lhs_double, /, unsigned int, &rhs, uint)
        VARVAL_OP_ACTION(double, lhs_double, /, short int, &rhs, short)
        VARVAL_OP_ACTION(double, lhs_double, /, long int, &rhs, long)
        VARVAL_OP_ACTION(double, lhs_double, /, float, &rhs, float)
        VARVAL_OP_ACTION(double, lhs_double, /, double, &rhs, double)
    }

    throw std::runtime_error("Unsupported types for getting quotient of numbers");
}

inline double VarValGetNumberAsDouble(const VarVal& value){
    if(const int* val_int = std::get_if<int>(&value)){
        return static_cast<double>(*val_int);
    }

    else if(const unsigned int* val_uint = std::get_if<unsigned int>(&value)){
        return static_cast<double>(*val_uint);
    }

    else if(const short int* val_short = std::get_if<short int>(&value)){
        return static_cast<double>(*val_short);
    }

    else if(const long int* val_long = std::get_if<long int>(&value)){
        return static_cast<double>(*val_long);
    }

    else if(const float* val_float = std::get_if<float>(&value)){
        return static_cast<double>(*val_float);
    }

    else if(const double* val_double = std::get_if<double>(&value)){
        return *val_double;
    }

    throw std::runtime_error("Unsupported types for turning into number");
}

#endif