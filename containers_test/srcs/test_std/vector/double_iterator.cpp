#include <iostream>
#include <vector>

int main()
{
    size_t      i;
    double        c = 89120.78;
    double         tab[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, -9.0};
    double         tab1[2890];
    for (i = 0; i < 2890; i++)
    {
        if (i == 2889)
            tab1[i] = -4.0;
        else
            tab1[i] = static_cast<double>(i) + static_cast<double>(i * 0.231);
        
    }
    std::vector<double>::iterator  it;
    std::vector<double>::iterator  it1(&c);
    std::vector<double>::iterator  it2(tab);
    std::vector<double>::iterator  it3(tab1);
    std::vector<double>::iterator  it2_eq(it2);
    std::vector<double>::iterator  it2_neq(tab + 1);
    std::vector<double>::iterator::reference ref_it2 = *it2;
    std::vector<double>::iterator::pointer ref_it3 = &*it3;

    (void)it;
    std::cout << *it1 << "\n";
    std::cout << *it2 << "\n";

    //[]
    for (i = 0; it2[i] >= 0; i++)
        std::cout << it2[i] << " ";
    std::cout << "\n";

    //*++(n)
    while (*it2 >= 0)
        std::cout << *it2++ << " ";
    std::cout << "\n";
    
    //*--(n)
    while (*it2 != ref_it2)
        std::cout << *it2-- << " ";
    std::cout << "\n";

    //*++
    while (*it2 >= 0)
        std::cout << *++it2 << " ";
    std::cout << "\n";

    //*--
    while (*it2 != ref_it2)
        std::cout << *--it2 << " ";
    std::cout << "\n";

    // + n
    for (i = 0; *(it2 + i) >= 0; i++)
        std::cout << *(it2 + i) << " ";
    std::cout << "\n";

    //++(n)
    while (*it3 >= 0)
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
    while (*it3 >= 0)
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
    while (*it3 >= 0)
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
    while (*it3 >= 0)
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

    return (0);
}
