#include <iostream>
#include <string>

#include "main.cpp"

int main(int argc, char* argv[]){ //to get the number of words used in the command to interpret the command given by the user.
    if(argc<2){ //error check
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "\tCodeVault - C++ Code Analyzer (Beta)" << std::endl;
        std::cout << "Error: At least two words needed\n" << std::endl;
        std::cout<<"( Note: Try using \'help\')"<<std::endl;
        return 1;
    }
    std::string command = argv[1]; //first word is the command
    analyzer a; //object of class analyser
    cliManager cli; //object of class cliManager
    cli.runterminal(a); //passing address of class analyser object 'a' to function 'runterminal' 
    std::cout<<"Enter command:";
    std::cin>>command;
    if(command=="populate"){
        if (argc != 3) {
            std::cout << "ERROR: 'analyze' requires a directory path." << std::endl;
            std::cout << "Use: ./codevault analyze <path_to_directory>" << std::endl;
            return 2;
        }
        std::string path = argv[2];
        a.populate_data();
        
    }
    else if(command =="report"){
        std::cout << "Running full report. Analyzing current directory ('.') first." << std::endl;
        a.populate_data(); // need explanation !!!
        a.reportData();
    }
    else if (command == "fsearch"){
        if (argc != 3) {
            std::cout << "ERROR: 'search' requires a filename." << std::endl;
            std::cout << "Use: ./codevault search <filename_to_find>" << std::endl;
            return 3;
        }
        //a.analyze("."); // need explanation !!!
        std::string fileName = argv[2]; // The file name to find is argv[2]
        a.searchfile();
    }
    else if (command == "fmax") {
        // Load data first, then find the largest file.
        
        a.minMax();
        
    }
    else {
        std::cout << "ERROR: Unknown command '" << command << ". Check \' help \' for available commands." << std::endl;
        return -1; //default statement for error check.
    }

    return 0; //program success
}
