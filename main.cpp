#include <iostream>
#include "stl_lib/hash_table.h"

int main()
{
    lib::hashtable<std::string, int> myHashTable;

    myHashTable.insert("One", 1);
    myHashTable.insert("Two", 2);
    myHashTable.insert("Three", 3);
    myHashTable.insert("Four", 4);
    myHashTable.insert("Five", 5);

    std::cout << "Hash Table contents:" << std::endl;
    myHashTable.display();

    int value;
    if (myHashTable.find("Two", value)) {
        std::cout << "Value of 'Two': " << value << std::endl;
    } else {
        std::cout << "'Two' not found in the hash table." << std::endl;
    }

    myHashTable.remove("Two");

    std::cout << "After removing 'Two':" << std::endl;
    myHashTable.display();
}