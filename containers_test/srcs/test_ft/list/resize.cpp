#include "list.hpp"
#include <iostream>
#include <string>

struct a
{
    int a;
};

template <typename T>
void    test(ft::list<T>  &list, typename ft::list<T>::iterator it_beg, typename ft::list<T>::iterator it_end)
{
    size_t i;
    try
    {
        typename ft::list<T>::iterator it(list.begin());
        std::cout << (it == it_beg) << " ";
        std::cout << (list.end() == it_end) << "\n";
        for (i = 0; i < list.size(); i++)
        {
            std::cout << *it++ << " ";
        }
        std::cout << "\n";
        for (i = 0; i < list.size(); i++)
        {
            std::cout << *++it << " ";
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
    if (list.size() > 0)
    {
        std::cout << *list.begin() << " ";
        std::cout << *--list.end() << " "; // a partir de la indefini
        std::cout << *list.rbegin() << " ";
        std::cout << *--list.rend() << " ";
        std::cout << list.front() << " ";
        std::cout << list.back() << " ";
    }
    else
    {
        std::cout << (list.begin() == list.end()) << " ";
        std::cout << (list.rbegin() == list.rend()) << " ";
        list.front();
        list.back();
    }
    std::cout << "\n";
}

void    test(ft::list<struct a>  &list, ft::list<struct a>::iterator it_beg, ft::list<struct a>::iterator it_end)
{
    size_t i;
    try
    {
        ft::list<struct a>::iterator it(list.begin());
        std::cout << (it == it_beg) << " ";
        std::cout << (list.end() == it_end) << "\n";
        for (i = 0; i < list.size(); i++)
        {
            std::cout << (*it++).a << " ";
        }
        std::cout << "\n";
        for (i = 0; i < list.size(); i++)
        {
            std::cout << (*++it).a << " ";
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
    if (list.size() > 0)
    {
        std::cout << (*list.begin()).a << " ";
        std::cout << (*--list.end()).a << " "; // a partir de la indefini
        std::cout << (*list.rbegin()).a << " ";
        std::cout << (*--list.rend()).a << " ";
        std::cout << (list.front()).a << " ";
        std::cout << (list.back()).a << " ";
    }
    else
    {
        std::cout << (list.begin() == list.end()) << " ";
        std::cout << (list.rbegin() == list.rend()) << " ";
        list.front();
        list.back();
    }
    std::cout << "\n";
}

template <typename T>
void    test(ft::list<T *>  &list, typename ft::list<T *>::iterator it_beg, typename ft::list<T *>::iterator it_end)
{
    size_t i;
    size_t j;
    try
    {
        typename ft::list<T *>::iterator it(list.begin());
        std::cout << (it == it_beg) << " ";
        std::cout << (list.end() == it_end) << "\n";
        for (i = 0; i < list.size(); i++)
        {
            for (j = 0; (*it)[j] != 0; j++)
                std::cout << (*it)[j];
            std::cout << " ";
            it++;
        }
        std::cout << "\n";
        for (i = 0; i < list.size(); i++)
        {
            ++it;
            for (j = 0; (*it)[j] != 0; j++)
                std::cout << (*it)[j];
            std::cout << " ";
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
    if (list.size() > 0)
    {
        std::cout << **list.begin() << " ";
        std::cout << **list.rbegin() << " ";
        std::cout << **--list.end() << " "; // a partir de la indefini
        std::cout << **--list.rend() << " ";
        std::cout << *list.front() << " ";
        std::cout << *list.back() << " ";
    }
    else
    {
        std::cout << (list.begin() == list.end()) << " ";
        std::cout << (list.rbegin() == list.rend()) << " ";
        list.front();
        list.back();
    }
    
    std::cout << "\n";
}

template <typename T>
void            test_func(ft::list<T> lst, size_t size)
{
    typename ft::list<T>::iterator beg(lst.begin());
    typename ft::list<T>::iterator end(lst.end());

    lst.resize(size);

    test(lst, beg, end);
}

template <typename T>
void            test_func(ft::list<T> lst, size_t size, const T &val)
{
    typename ft::list<T>::iterator beg(lst.begin());
    typename ft::list<T>::iterator end(lst.end());

    lst.resize(size, val);

    test(lst, beg, end);
}

template <typename T>
ft::list<T>        create(int size, const T &val)
{
    ft::list<T>     lst(size, val);

    return (lst);
}

template<typename T>
void    test_all(const T &val, const T &new_val, int ok, int min1, int max1, int min2, int max2)
{
    int i = 0;
    int j = 0;

    while (i < 20)
    {
        j = 0;
        while (j < 40)
        {
            test_func(create(i, val), j, new_val);
            if (ok)
                test_func(create(i, val), j, new_val);
            j++;
        }
        i++;
    }

    while (min1 < max1)
    {
        j = min2;
        while (j < max2)
        {
            test_func(create(i, val), j, new_val);
            if (ok)
                test_func(create(i, val), j, new_val);
            j++;
        }
        min1++;
    }
    
}

int main()
{
    std::string     str1("test1");
    std::string     str2("test2");
    double          db1(-88.8);
    double          db2(8099.61);
    int             tab_int1[] = {12, 27, 9, 255, 447, 828, 0};
    int             tab_int2[] = {-12, -27, -9, -255, -447, -828, 0};
    char            tab_char1[] = "poule";
    char            tab_char2[] = "entourloupe";

    //std::cout << "a\n";
    test_all(900, 9001, 1, 450, 470, 449, 471);
    test_all('j', 'e', 1, 700, 703, 680, 713);
    test_all(db1, db2, 1, 999, 1010, 998, 1011);
    test_all(str1, str2, 0, 47, 51, 42, 60);
    test_all(static_cast<char *>(tab_char1), static_cast<char *>(tab_char2), 0, 31, 38, 30, 39);
    test_all(static_cast<int *>(tab_int1), static_cast<int *>(tab_int2), 0, 24, 26, 21, 29);


    return (0);
}