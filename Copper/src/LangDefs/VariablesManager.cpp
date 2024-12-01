#include "LangDefs/Variable.hpp"

namespace Copper{

    void VariablesManager::CreateVariable(const std::string& identifier, const DataType& type){
        m_Vars[identifier] = new Variable(type);
    }

    void VariablesManager::print(){
        for(const auto var : m_Vars){
            std::cout << (int)(var.second->GetType()) << " " << var.first;
            if(&(var.second->GetValue()) != nullptr){
                std::visit([](const auto& v){
                    std::cout << " = " << v;
                }, var.second->GetValue());
            }
            std::cout << "\n";
        }
    }

}