
//need corrections and correct research before implementation

#ifndef HEAD_HPP
#define HEAD_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm> // For std::sort, used in minMax/searchfile indirectly

// Define the namespace alias for convenience
//namespace fs = std::filesystem;

// -----------------------------------------------------------------
// 1. DATA STRUCTURES
// -----------------------------------------------------------------
/**
 * @brief Represents the core metadata for an analyzed file.
 */
struct fileStructure {
  std::string name;
  long long byte_size;
};

// -----------------------------------------------------------------
// 2. CLASS DECLARATIONS (Interface Only)
// -----------------------------------------------------------------

/**
 * @brief Core logic class for file system analysis and data manipulation.
 * * Contains methods for populating data, reporting, sorting, and searching.
 */
class analyzer {
  private:
    std::vector<fileStructure> files;

  public:
    // Core Data Management
    void populate_data(const std::string& path = ".");
    void reportData();
    
    // Analysis and Manipulation
    auto sortFileOnByte(bool x); // Note: Should probably return void, or the max byte size.
    void minMax();
    void searchfile(const std::string& fname);
    void searchfile(); // Interactive wrapper
    
    // Utility
    void lineCount(const std::string& filepath);
    void lineCount(); // Interactive wrapper
};

/**
 * @brief Manages the user interface for Interactive Mode.
 */
class cliManager {
  public:
    /**
     * @brief Runs the continuous interactive loop.
     * @param a Reference to the analyzer object to execute commands on.
     */
    void runterminal(analyzer &a);
};

// -----------------------------------------------------------------
// 3. UTILITY FUNCTION DECLARATIONS
// -----------------------------------------------------------------

/**
 * @brief Prints the tool's main banner/header.
 */
void printBanner();

#endif // HEAD_HPP