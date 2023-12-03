#include <iostream>
#include "stl_lib/vector.h"

int main()
{
    lib::vector<int> list;
    list.push(1);
    list.push(5);
    list.push(9);

    std::cout << list.size() << std::endl;

    for (size_t i = 0; i < list.size(); ++i)
    {
        std::cout << "Value: " << list[i] << " ";
    }


    list.pop();

    for (size_t i = 0; i < list.size(); ++i)
    {
        std::cout << "Value: " << list[i] << " ";
    }

    return 0;
}