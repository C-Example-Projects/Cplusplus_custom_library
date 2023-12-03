#include <iostream>
#include "stl_lib/map.h"

int main()
{
    lib::map<std::string, int> map;
    map.push("Baa", 65);
    map.push("Bao", 1);
    map.push("Bao", 5);
    map.push("AAA", 2);

    for (auto it = map.begin(); it != map.end(); ++it)
    {
        std::cout << it.first() << " " << it.second();
        std::cout << std::endl;
    }

    std::cout << "[]: " << map["AAA"] << std::endl;
    std::cout << "contains: " << map.contains("c") << std::endl;

    map.erase(2);
    map.clear();


    for (auto it = map.begin(); it != map.end(); ++it)
    {
        std::cout << it.first() << " " << it.second();
        std::cout << std::endl;
    }
}