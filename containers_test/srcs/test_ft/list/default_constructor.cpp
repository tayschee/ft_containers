#include "list.hpp"
#include <iostream>
#include <string>

struct a
{
    int a;
};

template <typename T>
void    test(T  list)
{
    size_t i;
    try
    {
        typename T::iterator it(list.begin());
        for (i = 0; i < list.size(); i++)
        {
            std::cout << *it++;
        }
        std::cout << "\n";
        for (i = 0; i < list.size(); i++)
        {
            std::cout << *++it;
        }
        std::cout << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << list.empty() << " ";
    std::cout << list.size() << " ";
    std::cout << list.max_size() << " ";
    std::cout << (list.begin() == list.end()) << " "; // a partir de la indefini
    std::cout << (list.rbegin() == list.rend()) << " ";
    list.front();
    list.back();
    std::cout << "\n";
}

void    test(ft::list<struct a>  list)
{
    size_t i;
    try
    {
        ft::list<struct a>::iterator it(list.begin());
        for (i = 0; i < list.size(); i++)
        {
            std::cout << (*it++).a << " ";
        }
        std::cout << "\n";
        for (i = 0; i < list.size(); i++)
        {
            std::cout << (*it++).a << " ";
        }
        std::cout << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << list.empty() << " ";
    std::cout << list.size() << " ";
    std::cout << list.max_size() << " ";
    std::cout << (list.begin() == list.end()) << " "; // a partir de la indefini
    std::cout << (list.rbegin() == list.rend()) << " ";
    list.front();
    list.back();
    std::cout << "\n";
}

int main()
{
    ft::list<int>   list1;
    ft::list<char>   list2;
    ft::list<std::string>   list3;
    ft::list<int *>   list4;
    ft::list<struct a>   list5;
    ft::list<char *>   list6;
    ft::list<void *>   list7;



    test(list1);
    test(list2);
    test(list3);
    test(list4);
    test(list5);
    test(list6);
    test(list7);

    return (0);
}