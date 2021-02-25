#include <iostream>
#include <list>
#include <vector>
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
    std::vector<int>    lst(12);
    //std::vector<int>    lst1(4);
    std::vector<int>::iterator  it(lst.begin());


    std::cout << lst.capacity() << " " << lst.size() << "\n";
    //std::cout << lst1.capacity() << " " << lst1.size() << "\n\n";
    try
    {
        lst.insert(it, 12);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what();
    }
    //lst1 = lst;
    //lst1.resize(9);
    std::cout << lst.capacity() << " " << lst.size() << "\n";
    //std::cout << lst1.capacity() << " " << lst1.size() << "\n";
    

    return 0;
}