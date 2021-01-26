#include <iostream>
#include "vector.hpp"

int main()
{
    size_t      i;
    double        c = 12.12;
    double         tab[] = {94372.12, 521.23, -5.0};
    double         tab1[] = {1.53, 234.3412, 542.54, 542.541, 542.542, 876.43, 65.987, 321.874, 87.43, -5.0};
    double         tab2[] = {4.4, 54.2, 532.7, -5.0};
    ft::vector<double>::iterator  it;
    ft::vector<double>::iterator  it1(&c);
    ft::vector<double>::iterator  it2(tab);
    ft::vector<double>::iterator  it3(tab1);
    ft::vector<double>::iterator  it2_eq(it2);
    ft::vector<double>::const_iterator cit;
    ft::vector<double>::const_iterator cit1(&c);
    ft::vector<double>::const_iterator cit1bis(it1); //it1 must inherit
    ft::vector<double>::const_iterator cit2(tab2);
    ft::vector<double>::iterator  it2_neq; //enleve parenthese
    ft::vector<double>::iterator::reference ref_it2 = *it2;
    ft::vector<double>::iterator::pointer ref_it3 = &*it3;
    ft::vector<double>::const_iterator::reference ref_cit2 = *cit2;
    ft::vector<double>::const_iterator::pointer point_cit2 = &*cit2;

    (void)it;
    (void)cit;
    it2_neq = it2 + 1;
    std::cout << *it1 << "\n";
    std::cout << *cit1bis << "\n";
    *it1 = 'b';
    std::cout << *it1 << "\n";
    std::cout << *it2 << "\n";
    std::cout << *cit1 << "\n";

    //[]
    for (i = 0; it2[i] > 0.0; i++)
        std::cout << it2[i] << " ";
    std::cout << "\n";

    //const []
    for (i = 0; cit2[i] > 0.0; i++)
        std::cout << cit2[i] << " ";
    std::cout << "\n";

    //*++(n)
    while (*it2 > 0.0)
        std::cout << *it2++ << " ";
    std::cout << "\n";

    //*++(n) const
    while (*cit2 > 0.0)
        std::cout << *cit2++ << " ";
    std::cout << "\n";
    
    //*--(n)
    while (*it2 != ref_it2)
        std::cout << *it2-- << " ";
    std::cout << "\n";

    //*--(n) const
    while (*cit2 != ref_cit2)
        std::cout << *cit2-- << " ";
    std::cout << "\n";

    //*++
    while (*it2 > 0.0)
        std::cout << *++it2 << " ";
    std::cout << "\n";

    //*++ const
    while (*cit2 > 0.0)
        std::cout << *++cit2 << " ";
    std::cout << "\n";

    //*--
    while (*it2 != ref_it2)
        std::cout << *--it2 << " ";
    std::cout << "\n";

    //*-- const
    while (*cit2 != ref_cit2)
        std::cout << *--cit2 << " ";
    std::cout << "\n";

    // + n
    for (i = 0; *(it2 + i) > 0.0; i++)
        std::cout << *(it2 + i) << " ";
    std::cout << "\n";

    // + n const
    for (i = 0; *(cit2 + i) > 0.0; i++)
        std::cout << *(cit2 + i) << " ";
    std::cout << "\n";

    //++(n)
    while (*it3 > 0.0)
    {
        std::cout << *it3 << " ";
        it3++;
    }
    std::cout << "\n";

    //++(n) const
    while (*cit2 > 0.0)
    {
        std::cout << *cit2 << " ";
        cit2++;
    }
    std::cout << "\n";

     //- n const
    for (i = 0; &*(cit2 - i) != point_cit2; i++)
        std::cout << *(cit2 - i) << " ";
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
    while (*it3 > 0.0)
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
    while (*it3 > 0.0)
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
    while (*it3 > 0.0)
    {
        ++it3;
        std::cout << *it3 << " ";
    }
    std::cout << "\n";

    //++ const
    while (*cit2 > 0.0)
    {
        ++cit2;
        std::cout << *cit2 << " ";
    }
    std::cout << "\n";

     //-- const
    while (&*--it3 != ref_it3)
    {
        std::cout << *it3 << " ";
    }
    std::cout << "\n";

    //-- const
    while (&*--cit2 != point_cit2)
    {
        std::cout << *cit2 << " ";
    }
    std::cout << "\n";

    *cit2++;
    std::cout << *(it3 += (i - 1)) << " ";
    std::cout << *(it3 - 1) << " ";
    std::cout << *(it3 -= (i - 1)) << " ";
    std::cout << *it3 << " ";
    std::cout << *(it3 += (i / 2))<< " ";
    std::cout << *it3 << " ";
    std::cout << *(it3 -= (i / 2))<< " ";
    std::cout << *it3 << " ";
    std::cout << *(it3 += (i / 5))<< " ";
    std::cout << *it3 << " ";
    std::cout << *(it3 -= (i / 5))<< " ";
    std::cout << *it3 << " ";
    std::cout << *(cit2 += 3)<< " ";
    std::cout << *cit2 << " ";
    std::cout << *(cit2 -= 3)<< " ";
    std::cout << *cit2 << " ";

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

    //const
    std::cout << (it2_eq < cit2) << " ";
    std::cout << (cit2 <= it2_eq) << " ";
    std::cout << (cit2 >= it2_eq) << " ";
    std::cout << (cit2 > it2_eq) << " ";
    std::cout << (cit2 == it2_eq) << " ";
    std::cout << (cit2 != it2_eq) << " ";
    std::cout << (cit2 != it2_eq) << " ";

    ft::vector<double>::reverse_iterator::difference_type j;
    ft::vector<double>::reverse_iterator  itr;
    ft::vector<double>::reverse_iterator  it1r(it1);
    ft::vector<double>::reverse_iterator  it2r(it2);
    ft::vector<double>::reverse_iterator  it3r(it3);
    ft::vector<double>::reverse_iterator  it2r_eq(it2);
    ft::vector<double>::reverse_iterator  it2r_neq;
    ft::vector<double>::const_reverse_iterator  citr;
    ft::vector<double>::const_reverse_iterator  citr1(cit1);
    ft::vector<double>::const_reverse_iterator  citr2(it2r);
    ft::vector<double>::const_reverse_iterator  citr3(it3);

    (void)itr;
    (void)citr;
    it2r_neq = it2r + 1;
    std::cout << *--it1r << "\n";
    *it1r = c;
    std::cout << *it1r << "\n";
    std::cout << *--it2r << "\n";
    std::cout << *--it3r << "\n";
    std::cout << *--citr1;
    std::cout << *--citr2;
    std::cout << *--citr3;

    ft::vector<double>::iterator::reference ref_it2r = *it2r;
    ft::vector<double>::iterator::pointer ref_it3r = &*it3r;

    //[]
    for (j = 0; it2r[j] > 0.0; j--)
        std::cout << it2r[j] << " ";
    std::cout << "\n";

     for (j = 0; citr2[j] > 0.0; j--)
        std::cout << citr2[j] << " ";
    std::cout << "\n";

    for (j = 0; it3r[j] > 0.0; j--)
        std::cout << it3r[j] << " ";
    std::cout << "\n";

    for (j = 0; citr3[j] > 0.0; j--)
        std::cout << citr3[j] << " ";
    std::cout << "\n";

    //*--(n)
    while (*it2r > 0.0)
        std::cout << *it2r-- << " ";
    std::cout << "\n";

     while (*citr2 > 0.0)
        std::cout << *citr2-- << " ";
    std::cout << "\n";
    
    //*++(n)
    while (*it2r != ref_it2r)
        std::cout << *it2r++ << " ";
    std::cout << "\n";

     //*++(n)
    while (*citr2 != ref_it2r)
        std::cout << *citr2++ << " ";
    std::cout << "\n";

    //*--
    while (*it2r > 0.0)
        std::cout << *--it2r << " ";
    std::cout << "\n";

     while (*citr2 > 0.0)
        std::cout << *--citr2 << " ";
    std::cout << "\n";

    //*++
    while (*it2r != ref_it2r)
        std::cout << *++it2r << " ";
    std::cout << "\n";

    //*++
    while (*citr2 != ref_it2r)
        std::cout << *++citr2 << " ";
    std::cout << "\n";

    // - n
    for (j = 0; *(it2r + j) > 0.0; j--)
        std::cout << *(it2r + j) << " ";
    std::cout << "\n";

     // - n
    for (j = 0; *(citr2 + j) > 0.0; j--)
        std::cout << *(citr2 + j) << " ";
    std::cout << "\n";

    //--(n)
    while (*it3r > 0.0)
    {
        std::cout << *it3r << " ";
        it3r--;
    }
    std::cout << "\n";

    while (*citr3 > 0.0)
    {
        std::cout << *citr3 << " ";
        citr3--;
    }
    std::cout << "\n";

    //+ n
    for (j = 0; &*(it3r + j) != ref_it3; j++)
        std::cout << *(it3r + j) << " ";
    std::cout << "\n";

    //+ n
    for (j = 0; &*(citr3 + j) != ref_it3; j++)
        std::cout << *(citr3 + j) << " ";
    std::cout << "\n";

    //++(n)
    while (&*it3r++ != ref_it3)
    {
        std::cout << *it3r << " ";
    }   
    std::cout << "\n";

     //++(n)
    while (&*citr3++ != ref_it3)
    {
        std::cout << *citr3 << " ";
    }   
    std::cout << "\n";

    //-=
    it3r--;
    while (*it3r > 0.0)
    {
        std::cout << *it3r << " ";
        it3r -= 1;
    }
    std::cout << "\n";

    it3r--;
    while (*it3r > 0.0)
    {
        std::cout << *it3r << " ";
        it3r -= 1;
    }
    std::cout << "\n";

    citr3--;
    while (*citr3 > 0.0)
    {
        std::cout << *citr3 << " ";
        citr3 -= 1;
    }
    std::cout << "\n";

    //+=
    while (&*it3r != ref_it3r)
    {
        std::cout << *it3r << " ";
        it3r += 1;
    }
    std::cout << "\n";

     //+=
    while (&*citr3 != ref_it3r)
    {
        std::cout << *citr3 << " ";
        citr3 += 1;
    }
    std::cout << "\n";

    // = -=
    while (*it3r > 0.0)
    {
        std::cout << *it3r << " ";
        it3r = it3r -= 1;
    }
    std::cout << "\n";

     // = -=
    while (*citr3 > 0.0)
    {
        std::cout << *citr3 << " ";
        citr3 = citr3 -= 1;
    }
    std::cout << "\n";

    //= +=
    while (&*it3r != ref_it3r)
    {
        std::cout << *it3r << " ";
        it3r = it3r += 1;
    }
    std::cout << "\n";

    while (&*citr3 != ref_it3r)
    {
        std::cout << *citr3 << " ";
        citr3 = citr3 += 1;
    }
    std::cout << "\n";

    //--
    while (*it3r > 0.0)
    {
        --it3r;
        std::cout << *it3r << " ";
    }
    std::cout << "\n";

    //--
    while (*citr3 > 0.0)
    {
        --citr3;
        std::cout << *citr3 << " ";
    }
    std::cout << "\n";

    //++
    while (&*++it3r != ref_it3r)
    {
        std::cout << *it3r << " ";
    }
    std::cout << "\n";

    //++
    while (&*++citr3 != ref_it3r)
    {
        std::cout << *citr3 << " ";
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

    //no const const
    std::cout << (it2r_neq < citr2) << " ";
    std::cout << (citr2 <= it2r_neq) << " ";
    std::cout << (citr2 >= it2r_neq) << " ";
    std::cout << (citr2 > it2r_neq) << " ";
    std::cout << (citr2 == it2r_neq) << " ";
    std::cout << (citr2 != it2r_neq) << " ";
    std::cout << (citr2 != it2r_neq) << " ";
    std::cout << "\n";

    //const const
    std::cout << (citr3 < citr2) << " ";
    std::cout << (citr2 <= citr3) << " ";
    std::cout << (citr2 >= citr3) << " ";
    std::cout << (citr2 > citr3) << " ";
    std::cout << (citr2 == citr3) << " ";
    std::cout << (citr2 != citr3) << " ";
    std::cout << (citr2 != citr3) << " ";
    std::cout << "\n";

    //*citr = *citr;
    //*cit = *cit;*/
    return (0);
}
