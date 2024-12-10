#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Token/Token.hpp"
#include "Token/TokenType.hpp"
#include "LangDefs/DataTypes.hpp"
#include "LangDefs/TopDataTypes.hpp"
#include "LangDefs/VarValOperators.hpp"

namespace Herbata {

    class Variable {
    public:
        Variable(const DataType& type) : m_Type(type) {}

        inline VarVal GetValue() { return m_Val; }
        void SetValue(const VarVal& value, const DataType& type);

        DataType GetType() const { return m_Type; }

    private:
        const DataType m_Type;
        VarVal m_Val;
    };

    struct VarStruct
    {
        std::string Identifier;
        Variable* Var;
    };

    class VariablesManager{
    public:
        void print(); //DBG ONLY
        
        void CreateVariable(const std::string& identifier, const DataType& type);
        Variable* GetVariable(const std::string& identifier) const;
    private:
        std::vector<VarStruct> m_Vars;
    };

}

#endif
