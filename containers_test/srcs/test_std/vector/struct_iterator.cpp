#include <iostream>
#include <vector>

struct a
{
    int c;
};

int main()
{
    size_t      i;
    struct a         c = {12};
    struct a         tab[] = {{5}, {9}, {8}, {0}};
    struct a         tab1[] = {{12}, {600}, {729}, {23}, {432}, {53143}, {712}, {88}, {9012}, {481}, {0}};
    struct a         tab2[] = {{12}, {3}, {1}, {5}, {0}};
    std::vector<struct a>::iterator  it;
    std::vector<struct a>::iterator  it1(&c);
    std::vector<struct a>::iterator  it2(tab);
    std::vector<struct a>::iterator  it3(tab1);
    std::vector<struct a>::iterator  it2_eq(it2);
    std::vector<struct a>::const_iterator cit;
    std::vector<struct a>::const_iterator cit1(&c);
    std::vector<struct a>::const_iterator cit1bis(it1); //it1 must inherit
    std::vector<struct a>::const_iterator cit2(tab2);
    std::vector<struct a>::iterator  it2_neq; //enleve parenthese
    std::vector<struct a>::iterator::reference ref_it2 = *it2;
    std::vector<struct a>::iterator::pointer ref_it3 = &*it3;
    std::vector<struct a>::const_iterator::reference ref_cit2 = *cit2;
    std::vector<struct a>::const_iterator::pointer point_cit2 = &*cit2;

    (void)it;
    (void)cit;
    it2_neq = it2 + 1;
    std::cout << it1->c << "\n";
    std::cout << cit1bis->c << "\n";
    it1->c = 'b';
    std::cout << it1->c << "\n";
    std::cout << it2->c << "\n";
    std::cout << cit1->c << "\n";

    //[]
    for (i = 0; it2[i].c != 0; i++)
        std::cout << it2[i].c << " ";
    std::cout << "\n";

    //const []
    for (i = 0; cit2[i].c != 0; i++)
        std::cout << cit2[i].c << " ";
    std::cout << "\n";

    //*++(n)
    while (it2->c != 0)
        std::cout << (*it2++).c << " ";
    std::cout << "\n";

    //*++(n) const
    while (cit2->c != 0)
        std::cout << (*cit2++).c << " ";
    std::cout << "\n";
    
    //*--(n)
    while (it2->c != ref_it2.c)
        std::cout << (*it2--).c << " ";
    std::cout << "\n";

    //*--(n) const
    while (cit2->c != ref_cit2.c)
        std::cout << (*cit2--).c << " ";
    std::cout << "\n";

    //*++
    while (it2->c != 0)
        std::cout << (*++it2).c << " ";
    std::cout << "\n";

    //*++ const
    while (cit2->c != 0)
        std::cout << (*++cit2).c << " ";
    std::cout << "\n";

    //*--
    while (it2->c != ref_it2.c)
        std::cout << (*--it2).c << " ";
    std::cout << "\n";

    //*-- const
    while (cit2->c != ref_cit2.c)
        std::cout << (*--cit2).c << " ";
    std::cout << "\n";

    // + n
    for (i = 0; (*(it2 + i)).c != 0; i++)
        std::cout << (*(it2 + i)).c << " ";
    std::cout << "\n";

    // + n const
    for (i = 0; (*(cit2 + i)).c != 0; i++)
        std::cout << (*(cit2 + i)).c << " ";
    std::cout << "\n";

    //++(n)
    while (it3->c != 0)
    {
        std::cout << it3->c << " ";
        it3++;
    }
    std::cout << "\n";

    //++(n) const
    while (cit2->c != 0)
    {
        std::cout << cit2->c << " ";
        cit2++;
    }
    std::cout << "\n";

     //- n const
    for (i = 0; &*(cit2 - i) != point_cit2; i++)
        std::cout << (*(cit2 - i)).c << " ";
    std::cout << "\n";

    //- n
    for (i = 0; &*(it3 - i) != ref_it3; i++)
        std::cout << (*(it3 - i)).c << " ";
    std::cout << "\n";

    //--(n)
    while (&*it3-- != ref_it3)
    {
        std::cout << it3->c << " ";
    }   
    std::cout << "\n";

    //+=
    it3++;
    while (it3->c != 0)
    {
        std::cout << it3->c << " ";
        it3 += 1;
    }
    std::cout << "\n";

    //-=
    while (&*it3 != ref_it3)
    {
        std::cout << it3->c << " ";
        it3 -= 1;
    }
    std::cout << "\n";

    // = +=
    while (it3->c != 0)
    {
        std::cout << (*it3).c << " ";
        it3 = it3 += 1;
    }
    std::cout << "\n";

    //= -=
    while (&*it3 != ref_it3)
    {
        std::cout << (*it3).c << " ";
        it3 = it3 -= 1;
    }
    std::cout << "\n";

    //++
    while (it3->c != 0)
    {
        ++it3;
        std::cout << it3->c << " ";
    }
    std::cout << "\n";

    //++ const
    while (cit2->c != 0)
    {
        ++cit2;
        std::cout << cit2->c << " ";
    }
    std::cout << "\n";

     //-- const
    while (&*--it3 != ref_it3)
    {
        std::cout << it3->c << " ";
    }
    std::cout << "\n";

    //-- const
    while (&*--cit2 != point_cit2)
    {
        std::cout << cit2->c << " ";
    }
    std::cout << "\n";

    *cit2++;
    std::cout << (it3 += (i - 1))->c << " ";
    std::cout << (it3 - 1)->c << " ";
    std::cout << (it3 -= (i - 1))->c << " ";
    std::cout << it3->c << " ";
    std::cout << (it3 += (i / 2))->c << " ";
    std::cout << it3->c << " ";
    std::cout << (it3 -= (i / 2))->c << " ";
    std::cout << it3->c << " ";
    std::cout << (it3 += (i / 5))->c << " ";
    std::cout << it3->c << " ";
    std::cout << (it3 -= (i / 5))->c << " ";
    std::cout << it3->c << " ";
    std::cout << (cit2 += 3)->c << " ";
    std::cout << cit2->c << " ";
    std::cout << (cit2 -= 3)->c << " ";
    std::cout << cit2->c << " ";

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

    std::vector<struct a>::reverse_iterator::difference_type j;
    std::vector<struct a>::reverse_iterator  itr;
    std::vector<struct a>::reverse_iterator  it1r(it1);
    std::vector<struct a>::reverse_iterator  it2r(it2);
    std::vector<struct a>::reverse_iterator  it3r(it3);
    std::vector<struct a>::reverse_iterator  it2r_eq(it2);
    std::vector<struct a>::reverse_iterator  it2r_neq;
    std::vector<struct a>::const_reverse_iterator  citr;
    std::vector<struct a>::const_reverse_iterator  citr1(cit1);
    std::vector<struct a>::const_reverse_iterator  citr2(it2r);
    std::vector<struct a>::const_reverse_iterator  citr3(it3);

    (void)itr;
    (void)citr;
    it2r_neq = it2r + 1;
    std::cout << (*--it1r).c << "\n";
    *it1r = c;
    std::cout << (*it1r).c << "\n";
    std::cout << (*--it2r).c << "\n";
    std::cout << (*--it3r).c << "\n";
    std::cout << (*--citr1).c;
    std::cout << (*--citr2).c;
    std::cout << (*--citr3).c;

    std::vector<struct a>::iterator::reference ref_it2r = *it2r;
    std::vector<struct a>::iterator::pointer ref_it3r = &*it3r;

    //[]
    for (j = 0; it2r[j].c != 0; j--)
        std::cout << it2r[j].c << " ";
    std::cout << "\n";

     for (j = 0; citr2[j].c != 0; j--)
        std::cout << citr2[j].c << " ";
    std::cout << "\n";

    for (j = 0; it3r[j].c != 0; j--)
        std::cout << it3r[j].c << " ";
    std::cout << "\n";

    for (j = 0; citr3[j].c != 0; j--)
        std::cout << citr3[j].c << " ";
    std::cout << "\n";

    //*--(n)
    while (it2r->c != 0)
        std::cout << (*it2r--).c << " ";
    std::cout << "\n";

     while (citr2->c != 0)
        std::cout << (*citr2--).c << " ";
    std::cout << "\n";
    
    //*++(n)
    while (it2r->c != ref_it2r.c)
        std::cout << (*it2r++).c << " ";
    std::cout << "\n";

     //*++(n)
    while (citr2->c != ref_it2r.c)
    {
        std::cout << ref_it2r.c << "x";
        std::cout << (*citr2++).c << " ";
    }
    std::cout << "\n";

    //*--
    while (it2r->c != 0)
        std::cout << (*--it2r).c << " ";
    std::cout << "\n";

    while (citr2->c != 0)
        std::cout << (*--citr2).c << " ";
    std::cout << "\n";

    //*++
    while (it2r->c != ref_it2r.c)
        std::cout << (*++it2r).c << " ";
    std::cout << "\n";

    //*++
    while (citr2->c != ref_it2r.c)
        std::cout << (*++citr2).c << " ";
    std::cout << "\n";

    // - n
    for (j = 0; (*(it2r + j)).c != 0; j--)
        std::cout << (*(it2r + j)).c << " ";
    std::cout << "\n";

     // - n
    for (j = 0; (*(citr2 + j)).c != 0; j--)
        std::cout << (*(citr2 + j)).c << " ";
    std::cout << "\n";

    //--(n)
    while (it3r->c != 0)
    {
        std::cout << it3r->c << " ";
        it3r--;
    }
    std::cout << "\n";

    while (citr3->c != 0)
    {
        std::cout << citr3->c << " ";
        citr3--;
    }
    std::cout << "\n";

    //+ n
    for (j = 0; &*(it3r + j) != ref_it3; j++)
        std::cout << (*(it3r + j)).c << " ";
    std::cout << "\n";

    //+ n
    for (j = 0; &*(citr3 + j) != ref_it3; j++)
        std::cout << (*(citr3 + j)).c << " ";
    std::cout << "\n";

    //++(n)
    while (&*it3r++ != ref_it3)
    {
        std::cout << it3r->c << " ";
    }   
    std::cout << "\n";

     //++(n)
    while (&*citr3++ != ref_it3)
    {
        std::cout << citr3->c << " ";
    }   
    std::cout << "\n";

    //-=
    it3r--;
    while (it3r->c != 0)
    {
        std::cout << it3r->c << " ";
        it3r -= 1;
    }
    std::cout << "\n";

    it3r--;
    while (it3r->c != 0)
    {
        std::cout << it3r->c << " ";
        it3r -= 1;
    }
    std::cout << "\n";

    citr3--;
    while (citr3->c != 0)
    {
        std::cout << citr3->c << " ";
        citr3 -= 1;
    }
    std::cout << "\n";

    //+=
    while (&*it3r != ref_it3r)
    {
        std::cout << it3r->c << " ";
        it3r += 1;
    }
    std::cout << "\n";

     //+=
    while (&*citr3 != ref_it3r)
    {
        std::cout << citr3->c << " ";
        citr3 += 1;
    }
    std::cout << "\n";

    // = -=
    while (it3r->c != 0)
    {
        std::cout << it3r->c << " ";
        it3r = it3r -= 1;
    }
    std::cout << "\n";

     // = -=
    while (citr3->c != 0)
    {
        std::cout << citr3->c << " ";
        citr3 = citr3 -= 1;
    }
    std::cout << "\n";

    //= +=
    while (&*it3r != ref_it3r)
    {
        std::cout << it3r->c << " ";
        it3r = it3r += 1;
    }
    std::cout << "\n";

    while (&*citr3 != ref_it3r)
    {
        std::cout << citr3->c << " ";
        citr3 = citr3 += 1;
    }
    std::cout << "\n";

    //--
    while (it3r->c != 0)
    {
        --it3r;
        std::cout << it3r->c << " ";
    }
    std::cout << "\n";

    //--
    while (citr3->c != 0)
    {
        --citr3;
        std::cout << citr3->c << " ";
    }
    std::cout << "\n";

    //++
    while (&*++it3r != ref_it3r)
    {
        std::cout << it3r->c << " ";
    }
    std::cout << "\n";

    //++
    while (&*++citr3 != ref_it3r)
    {
        std::cout << citr3->c << " ";
    }
    std::cout << "\n";

    std::cout << (it3r -= (j + 1))->c << " ";
    std::cout << it3r->c << " ";
    std::cout << (it3r += (j + 1))->c << " ";
    std::cout << it3r->c << " ";
    std::cout << (it3r -= (j / 2))->c << " ";
    std::cout << it3r->c << " ";
    std::cout << (it3r += (j / 2))->c << " ";
    std::cout << it3r->c << " ";
    std::cout << (it3r -= (j / 3))->c << " ";
    std::cout << it3r->c << " ";
    std::cout << (it3r += (j / 3))->c << " ";
    std::cout << it3r->c << " ";
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
    //*cit = *cit;
    return (0);
}
