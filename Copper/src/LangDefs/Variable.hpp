#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <iostream>
#include <string>
#include <memory>
#include <map>

#include "Token/Token.hpp"
#include "Token/TokenType.hpp"
#include "LangDefs/DataTypes.hpp"

namespace Copper {

    class Variable {
    public:
        Variable(const DataType& type) : m_Type(type) {}

        inline VarVal GetValue() { return m_Val; }
        void SetValue(const Token* token);

        DataType GetType() const { return m_Type; }

    private:
        const DataType m_Type;
        VarVal m_Val;
    };

    class VariablesManager{
    public:
        void print(); //DBG ONLY
        
        void CreateVariable(const std::string& identifier, const DataType& type);
        inline Variable* GetVariable(const std::string& identifier) const { return m_Vars.at(identifier); }
    private:
        std::map<const std::string, Variable*> m_Vars;
    };

}

#endif
