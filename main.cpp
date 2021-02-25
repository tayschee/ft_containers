#include <iostream>
#include <list>
#include "list.hpp"



template <class T>
struct is_iterator
{
    static const bool value = true;
};

struct a
{
    static const bool test = true;
    int i = 0;
};

void    x(size_t size, size_t size2)
{
    (void)size;
    std::cout << "nb\n";
}

template <class T>
void x(T size, typename ft::enable_if<T::test, T>::type size2)
{
    (void)size;
    std::cout << "other\n";

}

template <class T>
int     func()
{
    return 1;
}

int main()
{
    ft::list<int>    lst(12, 13);
    ft::list<int>    lst1(11, 14);
    ft::list<int>::iterator    it(lst.begin());
    ft::list<int>::iterator     it1(lst1.begin());

    std::cout << *lst1.begin() << "\n";
    std::cout << *lst.begin() << "\n";
    std::cout << (it == lst1.begin()) << "\n";
    std::cout << (it1 == lst.begin()) << "\n\n";

    lst1.swap(lst);

    std::cout << *lst1.begin() << "\n";
    std::cout << *lst.begin() << "\n";

    std::cout << (it == lst1.begin()) << "\n";
    std::cout << (it1 == lst.begin()) << "\n";


    std::cout << (lst < lst1) << "\n";
    

    return 0;
}