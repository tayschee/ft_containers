#include <list>
#include <vector>
#include <iostream>
#include <string>

struct a
{
    int a;
};

template <typename T>
void    test(std::list<T>  &list)
{
    size_t i;
    try
    {
        typename std::list<T>::iterator it(list.begin());
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

template <typename T>
void    test(std::list<T *>  &list)
{
    size_t i;
    size_t j;
    try
    {
        typename std::list<T *>::iterator it(list.begin());
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
void            test_func(std::list<T> &lst, std::list<T> &lst2, size_t pos, size_t first, size_t last)
{
    typename std::list<T>::iterator it_beg(lst.begin());
    typename std::list<T>::iterator it_first(lst2.begin());
    typename std::list<T>::iterator it_last(lst2.begin());

    while (pos)
    {
        --pos;
        ++it_beg;
    }
    while (first)
    {
        --first;
        ++it_first;
    }
    while (last)
    {
        --last;
        ++it_last;
    }
    lst.splice(it_beg, lst2, it_first, it_last);

    test(lst);
    test(lst2);
}

template <typename T>
void            test_func(std::list<T> &lst, std::list<T> &lst2, size_t pos, size_t pos2)
{
    typename std::list<T>::iterator it_beg(lst.begin());
    typename std::list<T>::iterator it_beg2(lst2.begin());

    while (pos)
    {
        --pos;
        ++it_beg;
    }
    while (pos2)
    {
        --pos2;
        ++it_beg2;
    }
    lst.splice(it_beg, lst2, it_beg2);

    test(lst);
    test(lst2);
}

template <typename T>
void            test_func(std::list<T> &lst, std::list<T> &lst2, size_t pos)
{
    typename std::list<T>::iterator it_beg(lst.begin());

    while (pos)
    {
        --pos;
        ++it_beg;
    }
    lst.splice(it_beg, lst2);

    test(lst);
    test(lst2);
}

template<typename T>
void    test_all(T *tab1, size_t size1, T *tab2, size_t size2, size_t pos, size_t first, size_t last)
{
    std::list<T> lst(tab1, tab1 + size1);
    std::list<T> lst2(tab2, tab2 + size2);
    std::list<T> lst3(tab2, tab2 + size2);

    test_func(lst, lst2, pos, first, first);
    test_func(lst, lst2, pos, first, last);
    test_func(lst, lst2, pos, 0, first);
    test_func(lst, lst3, lst.size(), last, lst3.size());
    test_func(lst, lst3, 0, first, last);
    test_func(lst2, lst, 0, first, last);
    lst2.clear();
    test_func(lst2, lst, 0, first, last);
    test_func(lst, lst2, 0, 0, lst2.size());
}

template<typename T>
void    test_all(T *tab1, size_t size1, T *tab2, size_t size2, size_t pos, size_t pos2)
{
    std::list<T> lst(tab1, tab1 + size1);
    std::list<T> lst2(tab2, tab2 + size2);
    std::list<T> lst3(tab2, tab2 + size2);

    test_func(lst, lst2, pos, pos2);
    test_func(lst, lst2, pos, pos2);
    test_func(lst, lst2, pos, 0);
    test_func(lst, lst2, 0, 0);
    test_func(lst, lst2, 0, lst.size() - 1);
    test_func(lst, lst3, lst.size(), pos2);
    test_func(lst, lst3, 0, pos2);
    test_func(lst2, lst, 0, pos2);
    lst2.clear();
    test_func(lst2, lst, 0, pos2);
    test_func(lst, lst, 0, pos);
}

template<typename T>
void    test_all(size_t size, T val, size_t size2, T val2, size_t pos)
{
    std::list<T> lst(size, val);
    std::list<T> lst2(size2, val2);
    std::list<T> lst3(size2, val2);

    test_func(lst, lst2, pos);
    test_func(lst, lst2, pos);
    test_func(lst, lst3, lst.size());
    test_func(lst2, lst, 0);
    lst2.clear();
    test_func(lst2, lst, 0);
}

int main()
{
    std::string     str1("test1");
    std::string     str2("test2");
    int             tab_int1[] = {12, 36, 94, -121, 858, 327, 451, 32, 43, 44, 99, -1002, 255, 808, 218, 441, 90, -5, -12, 244, 0};
    int             tab_int2[] = {-12, -36, -94, 121, -858, -327, -451, 220, 90, 57, 18, 2, 0};
    char             tab_char1[] = "abcedfghijklmnopqrstuvwxyzon omatopee yataa tatakae tatakae tourte";
    char             tab_char2[] = "abefidlbfrlhefjnwhudb32ewdshub";
    double             tab_db1[] = {12, 36, 94, -121, 858, 327, 451, 32, 43, 44, 99, -1002, 255, 441, 90, -5, -12, 244, 0};
    double             tab_db2[] = {-12, -36, -94, 121, -858, -327, -451, 220, 90, 57, 18, 2, 0, 16, 42, 48, 7700};

    test_all(951, 900, 1024, 440, 506);
    test_all(10, 8, 1, -8, 1);
    test_all(2341, 'c', 220, 'j', 2300);
    test_all(631, 12.94, 10, 13.87, 21);
    test_all(42, str1, 42, str2, 21);
    test_all(12, tab_int1, 3, tab_int2, 10);
    test_all(92, tab_char1, 31, tab_char2, 30);

    test_all(tab_int1, 21, tab_int2, 13, 10, 3);
    test_all(tab_char1, 67, tab_char2, 31, 42, 25);
    test_all(tab_int1, 21, tab_int2, 13, 10, 3);
    test_all(tab_db1, 19, tab_db2, 17, 16, 6);

    test_all(tab_int1, 21, tab_int2, 13, 10, 3, 10);
    test_all(tab_char1, 67, tab_char2, 31, 42, 25, 30);
    test_all(tab_int1, 21, tab_int2, 13, 10, 3, 11);
    test_all(tab_db1, 19, tab_db2, 17, 16, 6, 7);
    




    return (0);
}