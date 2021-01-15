#include <iostream>
#include "vector.hpp"
#include "test.hpp"
#include <cstdlib>

int main()
{
    size_t      i;
    test<int>        c(6501);
    test<int>   tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0};
    test<char>         tab1[500];
    for (i = 0; i < 500; i++)
    {
        if (i == 499)
            tab1[i] = 0;
        else
            tab1[i] = static_cast<char>(std::rand() % 90 + 35);
    }
    ft::vector<test<int> >::iterator  it;
    ft::vector<test<int> >::iterator  it1(&c);
    ft::vector<test<int> >::iterator  it2(tab);
    ft::vector<test<char> >::iterator  it3(tab1);
    ft::vector<test<int> >::iterator  it2_eq(it2);
    ft::vector<test<int> >::iterator  it2_neq(tab + 1);
    ft::vector<test<int> >::iterator::reference ref_it2 = *it2;
    ft::vector<test<char> >::iterator::pointer ref_it3 = &*it3;

    (void)it;
    std::cout << *it1 << "\n";
    std::cout << *it2 << "\n";

    //[]
    for (i = 0; it2[i] != 0; i++)
        std::cout << it2[i] << " ";
    std::cout << "\n";

    //*++(n)
    while (*it2 != 0)
        std::cout << *it2++ << " ";
    std::cout << "\n";
    
    //*--(n)
    while (*it2 != ref_it2)
        std::cout << *it2-- << " ";
    std::cout << "\n";

    //*++
    while (*it2 != 0)
        std::cout << *++it2 << " ";
    std::cout << "\n";

    //*--
    while (*it2 != ref_it2)
        std::cout << *--it2 << " ";
    std::cout << "\n";

    // + n
    for (i = 0; *(it2 + i) != 0; i++)
        std::cout << *(it2 + i) << " ";
    std::cout << "\n";

    //++(n)
    while (*it3 != 0)
    {
        std::cout << *it3 << " ";
        it3++;
    }
    std::cout << "\n";

    //- n
    for (i = 0; &*(it3 - i) != ref_it3; i++)
        std::cout << *(it3 - i) << " ";
    std::cout << "\n";

    //--(n)
    while (&*it3-- != ref_it3)
    {
        std::cout << *it3 << " ";
        std::cout << *ref_it3 << " ";
    }   
    std::cout << "\n";

    //+=
    it3++;
    while (*it3 != 0)
    {
        std::cout << *it3 << " ";
        it3 += 1;
    }
    std::cout << "\n";

    //-=
    while (&*it3 != ref_it3)
    {
        std::cout << *it3 << " ";
        it3 -= 1;
    }
    std::cout << "\n";

    // = +=
    while (*it3 != 0)
    {
        std::cout << *it3 << " ";
        it3 = it3 += 1;
    }
    std::cout << "\n";

    //= -=
    while (&*it3 != ref_it3)
    {
        std::cout << *it3 << " ";
        it3 = it3 -= 1;
    }
    std::cout << "\n";

    //++
    while (*it3 != 0)
    {
        ++it3;
        std::cout << *it3 << " ";
    }
    std::cout << "\n";

    //--
    while (&*--it3 != ref_it3)
    {
        std::cout << *it3 << " ";
    }
    std::cout << "\n";

    std::cout << *(it3 += (i - 1)) << " ";
    std::cout << *it3 << " ";
    std::cout << *(it3 -= (i - 1)) << " ";
    std::cout << *it3 << " ";
    std::cout << *(it3 += (i / 2))<< " ";
    std::cout << *it3 << " ";
    std::cout << *(it3 -= (i / 2))<< " ";
    std::cout << *it3 << " ";
    std::cout << *(it3 += (i / 3))<< " ";
    std::cout << *it3 << " ";
    std::cout << *(it3 -= (i / 3))<< " ";
    std::cout << *it3 << " ";

    std::cout << "\n";



    //different
    /*std::cout << (it2 < it3) << " ";
    std::cout << (it2 <= it3) << " ";
    std::cout << (it2 >= it3) << " ";
    std::cout << (it2 > it3) << " ";
    std::cout << (it2 == it3) << " ";
    std::cout << (it2 != it3) << " ";
    std::cout << (it2 != it3) << " ";
    std::cout << "\n";*/

    //equal
    std::cout << (it2 < it2_eq) << " ";
    std::cout << (it2 <= it2_eq) << " ";
    std::cout << (it2 >= it2_eq) << " ";
    std::cout << (it2 > it2_eq) << " ";
    std::cout << (it2 == it2_eq) << " ";
    std::cout << (it2 != it2_eq) << " ";
    std::cout << (it2 != it2_eq) << " ";
    std::cout << "\n";

    //equal with -1
    std::cout << (it2 < it2_neq - 1) << " ";
    std::cout << (it2 <= it2_neq - 1) << " ";
    std::cout << (it2 >= it2_neq - 1) << " ";
    std::cout << (it2 > it2_neq - 1) << " ";
    std::cout << (it2 == it2_neq - 1) << " ";
    std::cout << (it2 != it2_neq - 1) << " ";
    std::cout << (it2 != it2_neq - 1) << " ";
    std::cout << "\n";

    //not equal because +1
    std::cout << (it2 < it2_neq) << " ";
    std::cout << (it2 <= it2_neq) << " ";
    std::cout << (it2 >= it2_neq) << " ";
    std::cout << (it2 > it2_neq) << " ";
    std::cout << (it2 == it2_neq) << " ";
    std::cout << (it2 != it2_neq) << " ";
    std::cout << (it2 != it2_neq) << " ";
    std::cout << "\n";

    return (0);
}
