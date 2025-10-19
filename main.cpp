
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>

struct fileStructure {
  std::string name;
  long long byte_size; //for large number storage (since files have a lot of bytes)
};

class analyzer{
  private: //private- to avoid unwanted file vector corruption
    std::vector <fileStructure> files; //vector to store files
  public:
  
    void populate_data(){ //reading files with bytes size in each file
        std::cout<<"--poplating vector with test data---\n";
        files.clear();
        // sample raw coded file names for testing
        files.push_back({"main.cpp", 1250});//pushing file name and byte size to vector files 
        files.push_back({"header.hpp", 450}); //basically stack operation
        files.push_back({"utility.cpp", 2100});
        files.push_back({"config.h", 55});
    }
   
    void reportData() { //report generation function
        if (files.empty()) { //checks if file is empty or not
            std::cout << "Vector is empty. Run 'populate' first.\n";
            return;
        }                                                          std::cout << "\n--- CodeVault Vector Report (Summation) ---\n"; //report summary 
        long long totalSizeBytes = 0;
        
        // CORE DSA: Iterating over the entire vector (array).
        for (int i=0; i<files.size();i++) { // for loop
            std::cout << " - File: " << files[i].name << " (" << files[i].byte_size << " bytes)\n";
            totalSizeBytes += files[i].byte_size; //total bytes size
        }
        std::cout << "\nTotal Files Stored: " << files.size() << "\n"; //size() function
        std::cout << "Total Codebase Size: " << totalSizeBytes << " bytes\n";
    }
    auto sortFileOnByte(bool x){
        //function to sort files based on byte size
        for( int i=0;i<files.size()-1;i++){
             for(int j=0;j<files.size()-1-i;j++){

                if(files[j].byte_size>files[j+1].byte_size){ //to sort bytes
                auto t=files[j].byte_size;
                files[j].byte_size=files[j+1].byte_size;
                files[j+1].byte_size=t;

                auto s=files[j].name;  //to sort file names , 'auto' - for automatic data type 
                files[j].name=files[j+1].name;
                files[j+1].name=s;
                }
            }
        }

        if(x){ //this would work if x is 1 ,i.e when the sortbyte function is called
            std::cout<<"Sorted files based on bytes :\n";
            for(int i=0;i<files.size();i++){
                std::cout << " - File: " << files[i].name << " (" << files[i].byte_size << " bytes)\n";
            }
        }
        int size= files.size();
        return files[size-1].byte_size;//return the max bytes since the sort is ascending order
    }
    void minMax(){
        int x= sortFileOnByte(0);//this makes sure the sortbyte bool x has value zeo so as to skip the sorted files display
        std::cout<<"Max byte containing file: "<<x;
    }

    void searchfile(){ //to search the file vector based on the file name.
        int x= sortFileOnByte(0); //to sort the vector before binary search.
        int size=files.size();
        int key; //key - for condition verification
        int low=0,mid,high=size-1;
        std::string fname;
        std::cout<<"Enter name of the file to be searched :";
        std::cin>>fname;
    
        while(low<=high){   //binary search algorithm
            mid=(low+high)/2;
            if(files[mid].name == fname){
                key=1;
                break;
            }
            else if(files[mid].name<fname)
                low=mid+1;
                else
                high = mid-1;
        }
        if(key==1){
            std::cout<<"File found at location "<<mid<<" with "<<files[mid].byte_size<<" bytes"<<std::endl;
        }
        else{
            std::cout<<"File not found. Try with a correct name"<<std::endl;
        }
    }
    
    void lineCount(){   //function to count lines of code in a desired file (any file in the system)
        std::string filepath; //string to store filename
        std::cout<<"enter filename ";
        std::cin>>filepath;
        std::ifstream file(filepath); //open file for reading
        if(! file.is_open()){ //to check whether the file exists
            std::cout<<"Error: Could not open file "<<filepath<<" !"<<std::endl;
            return;
        }
        int lCount=0; //line counter
        std::string line; //string to store lines

        while(std::getline(file,line)){ //lines include tab spaces and goes until new line is encountered.
            lCount++; //increment the lCount when new line is encountered.
        }
        file.close();
        if (lCount > 0) { //tocheck    whether file is empty and block any other possible errors.
            std::cout<<std::endl;
            std::cout << "Analysis Complete." << std::endl;
            std::cout << "File: " <<filepath<< std::endl;
            std::cout << "Total Lines of Code: " <<lCount<< std::endl;
        }   
        else {
            std::cout << "Could not complete analysis. Check the path and file permissions." << std::endl;
        }
    }
             
     // Future Expansion Point: This is where advanced features will go.
    // Example: void searchFile(const std::string& name); // Linear Search!

};

class cliManager{ //cli managing class for display of main menu
    public:
    void runterminal(analyzer &a){ //function to run the terminal as a whole 
    std::string command;
    std::cout << "\n\tWelcome to CodeVault Basic. Focus: Vector/Array Operations.\n";
    
    while (true) {
        std::cout << "\n>>";
        std::cin >> command;
        std::cin.clear();
        if ((command == "exit")||(command=="quit")) {
            break;
        } else if (command == "populate") {
            a.populate_data();
        } else if (command == "report") {
            a.reportData();
        } else if(command == "sortbyte"){
            a.sortFileOnByte(1);
        } else if(command == "maxbyte"){
            a.minMax();
        } else if(command == "fsearch"){
            a.searchfile();
        }else if(command == "flcount"){
            a.lineCount();
        }else if(command == "tcred"){
            printf("\n\tCredits :\nAuthor: tecnolgd\nDocumentation at https://c.com\n");
        }else if (command == "help") {
            std::cout << "\n\t-- Available commands --\n populate  - reading /fetching file names and byte size\n sortbyte  - display the files sorted based on byte size\n report    - summarize key findings regarding file data\n fsearch   - to sreach for a file based on its name\n maxbyte   - gives the max byte file\n exit/quit - terminate from the application\n flcount   - display number of lines of code in a desired file\n tcred     - tool credits and doc details\n";
        } else {
            std::cout << "Unknown command. Try using 'help'\n";
        }
    }
}
};

// --- Execution Focus: Simplified Main Loop ---
int main() {
    analyzer a; //object of class analyser
    cliManager cli; //object of class cliManager
    cli.runterminal(a); //passing address of class analyser object 'a' to function 'runterminal' 

    /* Flow of the cli.runterminal(&a); ->  object a  address--> passed to runterminal()function as argument --> later derefenced to get data or value from it --> runterminal() is executed with cli i.e., ' cli.runterminal(&a) '*/

    //Basically, class analyser is the argument for function runterminal() which runs inside class cliManager.
    return 0;
}