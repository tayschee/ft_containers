#include <iostream>
#include <list>
#include "list.hpp"
#include "vector.hpp"
#include <typeinfo>
#include <memory>
#include <string>
#include <stdio.h>
#include <vector>

struct a
{
    int value;
    void    *next;
};

struct b
{
    std::string val;
    void *next;
};

int main()
{
    int i;
    int             tab[] = {12, 24, 32, 64};
    std::list<int>   a(1, 12);
    a.push_back(24);
    a.push_back(32);
    a.push_back(64);
    std::vector<int>::iterator vit1(tab);
    std::vector<int>::iterator vit2(&tab[4]);
    std::list<int> b(a.begin(), a.end());
    std::list<int>::iterator it1(b.begin());
    std::list<int>::iterator it2(b.end());


    std::list<int> c(vit2, vit1);

    it1 = c.begin();

    std::cout << "size : " << c.size() << "\n";
    while (i < c.size())
    {
        std::cout << *it1++ << "\n";
        i++;
    }
   
    return (0);

}

