
#include <iostream>
#include <vector>
#include <string>

struct fileStructure {
  std::string name;
  long long byte_size = 0; //for large number storage (since files have a lot of bytes)
};

class analyzer{
  private: //private- to avoid unwanted file vector corruption
  std::vector <fileStructure> files; //vector to store files
  public:
  void populate_data(){ //reading files with bytes size in each file
    std::cout<<"--poplating vector with test data---\n";
    files.clear();
   
        files.push_back({"main.cpp", 1250});//pushing file name and byte size to vector files 
        files.push_back({"header.hpp", 450});
        files.push_back({"utility.cpp", 2100});
        files.push_back({"config.h", 55});
  }
        void reportData() { //report generation function
        if (files.empty()) {
            std::cout << "Vector is empty. Run 'populate' first.\n";
            return;
        }

        std::cout << "\n--- CodeVault Vector Report (Summation) ---\n"; //report summary 
        long long totalSizeBytes = 0;
        
        // CORE DSA: Iterating over the entire vector (array).
        for (const auto& file : files) { // for each loop ,const auto ??
            std::cout << " - File: " << file.name << " (" << file.byte_size << " bytes)\n";
            totalSizeBytes += file.byte_size; //total bytes size
        }

        std::cout << "\nTotal Files Stored: " << files.size() << "\n"; //size() function
        std::cout << "Total Codebase Size: " << totalSizeBytes << " bytes\n";
    }
    
    // Future Expansion Point: This is where advanced features will go.
    // Example: void searchFile(const std::string& name); // Linear Search!


};

// --- Execution Focus: Simplified Main Loop ---
int main() {
    analyzer a; //object
    std::string command;
    
    std::cout << "Welcome to CodeVault Basic. Focus: Vector/Array Operations.\n";
    
    while (true) {
        std::cout << "\n>>";
        std::cin >> command;

        if (command == "exit") {
            break;
        } else if (command == "populate") {
            a.populate_data();
        } else if (command == "report") {
            a.reportData();
        } else if (command == "help") {
            std::cout << "Commands: populate, report, exit\n";
        } else {
            std::cout << "Unknown command.\n";
        }
    }

    return 0;
}


    


 
