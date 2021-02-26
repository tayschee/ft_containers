#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <utility>
#include "map.hpp"
#include "list.hpp"

template<typename T>
struct  qqc
{
    bool operator() (const T &x, const T &y) const {return x<y;}
    int a;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int a7;
    int a8;
    int a9;
    int a10;
    int a11;
};

int main()
{
    size_t                      i = 0;
    std::pair<int, int>          tab1[] ={{41, 41}, {94, 94}, {18, 18}, {21, 21}, {50, 50}, {19, 19}};
    std::vector<std::pair<int, int> >::iterator it(tab1);
    std::vector<std::pair<int, int> >::iterator end(&tab1[6]);
    std::map<int, int>                          mp;
    std::map<int, int>::iterator mit(mp.begin());

    /*while(i < 8)
    {
        std::cout << (*mit++).first << " "; 
        ++i;
    }
    std::cout << "\n";*/
    i =0;
    /*while(i < 14)
    {
        std::cout << (*mit++).first << " "; 
        ++i;
    }*/
    std::cout << (*++mp.begin()).first << " "; 
    std::cout << (*mp.begin()).second << " "; 

    return 0;
}