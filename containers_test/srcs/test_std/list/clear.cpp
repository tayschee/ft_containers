#include <list>
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

void    test(std::list<struct a>  &list)
{
    size_t i;
    try
    {
        std::list<struct a>::iterator it(list.begin());
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
void            test_func(std::list<T> lst)
{
    lst.clear();

    test(lst);
}

template <typename T>
std::list<T>        create(int size, const T &val)
{
    std::list<T>     lst(size, val);

    return (lst);
}

template <typename T>
std::list<T>        create(int size, const T &val, const T &val2)
{
    std::list<T>     lst(size, val);

    lst.push_back(val2);
    return (lst);
}

template<typename T>
void    test_all(const T &val, const T &val2, int x, int x2)
{
    int i = 0;

    while (i < 20)
    {
        test_func(create(i, val));
        test_func(create(i, val, val2));
        i++;
    }
    while (x < x2)
    {
        test_func(create(x, val));
        test_func(create(x, val, val2));
        x++;
    } 
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

    //std::cout << "a\n";
    test_all(96, 69, 1005, 1040);
    test_all('j', 'e', 555, 607);
    test_all(db1, db2, 212, 321);
    test_all(str1, str2, 42, 48);
    test_all(static_cast<char *>(tab_char1), static_cast<char *>(tab_char2), 27, 33);
    test_all(static_cast<int *>(tab_int1), static_cast<int *>(tab_int2), 18, 30);


    return (0);
}