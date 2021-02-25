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
void            test_assign(ft::list<T> lst1, ft::list<T> lst2)
{
    typename ft::list<T>::iterator first(lst2.begin());
    typename ft::list<T>::iterator last(lst2.end());

    typename ft::list<T>::iterator beg(lst1.begin());
    typename ft::list<T>::iterator end(lst1.end());

    std::cout << "ok" << "\n";
    lst1.assign(first, last);
    std::cout << "seg" << "\n";

    test(lst1, beg, end);
}

template <typename T>
void            test_assign(ft::list<T> lst, size_t n, const T &val)
{
    typename ft::list<T>::iterator beg(lst.begin());
    typename ft::list<T>::iterator end(lst.end());
    lst.assign(n, val);

    test(lst, beg, end);
}

template <typename T>
ft::list<T>        create_list(int size, const T &val)
{
    ft::list<T>     lst(size, val);

    return (lst);
}  

template <typename T>
ft::list<T>        create_list(int size, const T &val, int inter, const T &val2, int repeat)
{
    int i = 0;
    ft::list<T>     lst(size, val);

    while(repeat)
    {
        --repeat;
        while (i < inter)
        {
            ++i;
            lst.push_back(val2);
        }
        lst.push_back(val);
    }
    return (lst);
}

template<typename T>
void    test_all1(const ft::list<T> &lst, const ft::list<T> &lst1, const ft::list<T> &lst2, const ft::list<T> &lst3)
{
    ft::list<T> empty_list;

    test_assign(empty_list, empty_list);
    test_assign(empty_list, lst);
    test_assign(empty_list, lst1);
    test_assign(empty_list, lst2);
    test_assign(empty_list, lst3);
    
    test_assign(lst, lst);
    test_assign(lst, lst1);
    test_assign(lst, lst2);
    test_assign(lst, lst3);
}

template<typename T>
void    test_all2(int nb1, const T &x1, const T &x2, int nb2)
{
    int i = 0;
    int j = 0;
    ft::list<T> empty_list;

    while (i < 10)
    {
        test_assign(empty_list, i, x1);
        ++i;
    }
    test_assign(empty_list, nb1, x1);
    while (i < 10)
    {
        while (j < 15)
        {
            test_assign(create_list(i, x1), j, x2);
            j++;
        }
        i++;
    }
    test_assign(create_list(nb2, x1), nb2 - 1, x2);
    test_assign(create_list(nb2, x1), nb2, x2);
    test_assign(create_list(nb2, x1), nb2 + 1, x2);
}

int main()
{
    std::string     str1("test1");
    std::string     str2("test2");
    std::string     str3("test3");
    double          db1(-88.8);
    double          db2(8099.61);
    double          db3(1008.7);
    int             tab_int1[] = {12, 27, 9, 255, 447, 828, 0};
    int             tab_int2[] = {-12, -27, -9, -255, -447, -828, 0};
    int             tab_int3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 1100, 0};
    char            tab_char1[] = "poule";
    char            tab_char2[] = "entourloupe";
    char            tab_char3[] = "sixteen";

    test_all1(create_list(12, 25, 3, -25, 1), create_list(12, 26, 6, -26, 15), create_list(2, 3, 1, -3, 1),
    create_list(12, 2, 3, -36, 1));
    test_all1(create_list(27, 'j', 3, 'i', 1), create_list(18, 'e', 9, '8', 7), create_list(4, 'k', 2, 'l', 1),
    create_list(25, 'O', 5, '"', 1));
    test_all1(create_list(24, str1, 8, str2, 1), create_list(43, str2, 9, str3, 3), create_list(5, str1, 2, str3, 2),
    create_list(28, str3, 4, str1, 1));
    test_all1(create_list(8, db1, 8, db2, 1), create_list(22, db2, 2, db3, 3), create_list(1, db1, 2, db3, 2),
    create_list(15, db3, 1, db1, 1));
    test_all1(create_list(15, static_cast<int *>(tab_int1), 3, static_cast<int *>(tab_int2), 1), 
    create_list(22, static_cast<int *>(tab_int2), 2, static_cast<int *>(tab_int3), 3),
    create_list(1, static_cast<int *>(tab_int1), 2, static_cast<int *>(tab_int3), 2),
    create_list(17, static_cast<int *>(tab_int3), 1, static_cast<int *>(tab_int1), 1));

    test_all1(create_list(8, static_cast<char *>(tab_char1), 8, static_cast<char *>(tab_char2), 1),
    create_list(22, static_cast<char *>(tab_char2), 2, static_cast<char *>(tab_char3), 3),
    create_list(1, static_cast<char *>(tab_char1), 2, static_cast<char *>(tab_char3), 2),
    create_list(15, static_cast<char *>(tab_char3), 1, static_cast<char *>(tab_char1), 1));


    test_all2(445, 8, -18, 3210);
    test_all2(301, 'm', 'k', 1808);
    test_all2(23, str2, str3, 306);
    test_all2(509, db2, db3, 31);
    test_all2(8, static_cast<int *>(tab_int2), static_cast<int *>(tab_int3), 67);
    test_all2(12, static_cast<char *>(tab_char2), static_cast<char *>(tab_char3), 49);


    return (0);
}