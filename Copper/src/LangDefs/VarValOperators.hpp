#ifndef VAR_VAL_OPERATORS_HPP
#define VAR_VAL_OPERATORS_HPP

#include <iostream>
#include <string>

#include "LangDefs/DataTypes.hpp"

inline const VarVal VarValSum(const VarVal& lhs, const VarVal& rhs){
    //numbers
    if(const int* lhs_int = std::get_if<int>(&lhs)){ //int
        if(const int* rhs_int = std::get_if<int>(&rhs)){ //int and int
            return *lhs_int + *rhs_int;
        }
        else if(const float* rhs_float = std::get_if<float>(&rhs)){ //int and float
            return static_cast<float>(*lhs_int) + *rhs_float;
        }
    }

    else if(const float* lhs_float = std::get_if<float>(&lhs)){ //float
        if(const int* rhs_int = std::get_if<int>(&rhs)){ //float and int
            return *lhs_float + static_cast<float>(*rhs_int);
        }
        else if(const float* rhs_float = std::get_if<float>(&rhs)){ //float and float
            return *lhs_float + *rhs_float;
        }
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
            return (char)(static_cast<int>(*lhs_char) + *rhs_int);
        }
    }
    throw std::runtime_error("Unsupported types for getting sum");
}

inline const VarVal VarValDif(const VarVal& lhs, const VarVal& rhs){
    //numbers
    if(const int* lhs_int = std::get_if<int>(&lhs)){ //int
        if(const int* rhs_int = std::get_if<int>(&rhs)){ //int and int
            return *lhs_int - *rhs_int;
        }
        else if(const float* rhs_float = std::get_if<float>(&rhs)){ //int and float
            return static_cast<float>(*lhs_int) - *rhs_float;
        }
    }

    else if(const float* lhs_float = std::get_if<float>(&lhs)){ //float
        if(const int* rhs_int = std::get_if<int>(&rhs)){ //float and int
            return *lhs_float - static_cast<float>(*rhs_int);
        }
        else if(const float* rhs_float = std::get_if<float>(&rhs)){ //float and float
            return *lhs_float - *rhs_float;
        }
    }
    throw std::runtime_error("Unsupported types for getting difference");
}

inline const VarVal VarValProd(const VarVal& lhs, const VarVal& rhs){
    //numbers
    if(const int* lhs_int = std::get_if<int>(&lhs)){ //int
        if(const int* rhs_int = std::get_if<int>(&rhs)){ //int and int
            return *lhs_int * *rhs_int;
        }
        else if(const float* rhs_float = std::get_if<float>(&rhs)){ //int and float
            return static_cast<float>(*lhs_int) * *rhs_float;
        }
    }

    else if(const float* lhs_float = std::get_if<float>(&lhs)){ //float
        if(const int* rhs_int = std::get_if<int>(&rhs)){ //float and int
            return *lhs_float * static_cast<float>(*rhs_int);
        }
        else if(const float* rhs_float = std::get_if<float>(&rhs)){ //float and float
            return *lhs_float * *rhs_float;
        }
    }

    throw std::runtime_error("Unsupported types for getting product of numbers");
}

inline const VarVal VarValQuot(const VarVal& lhs, const VarVal& rhs){
    //numbers
    if(const int* lhs_int = std::get_if<int>(&lhs)){ //int
        if(const int* rhs_int = std::get_if<int>(&rhs)){ //int and int
            if(*rhs_int == 0){
                throw std::runtime_error("Zero division exception!");
            }
            return *lhs_int / *rhs_int;
        }
        else if(const float* rhs_float = std::get_if<float>(&rhs)){ //int and float
            if(*rhs_float == 0.f){
                throw std::runtime_error("Zero division exception!");
            }
            return static_cast<float>(*lhs_int) / *rhs_float;
        }
    }

    else if(const float* lhs_float = std::get_if<float>(&lhs)){ //float
        if(const int* rhs_int = std::get_if<int>(&rhs)){ //float and int
            if(*rhs_int == 0){
                throw std::runtime_error("Zero division exception!");
            }
            return *lhs_float / static_cast<float>(*rhs_int);
        }
        else if(const float* rhs_float = std::get_if<float>(&rhs)){ //float and float
            if(*rhs_float == 0.f){
                throw std::runtime_error("Zero division exception!");
            }
            return *lhs_float / *rhs_float;
        }
    }

    throw std::runtime_error("Unsupported types for getting quotient of numbers");
}

inline float VarValGetNumberAsFloat(const VarVal& value){
    if(const int* val_int = std::get_if<int>(&value)){
        return static_cast<float>(*val_int);
    }
    else if(const float* val_float = std::get_if<float>(&value)){
        return *val_float;
    }

    throw std::runtime_error("Unsupported types for turning into number");
}

#endif