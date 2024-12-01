#include "Variable.hpp"

namespace Copper{

    void Variable::SetValue(const Token* token){
        if(token->type == TokenType::Number && m_Type == DataType::INT){
            m_Val = (int)std::stoi(token->value);
        }
    }

}