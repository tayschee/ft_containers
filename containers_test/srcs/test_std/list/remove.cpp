#include <list>
#include <vector>
#include <iostream>
#include <string>

struct a
{
    int a;
};

template <typename T>
void    test(std::list<T>  &list, typename std::list<T>::iterator old_it, size_t n)
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
void    test(std::list<T *>  &list, typename std::list<T>::iterator old_it, size_t n)
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
void            test_func(std::list<T> &lst, T val)
{
    typename std::list<T>::iterator old_it(lst.begin());

   
    lst.remove(val);
    if (lst.begin() != old_it)
        old_it = lst.begin();
    test(lst, old_it, lst.size());
}

template <typename T>
std::list<T>        create(T *tab, size_t size)
{
    typename std::vector<T>::iterator beg(tab);
    typename std::vector<T>::iterator end(tab + size);

    std::list<T>     lst(beg, end);

    return (lst);
}

template<typename T>
void    test_all(T *tab, size_t size, T val, size_t size1, T val2, size_t size2)
{
    std::list<T> lst(create(tab, size));
    std::list<T> lst1(size1, val);
    std::list<T> lst2(size2, val2);
    std::list<T> lst3;

    
    test_func(lst1, val);
    test_func(lst1, val);
    test_func(lst2, val);
    test_func(lst3, val);
    test_func(lst2, val);
    test_func(lst2, val2);
    test_func(lst3, val);
    test_func(lst, val);
    test_func(lst, val2);
}

int main()
{
    std::string     str1("test1");
    std::string     str2("test2");
    std::string     str3("test3");
    std::string     str4("oups");
    std::string     str5("allez");
    std::string     str6("word");
    std::string     str7("oulaoup");
    std::string     str8("pause");
    std::string     str9("posey");
    std::string     str10("bouyachaka");
    std::string     tab_str[] = {str1, str2, str3, str4, str5, str6, str7, str8, str9, str10, str7};
    int             tab_int[] = {12, 36, 94, -121, 858, 327, 451, 32, 12, 44, 99, -1002, 255, 808, 218, 441, 90, -5, 12, 12};
    double          tab_db[] = {12.89, 36, 94, -121, 44, 327, 451, 32, 1, 43, 44, 99, -1002, 255, 808, 218, 
                                441.12, 90, -5, -12, 244, -98.7, -99.2, 72.2};
    char             tab_char[] = "abcedfghijklmnopqrstuvwxyzon omatopee yataa tatakae tatakae tourte";
    char             tab_char1[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXxXXXXXXXXXXXXXXXXXXXXXXXX";

    test_all(tab_int, 20 , -7, 12, 25, 99);
    test_all(tab_char, 55, ' ', 4001, '"', 890);
    test_all(tab_char1, 54, 'X', 20, 'x', 12);
    test_all(tab_db, 23, 12.89, 840, 72.2, 3);
    test_all(tab_str, 10, str7, 41, str8, 12);

    return (0);
}