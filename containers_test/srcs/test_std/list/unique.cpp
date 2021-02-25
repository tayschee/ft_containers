#include <list>
#include <vector>
#include <iostream>
#include <string>

template<typename T>
int     func1(T value1, T value2)
{
    (void)value1;
    (void)value2;
    std::cout << "func1 pass\n";
    return (1);
}

template<typename T>
int     func2(T value1, T value2)
{
    (void)value1;
    (void)value2;
    std::cout << "func2 pass\n";
    return (0);
}

template<typename T>
int     func3(T value1, T value2)
{
    return (value1 + value2 < 30);
}

template<>
int     func3<std::string>(std::string value1, std::string value2)
{
    return (value1.size() + value2.size() < 12);
}

template<typename T>
int     func4(T value1, T value2)
{
    return (value1 == value2);
}

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
void            test_func(std::list<T> lst, int (*func)(T, T))
{
    typename std::list<T>::iterator old_it(lst.begin());

   
    lst.unique(func);
    if (lst.begin() != old_it)
        old_it = lst.begin();
    test(lst, old_it, lst.size());
}

template <typename T>
void            test_func(std::list<T> lst)
{
    typename std::list<T>::iterator old_it(lst.begin());

   
    lst.unique();
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
void    test_all(T *tab, size_t size, T val, size_t size1)
{
    std::list<T> lst(create(tab, size));
    std::list<T> lst1(size1, val);
    std::list<T> lst2(1, val);
    std::list<T> lst3;

    test_func(lst);
    test_func(lst, func1);
    test_func(lst, func2);
    test_func(lst, func3);
    test_func(lst, func4);

    test_func(lst1);
    test_func(lst1, func1);
    test_func(lst1, func2);
    test_func(lst1, func3);
    test_func(lst1, func4);

    test_func(lst2);
    test_func(lst2, func1);
    test_func(lst2, func2);
    test_func(lst2, func3);
    test_func(lst2, func4);

    test_func(lst3);
    test_func(lst3, func1);
    test_func(lst3, func2);
    test_func(lst3, func3);
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
    std::string     tab_str[] = {str1, str1, str2, str3, str4, str5, str6, str7, str8, str9, str10, str7};
    int             tab_int[] = {0, 0, 0, 0, 12, 34, 99, -15, 20, 20, 12, 27, 72, 84, 84};
    double          tab_db[] = {1022.7, 0, 94, -121, 44, 327, 451, 32, 1, 43, 44, 99, -1002, 255, 808, 218, 
                                441.12, 90, -5, -12, 244, -98.7, -99.2, 72.2, 72.2, 72.2};
    char             tab_char[] = "abcedfghijklmnopqrstuvwxyzon        omatopee yataa tatakae tatakae tourte";
    char             tab_char1[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXxXXXXXXXXXXXXXXXXXXXXXXXX";

    //std::cout << "a\n";
    test_all(tab_int, 15 , 42, 1024);
    test_all(tab_char, 74, 'J', 812);
    test_all(tab_char1, 54, '7', 301);
    test_all(tab_db, 26, 12.89, 40);
    test_all(tab_str, 12, str8, 4);

    return (0);
}