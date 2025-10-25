#include <iostream>
#include <string>

//#include "main.cpp"

int main(int argc, char* argv[]){ //to get the number of words used in the command to interpret the command given by the user.
    if(argc<2){ //error check
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "\tCodeVault - C++ Code Analyzer (Beta)" << std::endl;
        std::cout << "Error: At least two words needed\n" << std::endl;
        std::cout<<"( Note: Try using \"help\")"<<std::endl;
        return 1;
    }
    std::string command = argv[1]; //first word is the command
    analyzer a; //object of class analyser

    if(command=="populate"){
        if (argc != 3) {
            std::cout << "ERROR: 'analyze' requires a directory path." << std::endl;
            std::cout << "Use: ./codevault analyze <path_to_directory>" << std::endl;
            return 1;
        }
        std::string path = argv[2];
        analyzer.populate(path);
        
    }
    else if(command =="report"){
        std::cout << "Running full report. Analyzing current directory ('.') first." << std::endl;
        analyzer.populate("."); // Load data from current folder
        analyzer.report();
    }
    else if (command == "fsearch"){
        if (argc != 3) {
            std::cout << "ERROR: 'search' requires a filename." << std::endl;
            std::cout << "Use: ./codevault search <filename_to_find>" << std::endl;
            return 1;
        }
    }
}
