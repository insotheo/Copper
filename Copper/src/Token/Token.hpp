#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

#include "Token/TokenType.hpp"

namespace Copper{

    struct Token
    {
        TokenType type;
        std::string value;
    };
    

}

#endif