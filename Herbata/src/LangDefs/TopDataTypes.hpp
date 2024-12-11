#ifndef TOP_DATA_TYPES_HPP
#define TOP_DATA_TYPES_HPP

#include <string>
#include <variant>

namespace Herbata{
    
    template <typename T>
    struct HerbataNumberType{
    public:
        HerbataNumberType(const T& val) : value(val){} 
        HerbataNumberType() : value(){}

        inline std::variant<int, unsigned int, short int, long long, float, double> getValue() const {
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
            else if constexpr(std::is_same_v<F, long long>){
                return static_cast<long long>(value);
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

    struct HerbataINT : public HerbataNumberType<int>
    {
        HerbataINT(const int& val) : HerbataNumberType<int>(val){}
        HerbataINT(const HerbataINT& parent) : HerbataNumberType<int>(parent.value) {}
        HerbataINT(const HerbataNumberType<int>& parent) : HerbataNumberType<int>(parent){}
        HerbataINT() : HerbataNumberType<int>(){}
    };
    
    struct HerbataUINT : public HerbataNumberType<unsigned int>
    {
        HerbataUINT(const unsigned int& val) : HerbataNumberType<unsigned int>(val){}
        HerbataUINT(const HerbataUINT& parent) : HerbataNumberType<unsigned int>(parent.value) {}
        HerbataUINT(const HerbataNumberType<unsigned int>& parent) : HerbataNumberType<unsigned int>(parent){}
        HerbataUINT() : HerbataNumberType<unsigned int>(){}
    };

    struct HerbataSHORT : public HerbataNumberType<short int>
    {
        HerbataSHORT(const short int& val) : HerbataNumberType<short int>(val){}
        HerbataSHORT(const HerbataSHORT& parent) : HerbataNumberType<short int>(parent.value) {}
        HerbataSHORT(const HerbataNumberType<short int>& parent) : HerbataNumberType<short int>(parent){}
        HerbataSHORT() : HerbataNumberType<short int>(){} 
    };

    struct HerbataLONG : public HerbataNumberType<long long>
    {
        HerbataLONG(const long long& val) : HerbataNumberType<long long>(val){}
        HerbataLONG(const HerbataLONG& parent) : HerbataNumberType<long long>(parent.value) {}
        HerbataLONG(const HerbataNumberType<long long>& parent) : HerbataNumberType<long long>(parent){}
        HerbataLONG() : HerbataNumberType<long long>(){}
    };

    struct HerbataFLOAT : public HerbataNumberType<float>
    {
        HerbataFLOAT(const float& val) : HerbataNumberType<float>(val){}
        HerbataFLOAT(const HerbataFLOAT& parent) : HerbataNumberType<float>(parent.value) {}
        HerbataFLOAT(const HerbataNumberType<float>& parent) : HerbataNumberType<float>(parent){}
        HerbataFLOAT() : HerbataNumberType<float>(){}   
    };

    struct HerbataDOUBLE : public HerbataNumberType<double>
    {
        HerbataDOUBLE(const double& val) : HerbataNumberType<double>(val){}
        HerbataDOUBLE(const HerbataDOUBLE& parent) : HerbataNumberType<double>(parent.value) {}
        HerbataDOUBLE(const HerbataNumberType<double>& parent) : HerbataNumberType<double>(parent){}
        HerbataDOUBLE() : HerbataNumberType<double>(){}
    };

    struct HerbataSTRING
    {
        std::string value;

        HerbataSTRING(const std::string& val) : value(val)
        {}

        HerbataSTRING() : value()
        {}
        
    };

    struct HerbataCHAR
    {
        char value;

        HerbataCHAR(const char& val) : value(val)
        {}

        HerbataCHAR() : value()
        {}

    };

    struct HerbataBOOLEAN
    {
        bool value;

        HerbataBOOLEAN(const bool& val) : value(val)
        {}

        HerbataBOOLEAN() : value()
        {}

    };

}

#endif