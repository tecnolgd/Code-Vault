
#include <iostream>
#include <vector>
#include <string>

struct fileStructure {
  std::string name;
  long long byte_size = 0;
};

class analyser{
  private:
  std::vector <fileStructure> files;
  public:
  void populate_test_data(){
    std::cout<<"--poplating vector with test data---\n";
    files.clear();
    


  }
};
int main(){
  return 0;
}

