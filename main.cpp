#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <utility>
#include "map.hpp"
/*#include "vector.hpp"*/

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

void    func(const int &a, const int &b)
{
    std::cout << a << b << "\n";
}

int main()
{
    size_t                      i = 0;
    /*std::pair<char, char>               pr1('q', 32), pr2('e', 1), pr3('w', 21), pr4('v', 43), pr5('s', 66), pr6('a', 81),
                                        pr7('p', 19);
    std::pair<char, char>           tab[] = {pr1, pr2, pr3, pr4, pr5, pr6, pr7};
    std::map<char, char>            map(tab, tab + 3); 
    std::map<char, char>::iterator  it(map.end());

    std::cout << map.insert(it, pr6)->first << "\n";*/

    func(i, ++i);

    return 0;
}