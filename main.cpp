#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <utility>
/*#include "map.hpp"
#include "vector.hpp"*/

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
    char                                 tab[] = "drtfyguhjkjhbgvgbh";
    char                                 tab1[] = "drtfyguhjkjhbgvgbh";
    std::vector<char>::const_iterator vec(tab);
    std::vector<char>::const_iterator vec1(tab1);

    *vec++;
    *vec1+= 7;

    return 0;
}