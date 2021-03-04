#include <iostream>
#include "map.hpp"
#include "vector.hpp"
#include <typeinfo>

template <typename T>
struct      useless
{
    int     a;
    int     b;
    int     c;
    int     d;
    int     e;
    int     f;

    bool    operator()(const T &x, const T& y) const { return (x < y); }
};

template <typename T>
struct      more
{
    bool    operator()(const T &x, const T& y) const { return (x > y); }
};

template <typename T>
struct      to_int
{
    bool    operator()(const  T &x, const T &y) const { return (static_cast<int>(x) < static_cast<int>(y)); }
};

struct      string_size     
{
    bool    operator()(const std::string &x, const std::string & y) const { return (x.size() < y.size()); }
};

template <typename K, typename T, typename C >
void    test(ft::map<K, T, C> &map)
{
    try
    {
        typename ft::map<K, T, C>::iterator it(map.begin());

        while (it != map.end())
        {
            std::cout << it->first << " : " << it->second << ", ";
            ++it;
        }
        std::cout << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << map.max_size() << " ";
    std::cout << map.size() << " ";
    std::cout << map.empty() << " ";
    std::cout << (typeid(C) ==  typeid(map.key_comp())) << " ";
    if (map.size())
    {
        std::cout << (*map.begin()).first << " ";
        std::cout << (*--map.end()).first << " ";
        std::cout << (*map.rbegin()).first << " ";
        std::cout << (*--map.rend()).first << " ";
    }
    else
    {
        std::cout << (map.begin() == map.end()) << "\n";
        map.rbegin();
        map.rend();
    }
    std::cout << "\n";
    
}

template <typename K, typename T, typename C>
ft::map<K, T, C>    create()
{
    return(ft::map<K, T, C>());
}

template <typename K, typename T, typename C>
ft::map<K, T, C>    create(const ft::map<K, T, C> &map)
{
    return(ft::map<K, T, C>(map));
}

template <typename K, typename T, typename C>
ft::map<K, T, C>    create(ft::pair<K, T> *tab, size_t size)
{
    typename ft::vector<ft::pair<K, T> >::iterator beg(tab);
    typename ft::vector<ft::pair<K, T> >::iterator end(tab + size);

    return(ft::map<K, T, C>(beg, end));
}

template <typename K, typename T, typename C >
void    test_all(ft::pair<K, T> *tab1, size_t size1, ft::pair<K, T> *tab2, size_t size2, ft::pair<K, T> *tab3, size_t size3)
{
    size_t i = 0;
    size_t j = 0;
    ft::map<K, T, C> cpy1(tab1, tab1 + size1);
    ft::map<K, T, C> cpy2(tab2, tab2 + size2);
    ft::map<K, T, C> cpy3(tab3, tab3 + size3);
    ft::map<K, T, C> empty;

    ft::map<K, T, C> tab[] = {cpy1, cpy2, cpy3, empty};

    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            tab[i].swap(tab[j]);
            test(tab[i]);
            test(tab[j]);
            ++j;
        }
        ++i;
    }

}

int main()
{
    ft::pair<int, int>    tabii1[1025];
    ft::pair<int, int>    tabii2[1025];
    ft::pair<int, int>    tabii3[108];

    ft::pair<double, unsigned int>   tabdu1[101];
    ft::pair<double, unsigned int>   tabdu2[101];
    ft::pair<double, unsigned int>   tabdu3[418];
    

    ft::pair<std::string, char> sc1("salut1234", 'o'), sc2("salut1234", 'o'), sc3("autre chose", '8'), sc4("absurde", '1'),
                                sc5("yes", '|'), sc6("opium", 'q'), sc7("re", '-'), sc8("pure", 'p'), sc9(":::", ':'),
                                sc10(":::", ':'), sc11("|||", 'p'), sc12("{", '{'), sc13("{}", ']');
    ft::pair<std::string, char> tabsc1[] = {sc1, sc2, sc3, sc4, sc5, sc6, sc7, sc8, sc9, sc10, sc11};
    ft::pair<std::string, char> tabsc2[] = {sc3, sc2, sc1, sc9, sc6, sc4, sc10, sc11, sc8, sc9, sc11};
    ft::pair<std::string, char> tabsc3[] = {sc12, sc13, sc1};

    ft::pair<char, double>      cd1('a', 1.1), cd2('j', 2.2), cd3('f', 3.3), cd4('q', 4.4), cd5('g', 99.9), cd6('0', -42.8);
    ft::pair<char, double>   tabcd1[] = {cd1, cd2, cd3};
    ft::pair<char, double>   tabcd2[] = {cd2, cd3, cd1};
    ft::pair<char, double>   tabcd3[] = {cd2, cd3, cd1, cd4, cd5, cd6};
    size_t  i = 0;

    while(i < 1025)
    {
        if (i < 101)
            tabdu1[i] = ft::pair<double, unsigned int>(i * 2.2, i + 99);
        tabii1[i] = ft::pair<int, int>(i, i);
        if (i % 4 == 0)
        {
            if (i < 101)
                tabdu2[i] = ft::pair<double, unsigned int>(i * -2.2, i + 99);
            if (i < 108)
                tabii3[i] = ft::pair<int, int>(i * 12, i);
            if (i < 418)
                tabii3[i] = ft::pair<double, unsigned int>(i - 55, i);
            tabii2[i] = ft::pair<int, int>(i * 25, i);
        }
        if (i % 5 == 0)
        {
            if (i < 101)
                tabdu2[i] = ft::pair<double, unsigned int>(i * 18.2, i + 99);
            if (i < 108)
                tabii3[i] = ft::pair<int, int>(i * -2, i);
            if (i < 418)
                tabii3[i] = ft::pair<double, unsigned int>(i * 3, i);
            tabii2[i] = ft::pair<int, int>(i * -4, i);
        }
        if (i % 3 == 0)
        {
            if (i < 101)
                tabdu2[i] = ft::pair<double, unsigned int>(i * 1, i + 99);
            if (i < 108)
                tabii3[i] = ft::pair<int, int>(i + 55, i);
            if (i < 418)
                tabii3[i] = ft::pair<double, unsigned int>(i * 2, i);
            tabii2[i] = ft::pair<int, int>(i * 1, i);
        }
        else
        {
            if (i < 101)
                tabdu2[i] = ft::pair<double, unsigned int>(i + 7, i + 99);
            if (i < 108)
                tabii3[i] = ft::pair<int, int>(i + 24, i);
            if (i < 418)
                tabii3[i] = ft::pair<double, unsigned int>(i + 45, i);
            tabii2[i] = ft::pair<int, int>(i + 25, i);
        }
        ++i;
    }

    test_all<int, int, std::less<int> >(tabii1, 1025, tabii2, 1025, tabii3, 108);
    test_all<double, unsigned int, std::less<unsigned int> >(tabdu1, 101, tabdu2, 101, tabdu3, 418);
    test_all<std::string, char, std::less<std::string> >(tabsc1, 11, tabsc2, 11, tabsc3, 3);
    test_all<char, double, std::less<char> >(tabcd1, 3, tabcd2, 3, tabcd3, 6);

    test_all<int, int, more<int> >(tabii1, 1025, tabii2, 1025, tabii3, 108);
    test_all<double, unsigned int, more<unsigned int> >(tabdu1, 101, tabdu2, 101, tabdu3, 418);
    test_all<std::string, char, more<std::string> >(tabsc1, 11, tabsc2, 11, tabsc3, 3);
    test_all<char, double, more<char> >(tabcd1, 3, tabcd2, 3, tabcd3, 6);

    test_all<int, int, to_int<int> >(tabii1, 1025, tabii2, 1025, tabii3, 108);
    test_all<double, unsigned int, to_int<unsigned int> >(tabdu1, 101, tabdu2, 101, tabdu3, 418);
    test_all<std::string, char, string_size >(tabsc1, 11, tabsc2, 11, tabsc3, 3);
    test_all<char, double, to_int<char> >(tabcd1, 3, tabcd2, 3, tabcd3, 6);

    test_all<int, int, useless<int> >(tabii1, 1025, tabii2, 1025, tabii3, 108);
    test_all<double, unsigned int, useless<unsigned int> >(tabdu1, 101, tabdu2, 101, tabdu3, 418);
    test_all<std::string, char, useless<std::string> >(tabsc1, 11, tabsc2, 11, tabsc3, 3);
    test_all<char, double, useless<char> >(tabcd1, 3, tabcd2, 3, tabcd3, 6);

    return (0);
}