#include <iostream>
#include <map>
#include <vector>
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
void    test(std::map<K, T, C> &map)
{
    try
    {
        typename std::map<K, T, C>::iterator it(map.begin());

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

template <typename K, typename T, typename C >
void    test(const std::map<K, T, C> &map)
{
    try
    {
        typename std::map<K, T, C>::const_iterator it(map.begin());

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
std::map<K, T, C>    create()
{
    return(std::map<K, T, C>());
}

template <typename K, typename T, typename C>
std::map<K, T, C>    create(const std::map<K, T, C> &map)
{
    return(std::map<K, T, C>(map));
}

template <typename K, typename T, typename C>
std::map<K, T, C>    create(std::pair<K, T> *tab, size_t size)
{
    typename std::vector<std::pair<K, T> >::iterator beg(tab);
    typename std::vector<std::pair<K, T> >::iterator end(tab + size);

    return(std::map<K, T, C>(beg, end));
}

template <typename K, typename T, typename C >
void    test_all(std::pair<K, T> *tab1, size_t size1)
{
    size_t i = 0;
    typename std::pair<typename std::map<K, T, C>::iterator, bool> p;
    std::map<K, T, C> cpy;

    while(i < size1)
    {
        p = cpy.insert(tab1[i]);
        std::cout << p.first->first << " " << p.first->second << " " << p.second << "\n";
        test(cpy);

        p = cpy.insert(tab1[i]);
        std::cout << p.first->first << " " << p.first->second << " " << p.second << "\n";
        test(cpy);
        ++i;
    }
}

template <typename K, typename T, typename C >
void    test_all1(std::pair<K, T> *tab1, size_t size1)
{
    size_t i = 0;
    typename std::map<K, T, C>::iterator p;
    std::map<K, T, C> cpy;

    cpy.insert(tab1, tab1 + size1);
    test(cpy);

    cpy.insert(tab1, tab1);
    test(cpy);

    cpy.clear();
    cpy.insert(cpy.end(), cpy.end());
    test(cpy);

    cpy.clear();
    cpy.insert(tab1, tab1 + size1 / 2);
    test(cpy);
    cpy.insert(tab1 + size1 / 2, tab1 + size1);
    test(cpy);

    cpy.clear();
    while(i < size1)
    {
        cpy.insert(&tab1[i], &tab1[i + 1]);

        test(cpy);
        ++i;
    }

    i = 0;
    while(i < size1)
    {
        cpy.insert(&tab1[i], &tab1[i + 4 < size1 ? i + 4 : size1]);
        test(cpy);
        i += 4;
    }
}

template <typename K, typename T, typename C >
void    test_all2(std::pair<K, T> *tab1, size_t size1, size_t pos_it)
{
    size_t i = 0;
    typename std::map<K, T, C>::iterator p;
    typename std::map<K, T, C>::iterator it;
    std::map<K, T, C> cpy;

    while(i < size1)
    {
        p = cpy.insert(cpy.begin(), tab1[i]);
        std::cout << p->first << " " << p->second << "\n";
        test(cpy);
        p = cpy.insert(cpy.begin(), tab1[i]);
        std::cout << p->first << " " << p->second << "\n";
        test(cpy);
        ++i;
    }
    cpy.clear();
    i = 0;
    while(i < size1)
    {
        p = cpy.insert(cpy.end(), tab1[i]);
        std::cout << p->first << " " << p->second << "\n";
        test(cpy);
        p = cpy.insert(cpy.end(), tab1[i]);
        std::cout << p->first << " " << p->second << "\n";
        test(cpy);
        ++i;
    }
    i = 0;
    it = cpy.begin();
    while(i < pos_it)
    {
        ++it;
        ++i;
    }
    i = 0;
    while(i < size1)
    {
        p = cpy.insert(it, tab1[i]);
        //if(p != cpy.end())
        std::cout << p->first << " " << p->second << "\n";
        test(cpy);
        ++i;
    }

    i = 0;
    cpy.clear();
    p = cpy.begin();
    while(i < pos_it)
    {
        p = cpy.insert(p, tab1[i]);
        std::cout << p->first << " " << p->second << "\n";
        test(cpy);
        p = cpy.insert(p, tab1[i]);
        std::cout << p->first << " " << p->second << "\n";
        test(cpy);
        ++i;
    }
    it = cpy.begin();
    i = 0;
    while (i < pos_it) 
    {
        ++i;
        ++it;
    }
    while(i < size1)
    {
        p = cpy.insert(it, tab1[i]);
        std::cout << p->first << " " << p->second << "\n";
        test(cpy);
        p = cpy.insert(it, tab1[i]);
        std::cout << p->first << " " << p->second << "\n";
        test(cpy);
        ++i;
    }
}

int main()
{
    std::pair<int, int>    tabii1[1025];
    std::pair<double, unsigned int>   tabdu1[101];
    std::pair<int, int>    tabii2[1025];
    std::pair<double, unsigned int>   tabdu2[101];

    std::pair<std::string, char> sc1("salut1234", 'o'), sc2("salut1234", 'o'), sc3("autre chose", '8'), sc4("absurde", '1'),
                                sc5("yes", '|'), sc6("opium", 'q'), sc7("re", '-'), sc8("pure", 'p'), sc9(":::", ':'),
                                sc10(":::", ':'), sc11("|||", 'p');
    std::pair<std::string, char> tabsc1[] = {sc1, sc2, sc3, sc4, sc5, sc6, sc7, sc8, sc9, sc10, sc11};
    std::pair<std::string, char> tabsc2[] = {sc3, sc2, sc1, sc9, sc6, sc4, sc10, sc11, sc8, sc9, sc11};

    std::pair<char, double>      cd1('a', 1.1), cd2('j', 2.2), cd3('f', 3.3);
    std::pair<char, double>   tabcd1[] = {cd1, cd2, cd3};
    std::pair<char, double>   tabcd2[] = {cd2, cd3, cd1};
    size_t  i = 0;

    while(i < 1025)
    {
        if (i < 101)
            tabdu1[i] = std::pair<double, unsigned int>(i * 2.2, i + 99);
        tabii1[i] = std::pair<int, int>(i, i);
        if (i % 4 == 0)
        {
            if (i < 101)
                tabdu2[i] = std::pair<double, unsigned int>(i * -2.2, i + 99);
            tabii2[i] = std::pair<int, int>(i * 25, i);
        }
        if (i % 5 == 0)
        {
            if (i < 101)
                tabdu2[i] = std::pair<double, unsigned int>(i * 18.2, i + 99);
            tabii2[i] = std::pair<int, int>(i * -4, i);
        }
        if (i % 3 == 0)
        {
            if (i < 101)
                tabdu2[i] = std::pair<double, unsigned int>(i * 1, i + 99);
            tabii2[i] = std::pair<int, int>(i * 1, i);
        }
        else
        {
            if (i < 101)
                tabdu2[i] = std::pair<double, unsigned int>(i + 7, i + 99);
            tabii2[i] = std::pair<int, int>(i + 25, i);
        }
        ++i;
    }

    test_all<int, int, std::less<int> >(tabii1, 1025);
    test_all<int, int, std::less<int> >(tabii2, 1025);
    test_all<double, unsigned int, std::less<unsigned int> >(tabdu1, 101);
    test_all<double, unsigned int, std::less<unsigned int> >(tabdu2, 101);
    test_all<std::string, char, std::less<std::string> >(tabsc1, 11);
    test_all<std::string, char, std::less<std::string> >(tabsc2, 11);
    test_all<char, double, std::less<char> >(tabcd1, 3);
    test_all<char, double, std::less<char> >(tabcd2, 3);

    test_all<int, int, more<int> >(tabii1, 1025);
    test_all<int, int, more<int> >(tabii2, 1025);
    test_all<double, unsigned int, more<unsigned int> >(tabdu1, 101);
    test_all<double, unsigned int, more<unsigned int> >(tabdu2, 101);
    test_all<std::string, char, more<std::string> >(tabsc1, 11);
    test_all<std::string, char, more<std::string> >(tabsc2, 11);
    test_all<char, double, more<char> >(tabcd1, 3);
    test_all<char, double, more<char> >(tabcd2, 3);

    test_all<int, int, to_int<int> >(tabii1, 1025);
    test_all<int, int, to_int<int> >(tabii2, 1025);
    test_all<double, unsigned int, to_int<unsigned int> >(tabdu1, 101);
    test_all<double, unsigned int, to_int<unsigned int> >(tabdu2, 101);
    test_all<std::string, char, string_size >(tabsc1, 11);
    test_all<std::string, char, string_size >(tabsc2, 11);
    test_all<char, double, to_int<char> >(tabcd1, 3);
    test_all<char, double, to_int<char> >(tabcd2, 3);

    test_all<int, int, useless<int> >(tabii1, 1025);
    test_all<int, int, useless<int> >(tabii2, 1025);
    test_all<double, unsigned int, useless<unsigned int> >(tabdu1, 101);
    test_all<double, unsigned int, useless<unsigned int> >(tabdu2, 101);
    test_all<std::string, char, useless<std::string> >(tabsc1, 11);
    test_all<std::string, char, useless<std::string> >(tabsc2, 11);
    test_all<char, double, useless<char> >(tabcd1, 3);
    test_all<char, double, useless<char> >(tabcd2, 3);

    //test2
    test_all1<int, int, std::less<int> >(tabii1, 1025);
    test_all1<int, int, std::less<int> >(tabii2, 1025);
    test_all1<double, unsigned int, std::less<unsigned int> >(tabdu1, 101);
    test_all1<double, unsigned int, std::less<unsigned int> >(tabdu2, 101);
    test_all1<std::string, char, std::less<std::string> >(tabsc1, 11);
    test_all1<std::string, char, std::less<std::string> >(tabsc2, 11);
    test_all1<char, double, std::less<char> >(tabcd1, 3);
    test_all1<char, double, std::less<char> >(tabcd2, 3);

    test_all1<int, int, more<int> >(tabii1, 1025);
    test_all1<int, int, more<int> >(tabii2, 1025);
    test_all1<double, unsigned int, more<unsigned int> >(tabdu1, 101);
    test_all1<double, unsigned int, more<unsigned int> >(tabdu2, 101);
    test_all1<std::string, char, more<std::string> >(tabsc1, 11);
    test_all1<std::string, char, more<std::string> >(tabsc2, 11);
    test_all1<char, double, more<char> >(tabcd1, 3);
    test_all1<char, double, more<char> >(tabcd2, 3);

    test_all1<int, int, to_int<int> >(tabii1, 1025);
    test_all1<int, int, to_int<int> >(tabii2, 1025);
    test_all1<double, unsigned int, to_int<unsigned int> >(tabdu1, 101);
    test_all1<double, unsigned int, to_int<unsigned int> >(tabdu2, 101);
    test_all1<std::string, char, string_size >(tabsc1, 11);
    test_all1<std::string, char, string_size >(tabsc2, 11);
    test_all1<char, double, to_int<char> >(tabcd1, 3);
    test_all1<char, double, to_int<char> >(tabcd2, 3);

    test_all1<int, int, useless<int> >(tabii1, 1025);
    test_all1<int, int, useless<int> >(tabii2, 1025);
    test_all1<double, unsigned int, useless<unsigned int> >(tabdu1, 101);
    test_all1<double, unsigned int, useless<unsigned int> >(tabdu2, 101);
    test_all1<std::string, char, useless<std::string> >(tabsc1, 11);
    test_all1<std::string, char, useless<std::string> >(tabsc2, 11);
    test_all1<char, double, useless<char> >(tabcd1, 3);
    test_all1<char, double, useless<char> >(tabcd2, 3);

    //test3
    test_all2<int, int, std::less<int> >(tabii1, 1025, 127);
    test_all2<int, int, std::less<int> >(tabii2, 1025, 302);
    test_all2<double, unsigned int, std::less<unsigned int> >(tabdu1, 101, 12);
    test_all2<double, unsigned int, std::less<unsigned int> >(tabdu2, 101, 13);
    test_all2<std::string, char, std::less<std::string> >(tabsc1, 11, 3);
    test_all2<std::string, char, std::less<std::string> >(tabsc2, 11, 4);
    test_all2<char, double, std::less<char> >(tabcd1, 3, 1);
    test_all2<char, double, std::less<char> >(tabcd2, 3, 2);

    test_all2<int, int, more<int> >(tabii1, 1025, 441);
    test_all2<int, int, more<int> >(tabii2, 1025, 811);
    test_all2<double, unsigned int, more<unsigned int> >(tabdu1, 101, 90);
    test_all2<double, unsigned int, more<unsigned int> >(tabdu2, 101, 19);
    test_all2<std::string, char, more<std::string> >(tabsc1, 11, 8);
    test_all2<std::string, char, more<std::string> >(tabsc2, 11, 6);
    test_all2<char, double, more<char> >(tabcd1, 3, 2);
    test_all2<char, double, more<char> >(tabcd2, 3, 1);

    test_all2<int, int, to_int<int> >(tabii1, 1025, 113);
    test_all2<int, int, to_int<int> >(tabii2, 1025, 441);
    test_all2<double, unsigned int, to_int<unsigned int> >(tabdu1, 101, 91);
    test_all2<double, unsigned int, to_int<unsigned int> >(tabdu2, 101, 52);
    test_all2<std::string, char, string_size >(tabsc1, 11, 10);
    test_all2<std::string, char, string_size >(tabsc2, 11, 9);
    test_all2<char, double, to_int<char> >(tabcd1, 3, 2);
    test_all2<char, double, to_int<char> >(tabcd2, 3, 3);

    test_all2<int, int, useless<int> >(tabii1, 1025, 1000);
    test_all2<int, int, useless<int> >(tabii2, 1025, 1023);
    test_all2<double, unsigned int, useless<unsigned int> >(tabdu1, 101, 37);
    test_all2<double, unsigned int, useless<unsigned int> >(tabdu2, 101, 21);
    test_all2<std::string, char, useless<std::string> >(tabsc1, 11, 5);
    test_all2<std::string, char, useless<std::string> >(tabsc2, 11, 6);
    test_all2<char, double, useless<char> >(tabcd1, 3, 3);
    test_all2<char, double, useless<char> >(tabcd2, 3, 2);


    return (0);
}