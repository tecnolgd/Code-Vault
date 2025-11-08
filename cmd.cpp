
// requires modifications , this file is the command line interface way i.e., using one command at a time.

#include <iostream>
#include <string>

#include "main.cpp"

void printBanner() {
    std::cout << "----------------------------------------\n"
              << "    CodeVault C++ Analyzer Beta v1.0     \n"
              << "----------------------------------------\n";
}
int main(int argc, char* argv[]){ //to get the number of words used in the command to interpret the command given by the user.
    analyzer a; //object of class analyser
    cliManager cli; //object of class cliManager
    
    printBanner();
    if(argc<2){ //error check
        std::cout<<"Starting interactive mode ...\n";
        cli.runterminal(a); //passing address of class analyser object 'a' to function 'runterminal' 
        
        return 0;
    }
    std::string command = argv[1];
    std::string path= (argc >= 3) ? argv[2] : ".";
    //std::cout << "------------------------------------------" << std::endl;
       // std::cout << "\tCodeVault - C++ Code Analyzer (Beta)" << std::endl;
        
    if ((command == "populate") || (command == "report")) {
        
        a.populate_data(path);
        if(command=="report"){
            a.reportData();
        }
    }             // First populate data if not already done
    
    else {
        if (argc < 2) {
                std::cout << "Usage: codevault <command> <directory name>\n";
                return 1;
        }
        else if (command == "flcount") {
            
            a.populate_data(path);
            a.lineCount();
        }
    
        else if (command == "maxbyte") {
            a.populate_data(path);  // First load current directory
            a.minMax();
        }
        else if(command=="fsearch"){
            a.populate_data(path);
            a.searchfile();
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
    }
    

    return 0;
}

  