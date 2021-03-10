#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <utility>
//#include "map.hpp"
#include "vector.hpp"
#include <stack>

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
    size_t                  i = 0;
    char                 tab[] = "jkdlwnjrwnjkkfwjfv";
    ft::vector<char>     vec;

    vec.insert(vec.begin(), tab, tab + 2);

    while (i < vec.size())
    {
        std::cout << vec[i++];
    }
    std::cout << "\n";
    return 0;
}