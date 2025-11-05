#include <iostream>
#include <string>

#include "main.cpp"

int main(int argc, char* argv[]){ //to get the number of words used in the command to interpret the command given by the user.
    analyzer a; //object of class analyser
    cliManager cli; //object of class cliManager
    
    if(argc<2){ //error check
        cli.runterminal(a); //passing address of class analyser object 'a' to function 'runterminal' 
        
        return 0;
    }
    std::cout << "------------------------------------------" << std::endl;
        std::cout << "\tCodeVault - C++ Code Analyzer (Beta)" << std::endl;
        
    std::string command = argv[1]; //first word is the command
    /*if (command == "analyze") {
        if (argc != 3) {
            std::cout << "Usage: " << argv[0] << " analyze <directory_path>\n";
            return 1;
        }
        a.populate_data(argv[2]);
        a.reportData();
    }*/
    if(command=="populate"){
        if (argc != 3) {
            std::cout << "ERROR: 'analyze' requires a directory path." << std::endl;
            std::cout << "Use: ./codevault analyze <path_to_directory>" << std::endl;
            return 2;
        }
        std::string path = argv[2];
        a.populate_data(argv[2]);
        
    }
    else if(command =="report"){
        std::cout << "Running full report. Analyzing current directory ('.') first." << std::endl;
        a.populate_data(argv[2]); // need explanation !!!
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
    else if(command == "report"){
        std::string path = (argc >= 3) ? argv[2] : "."; // use provided path or default to current dir
        std::cout << "Running full report. Analyzing directory '" << path << "'.\n";
        a.populate_data(path);
        a.reportData(); 
        std::cout << "ERROR: Unknown command '" << command << ". Check \' help \' for available commands." << std::endl;
        return -1; //default statement for error check.
    }

    return 0; //program success
}
