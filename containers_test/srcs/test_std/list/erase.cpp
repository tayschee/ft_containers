#include <list>
#include <vector>
#include <iostream>
#include <string>

struct a
{
    int a;
};

template <typename T>
void    test(std::list<T>  &list, typename std::list<T>::iterator old_it)
{
    size_t i;
    try
    {
        for (i = 0; i < list.size(); i++)
        {
            std::cout << *old_it++ << " ";
        }
        std::cout << "\n";
        for (i = 0; i < list.size(); i++)
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
void    test(std::list<T *>  &list, typename std::list<T>::iterator old_it)
{
    size_t i;
    size_t j;
    try
    {
        for (i = 0; i < list.size(); i++)
        {
            for (j = 0; (*old_it)[j] != 0; j++)
                std::cout << (*old_it)[j];
            std::cout << " ";
            old_it++;
        }
        std::cout << "\n";
        for (i = 0; i < list.size(); i++)
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
void            test_func(std::list<T> &lst, int pos)
{
    typename std::list<T>::iterator it(lst.begin());
    typename std::list<T>::iterator old_it(lst.begin());

    while (pos)
    {
        --pos;
        it++;
    }

    if (pos == 0)
        old_it = lst.erase(it);
    else
        std::cout << *lst.erase(it) << "\n";
    test(lst, old_it);
}

template <typename T>
void            test_func(std::list<T> &lst, int beg, int end)
{
    typename std::list<T>::iterator it_beg(lst.begin());
    typename std::list<T>::iterator it_end(lst.end());
    while (beg)
    {
        --beg;
        ++it_beg;
    }
    while (end)
    {
        --end;
        ++it_end;
    }
    lst.erase(beg, end);


    test(lst);
}

template <typename T>
std::list<T>        create(T *tab, int size)
{
    typename std::vector<T>::iterator beg(tab);
    typename std::vector<T>::iterator end(&tab[size]);
    std::list<T>     lst(beg, end);

    return (lst);
}

/*template <typename T>
std::list<T>        create(int size, const T &val, const T &val2)
{
    std::list<T>     lst(size, val);

    lst.push_back(val2);
    return (lst);
}*/

template<typename T>
void    test_all(T *tab, int size, int pos)
{
    int i = 0;
    std::list<T> lst(create(tab, size));

    while (i < lst.size())
    {
        if (pos < lst.size())
            test_func(lst, pos);
        else
        {
            test_func(lst, lst.size() - 1);
        }
    }
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
    std::string     tab_str[] = {str1, str2, str3, str4, str5, str6, str7, str8, str9, str10};
    int             tab_int[] = {12, 36, 94, -121, 858, 327, 451, 32, 43, 44, 99, -1002, 255, 808, 218, 441, 90, -5, -12, 244};
    double          tab_db[] = {12, 36, 94, -121, 44, 327, 451, 32, 1, 43, 44, 99, -1002, 255, 808, 218, 
                                441.12, 90, -5, -12, 244, -98.7, -99.2};
    char             tab_char[] = "abcedfghijklmnopqrstuvwxyzon omatopee yataa tatakae tatakae tourte";

    //std::cout << "a\n";
    test_all(tab_int, 20 , 7);
    test_all(tab_char, 55, 42);
    test_all(tab_db, 23, 37);
    test_all(tab_str, 10, 3);

    test_all(tab_int, 18 , 0);
    test_all(tab_str, 7, 0);



    return (0);
}
