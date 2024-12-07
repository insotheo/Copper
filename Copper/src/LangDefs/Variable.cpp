#include "Variable.hpp"

namespace Copper{

    void Variable::SetValue(const VarVal& value, const DataType& type){
        if(m_Type == type){
            m_Val = value;
            return;
        }
        else{
            VarVal val = ConvertVarValToCorrectType(type, value, m_Type);
            m_Val = val;
            return;
        }
    }

}