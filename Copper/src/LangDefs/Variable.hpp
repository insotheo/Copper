#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <string>

#include "LangDefs/DataTypes.hpp"

namespace Copper{

    template <typename T>
    class Variable
    {
    public:
        inline Variable(const DataType& type, const T& value) 
                : m_Val(value), m_Type(type)
        {}
        inline T GetValue() {return m_Val;}
        inline DataType GetType() {return m_Type;}

    private:
        T m_Val;
        DataType m_Type;
    };  

}

#endif