#include <iostream>
#include <string>

//#include "main.cpp"

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

    if(command=="populate"){// to read the files or the directory
        if (argc != 3) {// 3, since the populate needs the filename or directory as the 3rd word in the command.
            std::cout << "ERROR: 'analyze' requires a directory path." << std::endl;
            std::cout << "Use: ./codevault analyze <path_to_directory>" << std::endl;
            return 1;
        }
        std::string path = argv[2];// words start from 0 ,so 2is the 3rd word i.e., the filename.
        analyzer.populate(path);
        
    }
    else if(command =="report"){
        std::cout << "Running full report. Analyzing current directory ('.') first." << std::endl;
        analyzer.populate("."); // need explanation !!!
        analyzer.report();
    }
    else if (command == "fsearch"){
        if (argc != 3) {
            std::cout << "ERROR: 'search' requires a filename." << std::endl;
            std::cout << "Use: ./codevault search <filename_to_find>" << std::endl;
            return 1;
        }
        a.analyze("."); // need explanation !!!
        std::string fileName = argv[2]; // The file name to find is argv[2]
        a.search(fileName);
    }
    else if (command == "fmax") {
        // Load data first, then find the largest file.
        a.analyze(".");
        a.maxByte();
    }
    else {
        std::cout << "ERROR: Unknown command '" << command << ". Check \' help \' for available commands." << std::endl;
        return 1; //default statement for error check.
    }
    return 0 //program success
}
