#include "list.hpp"
#include "vector.hpp"
#include <iostream>
#include <string>



template <typename T>
void    cmp(typename ft::list<T> &lst1, typename ft::list<T> &lst2)
{
    std::cout << (lst1 == lst2) << " ";
    std::cout << (lst2 == lst1) << " ";
    std::cout << (lst1 != lst2) << " ";
    std::cout << (lst2 != lst1) << " ";
    std::cout << (lst1 > lst2) << " ";
    std::cout << (lst2 > lst1) << " ";
    std::cout << (lst1 < lst2) << " ";
    std::cout << (lst2 < lst1) << " ";
    std::cout << (lst1 >= lst2) << " ";
    std::cout << (lst2 >= lst1) << " ";
    std::cout << (lst1 <= lst2) << " ";
    std::cout << (lst2 <= lst1) << " ";
    std::cout << "\n";
}

template <typename T>
ft::list<T> create(size_t i, T val)
{
    return (ft::list<T>(i, val));
}

template <typename T>
void    test_all(T val, T val2, T *tab, size_t size, T *tab1, size_t size1)
{
    typename ft::vector<T>::iterator beg(tab);
    typename ft::vector<T>::iterator end(&tab[size]);
    typename ft::vector<T>::iterator beg1(tab1);
    typename ft::vector<T>::iterator end1(&tab1[size1]);
    ft::list<T> lst1;
    ft::list<T> lst2;
    ft::list<T> lst3(beg, end);
    ft::list<T> lst4(lst3);
    ft::list<T> lst5(beg1, end1);
    size_t i = 0;
    size_t j = 0;

    cmp(lst4, lst5);
    cmp(lst3, lst4);
    lst3.push_back(val);
    cmp(lst3, lst4);
    lst4 = lst3;
    cmp(lst3, lst4);
    lst4.push_front(val2);
    cmp(lst3, lst4);
    while(i < 20)
    {
        lst1 = create(i, val);
        while(j < 20)
        {
            lst2 = create(j, val);
            cmp(lst1, lst2);
            lst2 = create(j, val2);
            cmp(lst1, lst2);
            ++j;
        }
        ++i;
    }
}

int main()
{
    int         tab_int[] = {12, 94, 255, 21, 41, 47, 48, 441, -45, -12, -1002};
    int         tab_int1[] = {12, 94, 255, 21, 21, 47, 48, 441, -45, -12, -1002};
    double      tab_db[] = {87.14, 78.14, 80.19, 18.27, 90.14, 27.36};
    double      tab_db1[] = {87.14, 78.14, 80.19, 18.27, 90.14, 27.36, 1002.43, 1823.92, 284.013, 141.293};
    char        tab_char[] = "bgrwieobfh56;]345;r23;5[]tl53[prkg[th3'jvg]345mgj42[5p4wf,lg3pg,p534]";
    char        tab_char1[] = "bgrwieobfh56;]345;r23;5[]tl53[prkg[th3jokferwjtipu354jti5jn43i"
                                "'jvg]345mgj42[5p4wf,lg3pg,p534]efjrqwbfr4i2brfwbdfeouwbriubefv789432n";
    std::string str("test");  
    std::string str1("test1");                       
    std::string str2("test2");
    std::string str3("test3");
    std::string str4("test4");
    std::string str5("test5");
    std::string tab_str[] = {str, str1, str2, str3, str4, str5};
    std::string tab_str1[] = {str, str1, str2, str2, str4, str5};

    test_all(24, 31, tab_int, 11, tab_int1, 18);
    test_all(24.14, 31.17, tab_db, 6, tab_db1, 10);
    test_all('X', 'x', tab_char, 70, tab_char1, 132);
    test_all(str1, str2, tab_str, 5, tab_str1, 5);

    return 0;
}