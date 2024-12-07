#ifndef TOP_DATA_TYPES_HPP
#define TOP_DATA_TYPES_HPP

#include <string>

namespace Copper{
    
    struct CopperINT
    {
        int value;

        CopperINT(const int& val) : value(val)
        {}

        CopperINT() : value()
        {}

    };
    
    struct CopperUINT
    {
        unsigned int value;

        CopperUINT(const unsigned int& val) : value(val)
        {}

        CopperUINT() : value()
        {}
        
    };

    struct CopperSHORT
    {
        short int value;

        CopperSHORT(const short int& val) : value(val)
        {}

        CopperSHORT() : value()
        {}
        
    };

    struct CopperLONG
    {
        long int value;

        CopperLONG(const long int& val) : value(val)
        {}

        CopperLONG() : value()
        {}
        
    };

    struct CopperFLOAT
    {
        float value;

        CopperFLOAT(const float& val) : value(val)
        {}

        CopperFLOAT() : value()
        {}
        
    };

    struct CopperDOUBLE
    {
        double value;

        CopperDOUBLE(const double& val) : value(val)
        {}

        CopperDOUBLE() : value()
        {}
        
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