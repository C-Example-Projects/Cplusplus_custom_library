#include <iostream>
#include "list/List.h"

int main()
{
    List<int> list;
    list.push(10);
    list.push(15);
    list.push(20);

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << (*it) << " ";
    }

    auto it = list.begin();
    std::cout << "Next: " << *(it.next(2));
    list.clear();

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << "2: " << (*it) << " ";
    }

    return 0;
}