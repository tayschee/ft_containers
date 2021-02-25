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
void    test(std::list<T *>  &list, typename std::list<T *>::iterator old_it, size_t n)
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
void            test_func(std::list<T> &lst, size_t pos, T val)
{
    typename std::list<T>::iterator it_beg(lst.begin());
    typename std::list<T>::iterator old_it(lst.begin());

    while (pos)
    {
        --pos;
        ++it_beg;
    }
    if (pos == 0)
    {
        old_it = lst.insert(it_beg, val);
        std::cout << (old_it  == lst.begin()) << "\n";
        old_it = lst.begin();
    }
    else
        std::cout << *lst.insert(it_beg, val) << "\n";

    test(lst, old_it, lst.size());
}

template <typename T>
void            test_func(std::list<T> &lst, size_t pos, size_t nb, T val)
{
    typename std::list<T>::iterator it_beg(lst.begin());
    typename std::list<T>::iterator old_it(lst.begin());

    while (pos)
    {
        --pos;
        ++it_beg;
    }
    if (pos == 0)
    {
        lst.insert(it_beg, nb, val);
        old_it = lst.begin();
    }
    else
        lst.insert(it_beg, nb, val);

    test(lst, old_it, lst.size());
}

template <typename T, typename It>
void            test_func(std::list<T> &lst, size_t pos, It beg, It end)
{
    typename std::list<T>::iterator it_beg(lst.begin());
    typename std::list<T>::iterator old_it(lst.begin());

    while (pos)
    {
        --pos;
        ++it_beg;
    }
    if (pos == 0)
    {
        lst.insert(it_beg, beg, end);
        old_it = lst.begin();
    }
    else
        lst.insert(it_beg, beg, end);

    test(lst, old_it, lst.size());
}

template<typename T>
void    test_all(T *tab, size_t size, size_t pos)
{
    size_t i = 0;
    std::list<T> lst(create(tab, size));

    while (i < lst.size())
    {
        if (pos < lst.size())
        {
            test_func(lst, pos);
        }
        else
        {
            test_func(lst, lst.size() - 1);
        }
    }
    
}

template<typename T>
void    test_all(size_t size, T val, T val2, size_t pos, size_t nb)
{
    size_t i = 0;
    T       new_val;
    std::list<T> lst(size, val);

    new_val = val;
    while (i < nb)
    {
        --nb;
        test_func(lst, pos, new_val);
        if (new_val == val)
            new_val = val2;
        else    
            new_val = val;
    }
    test_func(lst, 0, new_val);
    test_func(lst, lst.size(), new_val);
}

template<typename T>
void    test_all1(size_t size, T val, T val2, size_t pos, size_t nb)
{
    size_t j = 0;
    size_t i = 0;
    T       new_val;
    std::list<T> lst(size, val);

    new_val = val;
    while (i < nb)
    {
        --nb;
        test_func(lst, pos, j, new_val);
        if (new_val == val)
            new_val = val2;
        else    
            new_val = val;
        j++;
    }
    test_func(lst, 0, 0, new_val);
    test_func(lst, 0, 1, new_val);
    test_func(lst, 0, j, new_val);
    test_func(lst, lst.size(), 0, new_val);
    test_func(lst, lst.size(), 1, new_val);
    test_func(lst, lst.size(), j, new_val);
}

template<typename T>
void    test_all2(size_t size, T *tab, size_t end, size_t pos, size_t nb, T val)
{
    size_t i = 0;
    typename std::vector<T>::iterator it_beg(tab);
    typename std::vector<T>::iterator it_end(&tab[end]);
    std::list<T> lst_it(it_beg, it_end);
    std::list<T> lst(size, val);

    while (i < nb)
    {
        --nb;
        test_func(lst, pos, lst_it.begin(), lst_it.end());
    }
    test_func(lst, 0, lst_it.begin(), lst_it.end());
    test_func(lst, 0, lst_it.begin(), lst_it.begin());
    test_func(lst, 1, lst_it.begin(), lst_it.end());
    test_func(lst, lst.size() - 1, lst_it.begin(), lst_it.end());
    test_func(lst, lst.size(), lst_it.begin(), lst_it.end());
}

int main()
{
    std::string     str1("test1");
    std::string     str2("test2");
    int             tab_int1[] = {12, 36, 94, -121, 858, 327, 451, 32, 43, 44, 99, -1002, 255, 808, 218, 441, 90, -5, -12, 244, 0};
    int             tab_int2[] = {-12, -36, -94, 121, -858, -327, -451, 0};
    char             tab_char1[] = "abcedfghijklmnopqrstuvwxyzon omatopee yataa tatakae tatakae tourte";
    char             tab_char2[] = "abefidlbfrlhefjnwhudb32ewdshub";
    double          tab_double[] = {12.3, 27.7, 499.6, 8202.12, 505.9, 412.4, 307.3, 0.6, -43.3, -901.3};
    std::string     tab_str[] = {str1, str2, str2, str2, str1};
    char            *tab_char[] = {tab_char1};

    test_all(831, 12, 63, 270, 20);
    test_all(412, 12.14, 90.43, 1, 12);
    test_all(1168, 12.14, 90.43, 1066, 5);
    test_all(56, str1, str2, 54, 10);
    test_all(23, static_cast<int *>(tab_int1), static_cast<int *>(tab_int2), 12, 3);
    test_all(12, static_cast<char *>(tab_char1), static_cast<char *>(tab_char2), 4, 7);

    test_all1(831, 12, 63, 270, 20);
    test_all1(412, 12.14, 90.43, 1, 12);
    test_all1(1168, 12.14, 90.43, 1066, 5);
    test_all1(56, str1, str2, 54, 10);
    test_all1(23, static_cast<int *>(tab_int1), static_cast<int *>(tab_int2), 12, 3);
    test_all1(12, static_cast<char *>(tab_char1), static_cast<char *>(tab_char2), 4, 7);

    test_all2(341, tab_int1, 21, 219, 3, 42);
    test_all2(891, tab_char1, 67, 2, 1, 'C');
    test_all2(1168, tab_double, 10, 401, 2, 42.42);
    test_all2(56, tab_str, 5, 37, 8, static_cast<std::string>("abc"));
    test_all2(41, static_cast<char **>(tab_char), 1, 22, 3, tab_char2);



    return (0);
}