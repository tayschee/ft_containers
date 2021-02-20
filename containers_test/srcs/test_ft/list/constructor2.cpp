#include "list.hpp"
#include <iostream>
#include <string>

struct a
{
    int a;
};

template <typename T>
void    test(ft::list<T>  &list)
{
    size_t i;
    try
    {
        typename ft::list<T>::iterator it(list.begin());
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

void    test(ft::list<struct a>  &list)
{
    size_t i;
    try
    {
        ft::list<struct a>::iterator it(list.begin());
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
void    test(ft::list<T *>  &list)
{
    size_t i;
    size_t j;
    try
    {
        typename ft::list<T *>::iterator it(list.begin());
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

template<typename T>
void    test_all(const T &a, int x, int y)
{
    ft::list<T> l1(0);
    ft::list<T> l2(1);
    ft::list<T> l3(2);
    ft::list<T> l4(3);
    ft::list<T> l5(4);
    ft::list<T> l6(5);
    ft::list<T> l7(6);
    ft::list<T> l8(7);
    ft::list<T> l9(8);
    ft::list<T> l10(9);
    ft::list<T> l11(10);
    ft::list<T> l12(10);
    ft::list<T> l13(x);
    ft::list<T> l14(x + 27);
    ft::list<T> l15(x + 66);
    ft::list<T> l16(x + 192);
    ft::list<T> l17(y);
    ft::list<T> l18(y + 222);
    ft::list<T> l19(y + 371);
    ft::list<T> l20(y + 1094);
    ft::list<T> tabl[] = {l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14, l15, l16, l17, l18, l19, l20};

    ft::list<T> m1(0, a);
    ft::list<T> m2(1, a);
    ft::list<T> m3(2, a);
    ft::list<T> m4(3, a);
    ft::list<T> m5(4, a);
    ft::list<T> m6(5, a);
    ft::list<T> m7(6, a);
    ft::list<T> m8(7, a);
    ft::list<T> m9(8, a);
    ft::list<T> m10(9, a);
    ft::list<T> m11(10, a);
    ft::list<T> m12(11, a);
    ft::list<T> m13(x, a);
    ft::list<T> m14(x + 227, a);
    ft::list<T> m15(x + 94, a);
    ft::list<T> m16(x + 23, a);
    ft::list<T> m17(y, a);
    ft::list<T> m18(y + 239, a);
    ft::list<T> m19(y + 684, a);
    ft::list<T> m20(y + 1341, a);
    ft::list<T> tabm[] = {m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20};

    int i = 0;

    while (i < 19)
    {
        test(tabl[i]);
        test(tabm[i]);
        i++;
    }
}

template<typename T>
void    test_all(int j, T *a, int x, int y)
{
    (void)j;
    ft::list<T *> m1(0, a);
    ft::list<T *> m2(1, a);
    ft::list<T *> m3(2, a);
    ft::list<T *> m4(3, a);
    ft::list<T *> m5(4, a);
    ft::list<T *> m6(5, a);
    ft::list<T *> m7(6, a);
    ft::list<T *> m8(7, a);
    ft::list<T *> m9(8, a);
    ft::list<T *> m10(9, a);
    ft::list<T *> m11(10, a);
    ft::list<T *> m12(11, a);
    ft::list<T *> m13(x, a);
    ft::list<T *> m14(x + 227, a);
    ft::list<T *> m15(x + 94, a);
    ft::list<T *> m16(x + 23, a);
    ft::list<T *> m17(y, a);
    ft::list<T *> m18(y + 239, a);
    ft::list<T *> m19(y + 684, a);
    ft::list<T *> m20(y + 1341, a);
    ft::list<T *> tabm[] = {m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20};

    int i = 0;

    while (i < 20)
    {
        test(tabm[i]);
        i++;
    }
}

int main()
{
    std::string     str("test");
    double          db(72.27);
    int             tab_int[] = {12, 27, 39, 255, 447, 828, 0};
    char            tab_char[] = "nickel";
    struct a        strtc = {1021};
    int             a = 42;
    int             b = 401;
    int             c = 1248;

    test_all(a, b, c);
    test_all('f', 392, 2501);
    test_all(str, 125, 804);
    test_all(strtc, 231, 865);
    test_all(db, 288, 1427);
    test_all(1, tab_int, 71, 650);
    test_all(1, tab_char, 89, 721);


    return (0);
}