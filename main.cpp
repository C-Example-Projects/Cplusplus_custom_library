#include <iostream>
#include "list.h"

int main()
{
    lib::list<int> lists;
    lists.push_back(1);
    lists.push_back(5);
    lists.push_back(9);
    lists.push_front(3);
    lists.push_front(99);
    lists.insert(4, 100);

    std::cout << lists.size() << std::endl;

    for (auto it = lists.begin(); it != lists.end(); ++it)
    {
        std::cout << "Value: " << *it << " ";
    }

    std::cout << std::endl;

    std::cout << "Front: " << lists.front() << std::endl;
    std::cout << "Back: " << lists.back() << std::endl;

    lists.clear();

    return 0;
}