#include <iostream>
#include <string>

#include "main.cpp"

int main(int argc, char* argv[]){ //to get the number of words used in the command to interpret the command given by the user.
    analyzer a; //object of class analyser
    cliManager cli; //object of class cliManager
    
    if(argc<2){ //error check
        std::cout<<"Starting interactive mode ...\n";
        cli.runterminal(a); //passing address of class analyser object 'a' to function 'runterminal' 
        
        return 0;
    }
    std::string command = argv[1];
    
    //std::cout << "------------------------------------------" << std::endl;
       // std::cout << "\tCodeVault - C++ Code Analyzer (Beta)" << std::endl;
        
    if (command == "populate") {
        std::string path = (argc >= 3) ? argv[2] : ".";
        a.populate_data(path);
    }
    else if (command == "report") {
        // First populate data if not already done
        if (argc >= 3) {
            a.populate_data(argv[2]);
        } else {
            a.populate_data(".");
        }
        a.reportData();
    }
    else if (command == "fsearch") {
        a.populate_data(".");  // First load current directory
        a.searchfile();
    }
    else if (command == "fmax") {
        a.populate_data(".");  // First load current directory
        a.minMax();
    }
    else if (command == "help") {
        std::cout << "\nAvailable commands:\n"
                  << "populate [path]  - Load files from directory\n"
                  << "report [path]    - Show analysis report\n"
                  << "fsearch         - Search for a file\n"
                  << "fmax            - Show largest file\n"
                  << "help            - Show this help message\n";
    }
    else {
        std::cout << "Unknown command: " << command << "\n"
                  << "Use 'help' to see available commands\n";
        return 1;
    }

    return 0;
}

  