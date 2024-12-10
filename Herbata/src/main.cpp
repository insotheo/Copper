#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Lexer/Lexer.hpp"
#include "Parser/Parser.hpp"

int main(int argc, char* argv[]){
    try{
        if(argc != 2){
            throw std::runtime_error("Invalid arguments amount!");
        }

        std::stringstream* inputstream = new std::stringstream();
        std::ifstream* fs = new std::ifstream;
        
        fs->open(argv[1]);
        if(!(fs->is_open())){
            throw std::runtime_error("Error while trying to open the file!");
        }

        char c;
        while(fs->get(c)){
            *inputstream << c;
        }
        fs->close();
        delete fs;

        std::string input = inputstream->str();
        delete inputstream;

        // std::cout << input << "\n"; -- dbg only

        Herbata::Lexer lexer(input);
        Herbata::Parser parser(lexer);
        parser.Parse();
    }
    catch(std::runtime_error& err){
        std::cerr << err.what() << "\n";
        return -1;
    }
    return 0;
}