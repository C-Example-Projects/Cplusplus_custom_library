#include <iostream>
#include "stl_lib/vector.h"
#include "stl_lib/list.h"
#include "stl_lib/pair.h"

int main()
{
    lib::pair<int, std::string> pairs(1, "BAO DEP ZAI");

    std::cout << "first: " << pairs.first << std::endl;
    std::cout << "second: " << pairs.second << std::endl;

    auto pair = lib::make_pair<int, std::string>(2, "NGAN XINH DEP");
    
    std::cout << "first: " << pair.first << std::endl;
    std::cout << "second: " << pair.second << std::endl;
  
    return 0;
}