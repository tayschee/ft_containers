#include "list.hpp"
#include <iostream>
#include <string>

struct a
{
    int a;
};

template <typename T>
void    cmp(typename ft::list<T>::iterator &it1, typename ft::list<T>::iterator &it2)
{
    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << " ";
    std::cout << "\n";
}

template <typename T>
void    cmp(typename ft::list<T>::const_iterator &it1, typename ft::list<T>::iterator &it2)
{
    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << " ";
    std::cout << "\n";
}

template <typename T>
void    cmp(typename ft::list<T>::iterator &it1, typename ft::list<T>::const_iterator &it2)
{
    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << " ";
    std::cout << "\n";
}

template <typename T>
void    cmp(typename ft::list<T>::const_iterator &it1, typename ft::list<T>::const_iterator &it2)
{
    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << " ";
    std::cout << "\n";
}

template <typename T>
void    cmp(typename ft::list<T>::reverse_iterator &it1, typename ft::list<T>::reverse_iterator &it2)
{
    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << " ";
    std::cout << "\n";
}

template <typename T>
void    cmp(typename ft::list<T>::const_reverse_iterator &it1, typename ft::list<T>::reverse_iterator &it2)
{
    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << " ";
    std::cout << "\n";
}

template <typename T>
void    cmp(typename ft::list<T>::reverse_iterator &it1, typename ft::list<T>::const_reverse_iterator &it2)
{
    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << " ";
    std::cout << "\n";
}

template <typename T>
void    cmp(typename ft::list<T>::const_reverse_iterator &it1, typename ft::list<T>::const_reverse_iterator &it2)
{
    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << " ";
    std::cout << "\n";
}

template <typename T>
void    inc(typename ft::list<T>::iterator &beg, typename ft::list<T>::iterator &end)
{
    while (beg != end)
    {
        std::cout << *beg++ << " ";
    }
    std::cout << "\n";
    end--;
    beg++;
    while (beg != end)
    {
        std::cout << *++beg << " ";
    }
    std::cout << "\n";
    end++;
    while (beg != end)
    {
        std::cout << *beg-- << " ";
    }
    std::cout << "\n";
    beg--;
    end--;
    while (beg != end)
    {
        std::cout << *--beg << " ";
    }
}

template <typename T>
void    inc(typename ft::list<T>::const_iterator beg, typename ft::list<T>::const_iterator end)
{
    while (beg != end)
    {
        std::cout << *beg++ << " ";
    }
    std::cout << "\n";
    end--;
    beg++;
    while (beg != end)
    {
        std::cout << *++beg << " ";
    }
    std::cout << "\n";
    end++;
    while (beg != end)
    {
        std::cout << *beg-- << " ";
    }
    std::cout << "\n";
    beg--;
    end--;
    while (beg != end)
    {
        std::cout << *--beg << " ";
    }
}

template <typename T>
void    inc(typename ft::list<T>::reverse_iterator &beg, typename ft::list<T>::reverse_iterator &end)
{
    while (beg != end)
    {
        std::cout << *beg-- << " ";
    }
    std::cout << "\n";
    end++;
    beg--;
    while (beg != end)
    {
        std::cout << *--beg << " ";
    }
    std::cout << "\n";
    end--;
    while (beg != end)
    {
        std::cout << *beg++ << " ";
    }
    std::cout << "\n";
    beg++;
    end++;
    while (beg != end)
    {
        std::cout << *++beg << " ";
    }
}

template <typename T>
void    inc(typename ft::list<T>::const_reverse_iterator beg, typename ft::list<T>::const_reverse_iterator end)
{
    while (beg != end)
    {
        std::cout << *beg-- << " ";
    }
    std::cout << "\n";
    end++;
    beg--;
    while (beg != end)
    {
        std::cout << *--beg << " ";
    }
    std::cout << "\n";
    end--;
    while (beg != end)
    {
        std::cout << *beg++ << " ";
    }
    std::cout << "\n";
    beg++;
    end++;
    while (beg != end)
    {
        std::cout << *++beg << " ";
    }
}

template <typename T>
void test_list(T v1, int nb1, T v2, int nb2, T v3, int nb3)
{
    ft::list<T> lst1(nb1, v1);
    ft::list<T> lst2;
    typename ft::list<T>::iterator beg1;
    typename ft::list<T>::iterator end1;
    typename ft::list<T>::iterator beg2;
    typename ft::list<T>::iterator end2;
    typename ft::list<T>::const_iterator cbeg1;
    typename ft::list<T>::const_iterator cend1;
    typename ft::list<T>::const_iterator cbeg2;
    typename ft::list<T>::const_iterator cend2;
    typename ft::list<T>::reverse_iterator rbeg1;
    typename ft::list<T>::reverse_iterator rend1;
    typename ft::list<T>::reverse_iterator rbeg2;
    typename ft::list<T>::reverse_iterator rend2;
    typename ft::list<T>::const_reverse_iterator rcbeg1;
    typename ft::list<T>::const_reverse_iterator rcend1;
    typename ft::list<T>::const_reverse_iterator rcbeg2;
    typename ft::list<T>::const_reverse_iterator rcend2;

    while (nb2 > 0)
    {
        nb2--;
        lst1.push_back(v2);
    }
    while (nb3 > 0)
    {
        nb3--;
        lst1.push_back(v3);
    }
    lst2 = lst1;
    beg1 = lst1.begin();
    end1 = lst1.end();
    cbeg1 = beg1;
    cend1 = end1;
    beg2 = lst2.begin();
    end2 = lst2.end();
    cbeg2 = beg2;
    cend2 = end2;

    rbeg1 = typename ft::list<T>::reverse_iterator(lst1.begin());
    rend1 = typename ft::list<T>::reverse_iterator(lst1.end());
    rcbeg1 = typename ft::list<T>::const_reverse_iterator(cbeg1);
    rcend1 = typename ft::list<T>::const_reverse_iterator(cend1);
    rbeg2 = typename ft::list<T>::reverse_iterator(lst2.begin());
    rend2 = typename ft::list<T>::reverse_iterator(lst2.end());
    rcbeg2 = typename ft::list<T>::const_reverse_iterator(cbeg2);
    rcend2 = typename ft::list<T>::const_reverse_iterator(cend2);

    //no _const
    cmp<T>(beg1, beg1);
    cmp<T>(beg1, end1);
    inc<T>(beg1, end1);
    std::cout << "\n";
    cmp<T>(beg2, end2);
    inc<T>(beg2, end2);
    std::cout << "\n";
    cmp<T>(beg2, beg1);

    //const
    cmp<T>(cbeg1, cbeg1);
    cmp<T>(cbeg1, cend1);
    inc<T>(cbeg1, cend1);
    std::cout << "\n";
    cmp<T>(cbeg2, cend2);
    inc<T>(cbeg2, cend2);
    std::cout << "\n";
    cmp<T>(cbeg2, cbeg1);

    //no_const const
    cmp<T>(cbeg1, beg1);
    cmp<T>(cbeg1, end1);
    std::cout << "\n";
    cmp<T>(beg2, cend2);
    std::cout << "\n";
    cmp<T>(cbeg2, beg1);

    //reverse
    cmp<T>(rend1, rend1);
    cmp<T>(rend1, rbeg1);
    inc<T>(rend1, rbeg1);
    std::cout << "\n";
    cmp<T>(rend2, rbeg2);
    inc<T>(rend2, rbeg2);
    std::cout << "\n";
    cmp<T>(rend2, rend1);

    //const reverse
    cmp<T>(rcend1, rcend1);
    cmp<T>(rcend1, rcbeg1);
    inc<T>(rcend1, rcbeg1);
    std::cout << "\n";
    cmp<T>(rcend2, rcbeg2);
    inc<T>(rcend2, rcbeg2);
    std::cout << "\n";
    cmp<T>(rcend2, rcend1);

    //no-const const reverse
    cmp<T>(rcend1, rend1);
    cmp<T>(rcend1, rbeg1);
    std::cout << "\n";
    cmp<T>(rend2, rcbeg2);
    std::cout << "\n";
    cmp<T>(rcend2, rend1);
    

}

int main()
{
    size_t i;
    std::string str1("abc");
    std::string str2("edf");
    std::string str3("jkl");
    struct a    a = {12};
    ft::list<struct a> strct(3, a);

    std::cout << strct.begin()->a << "\n";
    test_list(12, 1, 34, 3, -72, 1);
    test_list('x', 3, 'e', 5, 'k', 1);
    test_list(str1, 3, str2, 2, str3, 1);
    test_list(12.5, 12, 34.2, 3, -72.1, 0);

    return 0;
}