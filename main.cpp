#include <iterator>
#include <iostream>
#include <vector>

int main()
{
    int         tab[] = {5, 6, 7, 8};
    std::vector<int>::iterator iterator(tab);
    std::vector<int>::iterator iterator1 = iterator;

    std::cout << *iterator << "\n";
    std::cout << *iterator1 << "\n";
    *iterator1++;
    std::cout << *iterator << "\n";
    std::cout << *iterator1 << "\n";
    *iterator1 = 9;
    std::cout << *iterator << "\n";
    std::cout << *iterator1 << "\n";

    return (0);
}