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
void            test_cons(std::list<T> lst)
{
    typename std::list<T>::iterator beg(lst.begin());
    typename std::list<T>::iterator end(lst.end());
    std::list<T> new_lst(beg, end);

    test(new_lst);
}

template <typename T>
std::list<T>        create_list(int size, const T& value1, const T &value2, const T &value3)
{
    std::list<T>     lst(size, value1);

    lst.push_back(value2);
    lst.push_back(value3);
    lst.push_front(value3);
    lst.push_front(value2);

    return (lst);
}  

template<typename T>
void    test_all(const T &x, const T &y, const T &z, int nb)
{
    int i = 0;
    std::list<T> empty_list;

    test_cons(empty_list);
    while (i < 12)
    {
        test_cons(create_list(i, x, y, z));
        i++;
    }
    test_cons(create_list(nb, x, y, z));
}

int main()
{
    std::string     str1("test1");
    std::string     str2("test2");
    std::string     str3("test3");
    double          db1(72.27);
    double          db2(8099.61);
    double          db3(1008.7);
    int             tab_int1[] = {12, 27, 39, 255, 447, 828, 0};
    int             tab_int2[] = {-12, -27, 3-9, -255, -447, -828, 0};
    int             tab_int3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 1100, 0};
    char            tab_char1[] = "nickel";
    char            tab_char2[] = "entourloupe";
    char            tab_char3[] = "sixteen";

    test_all(12, 84, 18, 126);
    test_all('f', 'm', 'k', 1808);
    test_all(str1, str2, str3, 85);
    test_all(db1, db2, db3, 401);
    test_all(static_cast<int *>(tab_int1), static_cast<int *>(tab_int2), static_cast<int *>(tab_int3), 88);
    test_all(static_cast<char *>(tab_char1), static_cast<char *>(tab_char2), static_cast<char *>(tab_char3), 21);


    return (0);
}