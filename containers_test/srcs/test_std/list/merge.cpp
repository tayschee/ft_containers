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
    return (value1 == value2);
}

template<>
int     func3<std::string>(std::string value1, std::string value2)
{
    return (value1.size() < value2.size());
}

template<typename T>
int     func4(T value1, T value2)
{
    return (value1 < value2);
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
void            test_func(std::list<T> lst, std::list<T> lst2, int (*func)(T, T))
{
    typename std::list<T>::iterator old_it(lst.begin());

   
    lst.merge(lst2, func);
    if (lst.begin() != old_it)
        old_it = lst.begin();
    test(lst, old_it, lst.size());
}

template <typename T>
void            test_func(std::list<T> lst, std::list<T> lst2)
{
    typename std::list<T>::iterator old_it(lst.begin());

    lst.merge(lst2);
    if (lst.begin() != old_it)
        old_it = lst.begin();
    test(lst, old_it, lst.size());
    test(lst2, lst2.begin(), lst2.size());
    
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
void    test_all(T *tab, size_t size, T *tab1, size_t size1, T val2, size_t size2, T val3, size_t size3)
{
    size_t  i = 0;
    int (*func[])(T, T) = {func1, func2, func3, func4};
    std::list<T> lst(create(tab, size));
    std::list<T> lst1(create(tab1, size1));
    std::list<T> lst2(size2, val2);
    std::list<T> lst3;
    std::list<T> lst4(size3, val3);

    test_func(lst, lst);
    test_func(lst1, lst1);
    test_func(lst2, lst2);
    test_func(lst3, lst3);
    test_func(lst4, lst4);

    test_func(lst, lst1);
    test_func(lst1, lst);
    test_func(lst, lst2);
    test_func(lst2, lst);
    test_func(lst, lst3);
    test_func(lst3, lst);
    test_func(lst, lst4);
    test_func(lst4, lst);

    test_func(lst1, lst2);
    test_func(lst2, lst1);
    test_func(lst1, lst3);
    test_func(lst3, lst1);

    test_func(lst1, lst4);
    test_func(lst4, lst1);

    test_func(lst2, lst3);
    test_func(lst3, lst2);
    test_func(lst2, lst4);
    test_func(lst4, lst2);

    test_func(lst3, lst4);
    test_func(lst4, lst3);

    while (i < 4)
    {
        test_func(lst, lst, func[i]);
        test_func(lst1, lst1, func[i]);
        test_func(lst2, lst2, func[i]);
        test_func(lst3, lst3, func[i]);
        test_func(lst4, lst4, func[i]);

        test_func(lst, lst1, func[i]);
        test_func(lst1, lst, func[i]);
        test_func(lst, lst2, func[i]);
        test_func(lst2, lst, func[i]);
        test_func(lst, lst3, func[i]);
        test_func(lst3, lst, func[i]);
        test_func(lst, lst4, func[i]);
        test_func(lst4, lst, func[i]);

        test_func(lst1, lst2, func[i]);
        test_func(lst2, lst1, func[i]);
        test_func(lst1, lst3, func[i]);
        test_func(lst3, lst1, func[i]);

        test_func(lst1, lst4, func[i]);
        test_func(lst4, lst1, func[i]);

        test_func(lst2, lst3, func[i]);
        test_func(lst3, lst2, func[i]);
        test_func(lst2, lst4, func[i]);
        test_func(lst4, lst2, func[i]);

        test_func(lst3, lst4, func[i]);
        test_func(lst4, lst3, func[i]);
        ++i;
    }
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
    std::string     tab_str1[] = {str1, str2, str3, str4, str5, str6, str7, str8, str9, str10, str7};
    int             tab_int[] = {0, 0, 0, 0, 12, 34, 99, 258, 494, 8006};
    int             tab_int1[] = {0, 21, 37, 48, 99, 205, 253, 412 ,442, 803, 851, 8009};
    double          tab_db[] = {12.94, 488.17, 1442.21, 901.12};
    double          tab_db1[] = {12.94, 488.17, 1442.21, 901.12};
    char             tab_char[] = "ABCDEFGHIJKLMOPQRSTUVWXYZ";
    char             tab_char1[] = "AEIOUY";

    //std::cout << "a\n";
    test_all(tab_int, 10, tab_int1, 12, -15, 24, 8008, 3);
    test_all(tab_char, 26, tab_char1, 7, 'a', 46, '?', 812);
    test_all(tab_db, 4, tab_db1, 4, 47.14, 201, 508.18, 2);
    test_all(tab_str, 12, tab_str1, 11, static_cast<std::string>("ouip"), 7, static_cast<std::string>("o"), 54);

    return (0);
}