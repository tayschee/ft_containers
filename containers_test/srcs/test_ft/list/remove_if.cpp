#include "list.hpp"
#include "vector.hpp"
#include <iostream>
#include <string>

template<typename T>
int     func1(T value)
{
    (void)value;
    std::cout << "func1 pass\n";
    return (1);
}

template<typename T>
int     func2(T value)
{
    (void)value;
    std::cout << "func2 pass\n";
    return (0);
}

template<typename T>
int     func3(T value)
{
    return (value != 0);
}

template<>
int     func3<std::string>(std::string value)
{
    return (value != "");
}

template<typename T>
int     func4(T value)
{
    return (value < 250);
}

template<>
int     func4<std::string>(std::string value)
{
    return (value.size() < 10);
}

template <typename T>
void    test(ft::list<T>  &list, typename ft::list<T>::iterator old_it, size_t n)
{
    size_t i;
    try
    {
        for (i = 0; i < n; i++)
        {
            std::cout << *old_it++ << " ";
        }
        std::cout << "\n";
        for (i = 0; i < n; i++)
        {
            std::cout << *++old_it << " ";
        }
        std::cout << "\n";

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

template <typename T>
void    test(ft::list<T *>  &list, typename ft::list<T>::iterator old_it, size_t n)
{
    size_t i;
    size_t j;
    try
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; (*old_it)[j] != 0; j++)
                std::cout << (*old_it)[j];
            std::cout << " ";
            old_it++;
        }
        std::cout << "\n";
        for (i = 0; i < n; i++)
        {
            ++old_it;
            for (j = 0; (*old_it)[j] != 0; j++)
                std::cout << (*old_it)[j];
            std::cout << " ";
        }
        std::cout << "\n";

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
void            test_func(ft::list<T> lst, int (*func)(T))
{
    typename ft::list<T>::iterator old_it(lst.begin());

   
    lst.remove_if(func);
    if (lst.begin() != old_it)
        old_it = lst.begin();
    test(lst, old_it, lst.size());
}

template <typename T>
ft::list<T>        create(T *tab, size_t size)
{
    typename ft::vector<T>::iterator beg(tab);
    typename ft::vector<T>::iterator end(tab + size);

    ft::list<T>     lst(beg, end);

    return (lst);
}

template<typename T>
void    test_all(T *tab, size_t size, T val, size_t size1, T val2, size_t size2)
{
    ft::list<T> lst(create(tab, size));
    ft::list<T> lst1(size1, val);
    ft::list<T> lst2(size2, val2);
    ft::list<T> lst3;

    test_func(lst, func2);
    test_func(lst, func3);
    test_func(lst, func4);
    test_func(lst, func1);

    test_func(lst1, func2);
    test_func(lst1, func3);
    test_func(lst1, func4);
    test_func(lst1, func1);

    test_func(lst2, func2);
    test_func(lst2, func3);
    test_func(lst2, func4);
    test_func(lst2, func1);

    test_func(lst3, func3);
    test_func(lst3, func2);
    test_func(lst3, func1);
    test_func(lst3, func4);
}

int main()
{
    std::string     str1("test1");
    std::string     str2("test2");
    std::string     str3("test3hertgsfehe");
    std::string     str4("oups");
    std::string     str5("allezfrwegrewbre");
    std::string     str6("word");
    std::string     str7("oulaoup");
    std::string     str8("pause");
    std::string     str9("poseyyetrgevsdevfdsfv");
    std::string     str10("bouyachaka");
    std::string     tab_str[] = {str1, str2, str3, str4, str5, str6, str7, str8, str9, str10, str7};
    int             tab_int[] = {0, 36, 94, -121, 858, 327, 451, 32, 12, 44, 99, -1002, 0, 808, 218, 441, 90, -5, 12, 251};
    double          tab_db[] = {1022.7, 0, 94, -121, 44, 327, 451, 32, 1, 43, 44, 99, -1002, 255, 808, 218, 
                                441.12, 90, -5, -12, 244, -98.7, -99.2, 72.2};
    char             tab_char[] = "abcedfghijklmnopqrstuvwxyzon omatopee yataa tatakae tatakae tourte";
    char             tab_char1[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXxXXXXXXXXXXXXXXXXXXXXXXXX";

    std::cout << "a\n";
    test_all(tab_int, 20 , -7, 12, 25, 99);
    test_all(tab_char, 55, ' ', 4001, '"', 890);
    test_all(tab_char1, 54, 'X', 20, 'x', 12);
    test_all(tab_db, 23, 12.89, 840, 72.2, 3);
    test_all(tab_str, 10, str7, 41, str8, 12);

    return (0);
}