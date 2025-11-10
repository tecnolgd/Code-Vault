
//need corrections and correct research before implementation

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream> //file I/O
#include <filesystem> //filesystem operations

struct fileStructure {
  std::string name;
  long long byte_size; //for large byte-count (since files have a lot of bytes)
};

class analyzer{
    private:
    std::vector <fileStructure> files;

    public:
    void populate_data( const std::string& path=".");
    void reportData();
    auto sortFileOnByte(bool x);
    void minMax();
    void searchfile(const std::string& fname);
    void searchfile();
    void lineCount(const std::string& filepath);
    void lineCount();


};

class cliManager{
    public:
    void runterminal(analyzer &a);
};



#endif