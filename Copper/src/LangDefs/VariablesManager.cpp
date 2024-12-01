#include "LangDefs/Variable.hpp"

namespace Copper{

    void VariablesManager::CreateVariable(const std::string& identifier, const DataType& type){
        Variable var(type);
        m_Vars[identifier] = &var;
    }

    void VariablesManager::print(){
        for(const auto& var : m_Vars){
            std::cout << var.first << "\n";
        }
    }

}