#include "LangDefs/Variable.hpp"

namespace Copper{

    void VariablesManager::CreateVariable(const std::string& identifier, const DataType& type){
        m_Vars.emplace_back(VarStruct{identifier, new Variable(type)});
    }

    Variable* VariablesManager::GetVariable(const std::string& identifier) const
    {
        for (int i = 0; i < m_Vars.size(); ++i) {
            if (m_Vars[i].Identifier == identifier) {
                return m_Vars[i].Var;
            }
        }
        return nullptr;
    }

    void VariablesManager::print(){
        for (const auto var : m_Vars) {
            std::cout << (int)(var.Var->GetType()) << " " << var.Identifier;
            std::visit([](const auto& v) {
                std::cout << " = " << v.value;
                }, var.Var->GetValue());
            std::cout << "\n";
        }
    }

}