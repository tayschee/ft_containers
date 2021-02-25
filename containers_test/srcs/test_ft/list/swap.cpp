#include "list.hpp"
#include <iostream>
#include <string>

struct a
{
    int a;
};

template <typename T>
void    test(ft::list<T>  &list)
{
    size_t i;
    try
    {
        typename ft::list<T>::iterator it(list.begin());
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

void    test(ft::list<struct a>  &list)
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
void    test(ft::list<T *>  &list)
{
    size_t i;
    size_t j;
    try
    {
        typename ft::list<T *>::iterator it(list.begin());
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
void            test_func(ft::list<T> lst, ft::list<T> lst_bis)
{
    typename ft::list<T>::iterator beg_lst(lst.begin());
    typename ft::list<T>::iterator beg_bis(lst_bis.begin());

    lst.swap(lst_bis);

    if (lst.size() != 0 && lst_bis.size() != 0)
    {
        std::cout << (beg_bis  == lst.begin()) << " ";
        std::cout << (beg_lst  == lst_bis.begin()) << "\n";
    }

    test(lst);
    test(lst_bis);
}

template <typename T>
void            test_func1(ft::list<T> lst, ft::list<T> lst_bis)
{
    typename ft::list<T>::iterator beg_lst(lst.begin());
    typename ft::list<T>::iterator beg_bis(lst_bis.begin());
   
    ft::swap(lst_bis, lst);

    if (lst.size() != 0 && lst_bis.size() != 0)
    {
        std::cout << (beg_bis  == lst.begin()) << " ";
        std::cout << (beg_lst  == lst_bis.begin()) << "\n";
    }

    test(lst);
    test(lst_bis);
}

template <typename T>
ft::list<T>        create(int size, const T &val)
{
    ft::list<T>     lst(size, val);

    return (lst);
}

template <typename T>
ft::list<T>        create(int size, const T &val, const T &val2, int nb)
{
    ft::list<T>     lst(size, val);

    while (nb)
    {
        --nb;
        lst.push_back(val2);
    }
    return (lst);
}

template<typename T>
void    test_all(const T &val, const T &val2, int x)
{
    int i = 0;
    int j = 0;

    while (i < 20)
    {
        j = 0;
        while (j < 20)
        {
            test_func(create(i, val), create(j, val2));
            test_func1(create(i, val), create(j, val2));
            j++;
        }
        i++;
    }
    test_func(create(x, val), create(x - 1, val2));
    test_func1(create(x, val), create(x - 1, val2));
    test_func(create(x, val), create(x, val2));
    test_func1(create(x, val), create(x, val2));
    test_func(create(x, val), create(x + 1, val2));
    test_func1(create(x, val), create(x + 1, val2));
}

int main()
{
    std::string     str1("abcdef");
    std::string     str2("ghijkl");
    double          db1(881.8);
    double          db2(129.61);
    int             tab_int1[] = {12, 27, 9, 255, 447, 828, 0};
    int             tab_int2[] = {-12, -27, -9, -255, -447, -828, 0};
    char            tab_char1[] = "poule";
    char            tab_char2[] = "entourloupe";

    //std::cout << "a\n";
    test_all(725, 441, 221);
    test_all('}', '{', 201);
    test_all(db1, db2, 641);
    test_all(str1, str2, 76);
    test_all(static_cast<char *>(tab_char1), static_cast<char *>(tab_char2), 23);
    test_all(static_cast<int *>(tab_int1), static_cast<int *>(tab_int2), 46);


    return (0);
}