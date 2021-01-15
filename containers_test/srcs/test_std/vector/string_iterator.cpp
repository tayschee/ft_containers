#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

int main()
{
    size_t      i;
    std::string        c = "mot";
    std::string         tab[] = {"je", " ", "teste", "encore", "et", "encore", ""};
    std::string         tab1[901];
    std::string         tab2[10] = {"oui", "non", "quinoa", "banane", "mail", "clavier", "huitre", "soupe", "loutre"};
    for (i = 0; i < 901; i++)
    {
        if (i == 900)
            tab1[i] = "";
        else
            tab1[i] = tab2[std::rand() % 10] + tab2[std::rand() % 10] + tab2[std::rand() % 10];
        
    }
    std::vector<std::string>::iterator  it;
    std::vector<std::string>::iterator  it1(&c);
    std::vector<std::string>::iterator  it2(tab);
    std::vector<std::string>::iterator  it3(tab1);
    std::vector<std::string>::iterator  it2_eq(it2);
    std::vector<std::string>::iterator  it2_neq(tab + 1);
    std::vector<std::string>::iterator::reference ref_it2 = *it2;
    std::vector<std::string>::iterator::pointer ref_it3 = &*it3;

    (void)it;
    std::cout << *it1 << "\n";
    std::cout << *it2 << "\n";

    //[]
    for (i = 0; it2[i] != ""; i++)
        std::cout << it2[i] << " ";
    std::cout << "\n";

    //*++(n)
    while (*it2 != "")
        std::cout << *it2++ << " ";
    std::cout << "\n";
    
    //*--(n)
    while (*it2 != ref_it2)
        std::cout << *it2-- << " ";
    std::cout << "\n";

    //*++
    while (*it2 != "")
        std::cout << *++it2 << " ";
    std::cout << "\n";

    //*--
    while (*it2 != ref_it2)
        std::cout << *--it2 << " ";
    std::cout << "\n";

    // + n
    for (i = 0; *(it2 + i) != ""; i++)
        std::cout << *(it2 + i) << " ";
    std::cout << "\n";

    //++(n)
    while (*it3 != "")
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
    while (*it3 != "")
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
    while (*it3 != "")
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
    while (*it3 != "")
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
