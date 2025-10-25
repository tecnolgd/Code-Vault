#include <iostream>
#include <string>

//#include "main.cpp"

int main(int argc, char* argv[]){
    if(argc<2){
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "\tCodeVault - C++ Code Analyzer (Beta)" << std::endl;
        std::cout << "Error: At least two words needed\n" << std::endl;
        std::cout<<"( Note: Try using \"help\")"<<std::endl;
        return 1;
    }
    std::string command = argv[1];
    
}
