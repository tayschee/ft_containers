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

template<typename T>
void    test_all(const T &a, int x, int y)
{
    std::list<T> l1(0);
    std::list<T> l2(1);
    std::list<T> l3(2);
    std::list<T> l4(3);
    std::list<T> l5(4);
    std::list<T> l6(5);
    std::list<T> l7(6);
    std::list<T> l8(7);
    std::list<T> l9(8);
    std::list<T> l10(9);
    std::list<T> l11(10);
    std::list<T> l12(10);
    std::list<T> l13(x);
    std::list<T> l14(x + 27);
    std::list<T> l15(x + 66);
    std::list<T> l16(x + 192);
    std::list<T> l17(y);
    std::list<T> l18(y + 222);
    std::list<T> l19(y + 371);
    std::list<T> l20(y + 1094);
    std::list<T> tabl[] = {l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14, l15, l16, l17, l18, l19, l20};

    std::list<T> m1(0, a);
    std::list<T> m2(1, a);
    std::list<T> m3(2, a);
    std::list<T> m4(3, a);
    std::list<T> m5(4, a);
    std::list<T> m6(5, a);
    std::list<T> m7(6, a);
    std::list<T> m8(7, a);
    std::list<T> m9(8, a);
    std::list<T> m10(9, a);
    std::list<T> m11(10, a);
    std::list<T> m12(11, a);
    std::list<T> m13(x, a);
    std::list<T> m14(x + 227, a);
    std::list<T> m15(x + 94, a);
    std::list<T> m16(x + 23, a);
    std::list<T> m17(y, a);
    std::list<T> m18(y + 239, a);
    std::list<T> m19(y + 684, a);
    std::list<T> m20(y + 1341, a);
    std::list<T> tabm[] = {m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20};

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
    std::list<T *> m1(0, a);
    std::list<T *> m2(1, a);
    std::list<T *> m3(2, a);
    std::list<T *> m4(3, a);
    std::list<T *> m5(4, a);
    std::list<T *> m6(5, a);
    std::list<T *> m7(6, a);
    std::list<T *> m8(7, a);
    std::list<T *> m9(8, a);
    std::list<T *> m10(9, a);
    std::list<T *> m11(10, a);
    std::list<T *> m12(11, a);
    std::list<T *> m13(x, a);
    std::list<T *> m14(x + 227, a);
    std::list<T *> m15(x + 94, a);
    std::list<T *> m16(x + 23, a);
    std::list<T *> m17(y, a);
    std::list<T *> m18(y + 239, a);
    std::list<T *> m19(y + 684, a);
    std::list<T *> m20(y + 1341, a);
    std::list<T *> tabm[] = {m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20};

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