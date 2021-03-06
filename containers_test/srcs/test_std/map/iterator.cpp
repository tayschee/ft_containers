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
void    cmp(typename std::map<K, T, C>::iterator it1, typename std::map<K, T, C>::iterator it2)
{
    std::cout << (it1 == it1) << " ";
    std::cout << (it1 != it1) << " ";
    std::cout << (it2 == it2) << " ";
    std::cout << (it2 != it2) << " ";
    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << "\n";
}

template <typename K, typename T, typename C >
void    cmp(typename std::map<K, T, C>::iterator it1, typename std::map<K, T, C>::const_iterator it2)
{
    std::cout << (it1 == it1) << " ";
    std::cout << (it1 != it1) << " ";
    std::cout << (it2 == it2) << " ";
    std::cout << (it2 != it2) << " ";
    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << "\n";
}

template <typename K, typename T, typename C >
void    cmp(typename std::map<K, T, C>::const_iterator it1, typename std::map<K, T, C>::const_iterator it2)
{
    std::cout << (it1 == it1) << " ";
    std::cout << (it1 != it1) << " ";
    std::cout << (it2 == it2) << " ";
    std::cout << (it2 != it2) << " ";
    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << "\n";
}

template <typename K, typename T, typename C >
void    cmp(typename std::map<K, T, C>::reverse_iterator it1, typename std::map<K, T, C>::reverse_iterator it2)
{
    std::cout << (it1 == it1) << " ";
    std::cout << (it1 != it1) << " ";
    std::cout << (it2 == it2) << " ";
    std::cout << (it2 != it2) << " ";
    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << "\n";
}

template <typename K, typename T, typename C >
void    cmp(typename std::map<K, T, C>::reverse_iterator it1, typename std::map<K, T, C>::const_reverse_iterator it2)
{
    std::cout << (it1 == it1) << " ";
    std::cout << (it1 != it1) << " ";
    std::cout << (it2 == it2) << " ";
    std::cout << (it2 != it2) << " ";
    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << "\n";
}

template <typename K, typename T, typename C >
void    cmp(typename std::map<K, T, C>::const_reverse_iterator it1, typename std::map<K, T, C>::const_reverse_iterator it2)
{
    std::cout << (it1 == it1) << " ";
    std::cout << (it1 != it1) << " ";
    std::cout << (it2 == it2) << " ";
    std::cout << (it2 != it2) << " ";
    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << "\n";
}

template <typename K, typename T, typename C >
void    inc(typename std::map<K, T, C>::iterator beg, typename std::map<K, T, C>::iterator end)
{
    while (beg != end)
    {
        std::cout << (*beg++).first << " ";
    }
    std::cout << "\n";
    end--;
    beg++;
    while (beg != end)
    {
        std::cout << (*++beg).first << " ";
    }
    std::cout << "\n";
    end++;
    while (beg != end)
    {
        std::cout << (*beg--).first << " ";
    }
    std::cout << "\n";
    beg--;
    end--;
    while (beg != end)
    {
        std::cout << (*--beg).first << " ";
    }
}

template <typename K, typename T, typename C >
void    inc(typename std::map<K, T, C>::const_iterator beg, typename std::map<K, T, C>::const_iterator end)
{
    while (beg != end)
    {
        std::cout << (*beg++).first << " ";
    }
    std::cout << "\n";
    end--;
    beg++;
    while (beg != end)
    {
        std::cout << (*++beg).first << " ";
    }
    std::cout << "\n";
    end++;
    while (beg != end)
    {
        std::cout << (*beg--).first << " ";
    }
    std::cout << "\n";
    beg--;
    end--;
    while (beg != end)
    {
        std::cout << (*--beg).first << " ";
    }
}

template <typename K, typename T, typename C >
void    inc(typename std::map<K, T, C>::reverse_iterator beg, typename std::map<K, T, C>::reverse_iterator end)
{
    while (beg != end)
    {
        std::cout << (*beg--).first << " ";
    }
    std::cout << "\n";
    end++;
    beg--;
    while (beg != end)
    {
        std::cout << (*--beg).first << " ";
    }
    std::cout << "\n";
    end--;
    while (beg != end)
    {
        std::cout << (*beg++).first << " ";
    }
    std::cout << "\n";
    beg++;
    end++;
    while (beg != end)
    {
        std::cout << (*++beg).first << " ";
    }
}

template <typename K, typename T, typename C >
void    inc(typename std::map<K, T, C>::const_reverse_iterator beg, typename std::map<K, T, C>::const_reverse_iterator end)
{
    while (beg != end)
    {
        std::cout << (*beg--).first << " ";
    }
    std::cout << "\n";
    end++;
    beg--;
    while (beg != end)
    {
        std::cout << (*--beg).first << " ";
    }
    std::cout << "\n";
    end--;
    while (beg != end)
    {
        std::cout << (*beg++).first << " ";
    }
    std::cout << "\n";
    beg++;
    end++;
    while (beg != end)
    {
        std::cout << (*++beg).first << " ";
    }
}

template <typename K, typename T, typename C >
void    test_all(std::pair<K, T> *tab1, size_t size1, std::pair<K, T> *tab2, size_t size2, std::pair<K, T> *tab3, size_t size3)
{
    std::map<K, T, C>    map1(tab1, tab1 + size1);
    std::map<K, T, C>    map2(tab2, tab2 + size2);
    std::map<K, T, C>    map3(tab3, tab3 + size3);
    const std::map<K, T, C>    cmap1(tab1, tab1 + size1);
    const std::map<K, T, C>    cmap2(tab2, tab2 + size2);
    const std::map<K, T, C>    cmap3(tab3, tab3 + size3);

    std::map<K, T, C>            tab[] = {map1, map2, map3};
    const std::map<K, T, C>      ctab[] = {cmap1, cmap2, cmap3};

    size_t i = 0;
    size_t j = 0;

    while (i < 3)
    {
        inc<K, T, C>(tab[i].begin(), tab[i].end());
        inc<K, T, C>(ctab[i].begin(), ctab[i].end());

        inc<K, T, C>(tab[i].rend(), tab[i].rbegin());
        inc<K, T, C>(ctab[i].rend(), ctab[i].rbegin());
        j = 0;
        while (j < 3)
        {
            cmp<K, T, C>(tab[i].begin(), tab[j].begin());
            cmp<K, T, C>(ctab[i].begin(), ctab[j].begin());
            cmp<K, T, C>(tab[i].begin(), ctab[j].begin());

            cmp<K, T, C>(tab[i].rbegin(), tab[j].rbegin());
            cmp<K, T, C>(ctab[i].rbegin(), ctab[j].rbegin());
            cmp<K, T, C>(tab[i].rbegin(), ctab[j].rbegin());
            ++j;
        }
        ++i;
    }



}

int main()
{
    std::pair<int, int>    tabii1[1025];
    std::pair<int, int>    tabii2[1025];
    std::pair<int, int>    tabii3[108];

    std::pair<double, unsigned int>   tabdu1[101];
    std::pair<double, unsigned int>   tabdu2[101];
    std::pair<double, unsigned int>   tabdu3[418];
    

    std::pair<std::string, char> sc1("salut1234", 'o'), sc2("salut1234", 'o'), sc3("autre chose", '8'), sc4("absurde", '1'),
                                sc5("yes", '|'), sc6("opium", 'q'), sc7("re", '-'), sc8("pure", 'p'), sc9(":::", ':'),
                                sc10(":::", ':'), sc11("|||", 'p'), sc12("{", '{'), sc13("{}", ']');
    std::pair<std::string, char> tabsc1[] = {sc1, sc2, sc3, sc4, sc5, sc6, sc7, sc8, sc9, sc10, sc11};
    std::pair<std::string, char> tabsc2[] = {sc3, sc2, sc1, sc9, sc6, sc4, sc10, sc11, sc8, sc9, sc11};
    std::pair<std::string, char> tabsc3[] = {sc12, sc13, sc1};

    std::pair<char, double>      cd1('a', 1.1), cd2('j', 2.2), cd3('f', 3.3), cd4('q', 4.4), cd5('g', 99.9), cd6('0', -42.8);
    std::pair<char, double>   tabcd1[] = {cd1, cd2, cd3};
    std::pair<char, double>   tabcd2[] = {cd2, cd3, cd1};
    std::pair<char, double>   tabcd3[] = {cd2, cd3, cd1, cd4, cd5, cd6};
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
            if (i < 108)
                tabii3[i] = std::pair<int, int>(i * 12, i);
            if (i < 418)
                tabii3[i] = std::pair<double, unsigned int>(i - 55, i);
            tabii2[i] = std::pair<int, int>(i * 25, i);
        }
        if (i % 5 == 0)
        {
            if (i < 101)
                tabdu2[i] = std::pair<double, unsigned int>(i * 18.2, i + 99);
            if (i < 108)
                tabii3[i] = std::pair<int, int>(i * -2, i);
            if (i < 418)
                tabii3[i] = std::pair<double, unsigned int>(i * 3, i);
            tabii2[i] = std::pair<int, int>(i * -4, i);
        }
        if (i % 3 == 0)
        {
            if (i < 101)
                tabdu2[i] = std::pair<double, unsigned int>(i * 1, i + 99);
            if (i < 108)
                tabii3[i] = std::pair<int, int>(i + 55, i);
            if (i < 418)
                tabii3[i] = std::pair<double, unsigned int>(i * 2, i);
            tabii2[i] = std::pair<int, int>(i * 1, i);
        }
        else
        {
            if (i < 101)
                tabdu2[i] = std::pair<double, unsigned int>(i + 7, i + 99);
            if (i < 108)
                tabii3[i] = std::pair<int, int>(i + 24, i);
            if (i < 418)
                tabii3[i] = std::pair<double, unsigned int>(i + 45, i);
            tabii2[i] = std::pair<int, int>(i + 25, i);
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