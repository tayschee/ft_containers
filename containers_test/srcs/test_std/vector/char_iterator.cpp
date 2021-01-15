#include <iostream>
#include <vector>

int main()
{
    size_t      i;
    char        c = 'a';
    char         tab[] = "qwerty";
    char         tab1[] = "qqc de un peu long mais relativement court, rajoutons encore quelques mots";
    std::vector<char>::iterator  it;
    std::vector<char>::iterator  it1(&c);
    std::vector<char>::iterator  it2(tab);
    std::vector<char>::iterator  it3(tab1);
    std::vector<char>::iterator  it2_eq(it2);
    std::vector<char>::iterator  it2_neq;
    std::vector<char>::iterator::reference ref_it2 = *it2;
    std::vector<char>::iterator::pointer ref_it3 = &*it3;

    (void)it;
    it2_neq = it2 + 1;
    std::cout << *it1 << "\n";
    *it1 = 'b';
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
    std::cout << (it2 < it3) << " ";
    std::cout << (it2 <= it3) << " ";
    std::cout << (it2 >= it3) << " ";
    std::cout << (it2 > it3) << " ";
    std::cout << (it2 == it3) << " ";
    std::cout << (it2 != it3) << " ";
    std::cout << (it2 != it3) << " ";
    std::cout << "\n";

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

    std::vector<char>::reverse_iterator  itr;
    std::vector<char>::reverse_iterator  it1r(it1);
    std::vector<char>::reverse_iterator  it2r(it2);
    std::vector<char>::reverse_iterator  it3r(it3);
    std::vector<char>::reverse_iterator  it2r_eq(it2);
    std::vector<char>::reverse_iterator  it2r_neq;
    std::vector<char>::reverse_iterator::difference_type j;

    (void)itr;
    it2r_neq = it2r + 1;
    std::cout << *--it1r << "\n";
    *it1r = c;
    std::cout << *it1r << "\n";
    std::cout << *--it2r << "\n";
     std::cout << *--it3r << "\n";

    std::vector<char>::iterator::reference ref_it2r = *it2r;
    std::vector<char>::iterator::pointer ref_it3r = &*it3r;

    //[]
    for (j = 0; it2r[j] != 0; j--)
        std::cout << it2r[j] << " ";
    std::cout << "\n";

    for (j = 0; it3r[j] != 0; j--)
        std::cout << it3r[j] << " ";
    std::cout << "\n";

    //*--(n)
    while (*it2r != 0)
        std::cout << *it2r-- << " ";
    std::cout << "\n";
    
    //*++(n)
    while (*it2r != ref_it2r)
        std::cout << *it2r++ << " ";
    std::cout << "\n";

    //*--
    while (*it2r != 0)
        std::cout << *--it2r << " ";
    std::cout << "\n";

    //*++
    while (*it2r != ref_it2r)
        std::cout << *++it2r << " ";
    std::cout << "\n";

    // - n
    for (j = 0; *(it2r + j) != 0; j--)
        std::cout << *(it2r + j) << " ";
    std::cout << "\n";

    //--(n)
    while (*it3r != 0)
    {
        std::cout << *it3r << " ";
        it3r--;
    }
    std::cout << "\n";

    //+ n
    for (j = 0; &*(it3r + j) != ref_it3; j++)
        std::cout << *(it3r + j) << " ";
    std::cout << "\n";

    //++(n)
    while (&*it3r++ != ref_it3)
    {
        std::cout << *it3r << " ";
        std::cout << *ref_it3 << " ";
    }   
    std::cout << "\n";

    //-=
    it3r--;
    while (*it3r != 0)
    {
        std::cout << *it3r << " ";
        it3r -= 1;
    }
    std::cout << "\n";

    //+=
    while (&*it3r != ref_it3r)
    {
        std::cout << *it3r << " ";
        it3r += 1;
    }
    std::cout << "\n";

    // = -=
    while (*it3r != 0)
    {
        std::cout << *it3r << " ";
        it3r = it3r -= 1;
    }
    std::cout << "\n";

    //= +=
    while (&*it3r != ref_it3r)
    {
        std::cout << *it3r << " ";
        it3r = it3r += 1;
    }
    std::cout << "\n";

    //--
    while (*it3r != 0)
    {
        --it3r;
        std::cout << *it3r << " ";
    }
    std::cout << "\n";

    //++
    while (&*++it3r != ref_it3r)
    {
        std::cout << *it3r << " ";
    }
    std::cout << "\n";

    std::cout << *(it3r -= (j + 1)) << " ";
    std::cout << *it3r << " ";
    std::cout << *(it3r += (j + 1)) << " ";
    std::cout << *it3r << " ";
    std::cout << *(it3r -= (j / 2))<< " ";
    std::cout << *it3r << " ";
    std::cout << *(it3r += (j / 2))<< " ";
    std::cout << *it3r << " ";
    std::cout << *(it3r -= (j / 3))<< " ";
    std::cout << *it3r << " ";
    std::cout << *(it3r += (j / 3))<< " ";
    std::cout << *it3r << " ";
    std::cout << "\n";

    //different
    std::cout << (it2r < it3r) << " ";
    std::cout << (it2r <= it3r) << " ";
    std::cout << (it2r >= it3r) << " ";
    std::cout << (it2r > it3r) << " ";
    std::cout << (it2r == it3r) << " ";
    std::cout << (it2r != it3r) << " ";
    std::cout << (it2r != it3r) << " ";
    std::cout << "\n";

    //equal
    std::cout << (it2r < it2r_eq) << " ";
    std::cout << (it2r <= it2r_eq) << " ";
    std::cout << (it2r >= it2r_eq) << " ";
    std::cout << (it2r > it2r_eq) << " ";
    std::cout << (it2r == it2r_eq) << " ";
    std::cout << (it2r != it2r_eq) << " ";
    std::cout << (it2r != it2r_eq) << " ";
    std::cout << "\n";

    //equal with +1
    std::cout << (it2r < it2r_neq + 1) << " ";
    std::cout << (it2r <= it2r_neq + 1) << " ";
    std::cout << (it2r >= it2r_neq + 1) << " ";
    std::cout << (it2r > it2r_neq + 1) << " ";
    std::cout << (it2r == it2r_neq + 1) << " ";
    std::cout << (it2r != it2r_neq + 1) << " ";
    std::cout << (it2r != it2r_neq + 1) << " ";
    std::cout << "\n";

    //not equal because -1
    std::cout << (it2r < it2r_neq) << " ";
    std::cout << (it2r <= it2r_neq) << " ";
    std::cout << (it2r >= it2r_neq) << " ";
    std::cout << (it2r > it2r_neq) << " ";
    std::cout << (it2r == it2r_neq) << " ";
    std::cout << (it2r != it2r_neq) << " ";
    std::cout << (it2r != it2r_neq) << " ";
    std::cout << "\n";

    return (0);
}
