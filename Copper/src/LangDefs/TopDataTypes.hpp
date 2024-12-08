#ifndef TOP_DATA_TYPES_HPP
#define TOP_DATA_TYPES_HPP

#include <string>
#include <variant>

namespace Copper{
    
    template <typename T>
    struct CopperNumberType{
    public:
        CopperNumberType(const T& val) : value(val){} 
        CopperNumberType() : value(){}

        inline std::variant<int, unsigned int, short int, long int, float, double> getValue() const {
            using F = std::decay_t<decltype(value)>;
            
            if constexpr(std::is_same_v<F, int>){
                return static_cast<int>(value);
            }
            else if constexpr(std::is_same_v<F, unsigned int>){
                return static_cast<unsigned int>(value);
            }
            else if constexpr(std::is_same_v<F, short int>){
                return static_cast<short int>(value);
            }
            else if constexpr(std::is_same_v<F, long int>){
                return static_cast<long int>(value);
            }
            else if constexpr(std::is_same_v<F, float>){
                return static_cast<float>(value);
            }
            else if constexpr(std::is_same_v<F, double>){
                return static_cast<double>(value);
            }
            else{
                throw std::runtime_error("NaN");
            }
        }
        
        T value;
    };

    struct CopperINT : public CopperNumberType<int>
    {
        CopperINT(const int& val) : CopperNumberType<int>(val){}
        CopperINT(const CopperINT& parent) : CopperNumberType<int>(parent.value) {}
        CopperINT(const CopperNumberType<int>& parent) : CopperNumberType<int>(parent){}
        CopperINT() : CopperNumberType<int>(){}
    };
    
    struct CopperUINT : public CopperNumberType<unsigned int>
    {
        CopperUINT(const unsigned int& val) : CopperNumberType<unsigned int>(val){}
        CopperUINT(const CopperUINT& parent) : CopperNumberType<unsigned int>(parent.value) {}
        CopperUINT(const CopperNumberType<unsigned int>& parent) : CopperNumberType<unsigned int>(parent){}
        CopperUINT() : CopperNumberType<unsigned int>(){}
    };

    struct CopperSHORT : public CopperNumberType<short int>
    {
        CopperSHORT(const short int& val) : CopperNumberType<short int>(val){}
        CopperSHORT(const CopperSHORT& parent) : CopperNumberType<short int>(parent.value) {}
        CopperSHORT(const CopperNumberType<short int>& parent) : CopperNumberType<short int>(parent){}
        CopperSHORT() : CopperNumberType<short int>(){} 
    };

    struct CopperLONG : public CopperNumberType<long int>
    {
        CopperLONG(const long int& val) : CopperNumberType<long int>(val){}
        CopperLONG(const CopperLONG& parent) : CopperNumberType<long int>(parent.value) {}
        CopperLONG(const CopperNumberType<long int>& parent) : CopperNumberType<long int>(parent){}
        CopperLONG() : CopperNumberType<long int>(){}
    };

    struct CopperFLOAT : public CopperNumberType<float>
    {
        CopperFLOAT(const float& val) : CopperNumberType<float>(val){}
        CopperFLOAT(const CopperFLOAT& parent) : CopperNumberType<float>(parent.value) {}
        CopperFLOAT(const CopperNumberType<float>& parent) : CopperNumberType<float>(parent){}
        CopperFLOAT() : CopperNumberType<float>(){}   
    };

    struct CopperDOUBLE : public CopperNumberType<double>
    {
        CopperDOUBLE(const double& val) : CopperNumberType<double>(val){}
        CopperDOUBLE(const CopperDOUBLE& parent) : CopperNumberType<double>(parent.value) {}
        CopperDOUBLE(const CopperNumberType<double>& parent) : CopperNumberType<double>(parent){}
        CopperDOUBLE() : CopperNumberType<double>(){}
    };

    struct CopperSTRING
    {
        std::string value;

        CopperSTRING(const std::string& val) : value(val)
        {}

        CopperSTRING() : value()
        {}
        
    };

    struct CopperCHAR
    {
        char value;

        CopperCHAR(const char& val) : value(val)
        {}

        CopperCHAR() : value()
        {}

    };

    struct CopperBOOLEAN
    {
        bool value;

        CopperBOOLEAN(const bool& val) : value(val)
        {}

        CopperBOOLEAN() : value()
        {}

    };

}

#endif