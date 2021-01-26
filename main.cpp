#include <iterator>
#include <iostream>
#include <vector>
#include <list>
#include <typeinfo>
#include "./include/vector.hpp"

int main()
{
    int i;
    char    tab[] = {'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    std::vector<int> vec(2, 6);
    vec.push_back(12);
    vec.push_back(36);
    vec.push_back(94);
    std::vector<int>::iterator a(vec.begin());
    std::vector<int>::iterator b(vec.begin());

    for (i = 0; a + i < vec.end() ; i++)
        std::cout << *(a + i) << " ";
    std::cout << "\n";
    b = vec.erase(a + 2);
    for (i = 0; a + i < vec.end() ; i++)
        std::cout << *(a + i) << " ";
    std::cout << "\n";
    for (i = 0; b + i < vec.end() ; i++)
        std::cout << *(b + i) << " ";
    std::cout << *(a + 2) << " ";
    std::cout << "\n";
    return 0;
}