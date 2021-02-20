#include "vector.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h> //sleep

struct a
{
    float j;
};

template<typename T>
void print(ft::vector<T> &vec, size_t x)
{
    size_t i;

    try
    {
        typename ft::vector<T>::iterator it(&vec[x]);
        typename ft::vector<T>::iterator ret;
        ret = vec.erase(it);
        while (ret != vec.end())
            std::cout << *ret++ << " ";
        std::cout << "\n";
        for(i = 0; 1; i++)
        {
            std::cout << vec.at(i) << " ";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    std::cout << vec.max_size() << "\n";
    std::cout << vec.size() << "\n";
    std::cout << vec.capacity() << "\n";
    std::cout << vec.empty() << "\n";
    if (i > 0)
    {
        std::cout << vec.front() << "\n";
        std::cout << vec.back() << "\n";
        std::cout << *vec.begin() << "\n";
        std::cout << *--vec.end() << "\n";
        std::cout << *vec.rbegin() << "\n";
        std::cout << *--vec.rend() << "\n";
    }
    std::cout << "\n";
}

template<typename T>
void print(ft::vector<T> &vec, size_t x, size_t y)
{
    size_t i;

    try
    {
        typename ft::vector<T>::iterator beg(&vec[x]);
        typename ft::vector<T>::iterator end(&vec[y]);
        typename ft::vector<T>::iterator ret;
        ret = vec.erase(beg, end);
        while (ret != vec.end())
            std::cout << *ret++ << " ";
        std::cout << "\n";
        for(i = 0; 1; i++)
            std::cout << vec.at(i) << " ";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    std::cout << vec.max_size() << "\n";
    std::cout << vec.size() << "\n";
    std::cout << vec.capacity() << "\n";
    std::cout << vec.empty() << "\n";
    if (i > 0)
    {
        std::cout << vec.front() << "\n";
        std::cout << vec.back() << "\n";
        std::cout << *vec.begin() << "\n";
        std::cout << *--vec.end() << "\n";
        std::cout << *vec.rbegin() << "\n";
        std::cout << *--vec.rend() << "\n";
    }
    std::cout << "\n";
}

void print(ft::vector<struct a> &vec, size_t x)
{
    size_t i;

    try
    {
        typename ft::vector<struct a>::iterator it(&vec[x]);
        typename ft::vector<struct a>::iterator ret;
        ret = vec.erase(it);
        while (ret != vec.end())
            std::cout << (*ret++).j << " ";
        std::cout << "\n";
        for(i = 0; 1; i++)
        {
            std::cout << vec.at(i).j << " ";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    std::cout << vec.max_size() << "\n";
    std::cout << vec.size() << "\n";
    std::cout << vec.capacity() << "\n";
    std::cout << vec.empty() << "\n";
    if (i > 0)
    {
        std::cout << vec.front().j << "\n";
        std::cout << vec.back().j << "\n";
        std::cout << (*vec.begin()).j << "\n";
        std::cout << (*--vec.end()).j << "\n";
        std::cout << (*vec.rbegin()).j << "\n";
        std::cout << (*--vec.rend()).j << "\n";
    }
    std::cout << "\n";
}

void print(ft::vector<struct a> &vec, size_t x, size_t y)
{
    size_t i;

    try
    {
        typename ft::vector<struct a>::iterator beg(&vec[x]);
        typename ft::vector<struct a>::iterator end(&vec[y]);
        typename ft::vector<struct a>::iterator ret;
        ret = vec.erase(beg, end);
        while (ret != vec.end())
            std::cout << (*ret++).j << " ";
        std::cout << "\n";
        for(i = 0; 1; i++)
        {
            std::cout << vec.at(i).j << " ";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    std::cout << vec.max_size() << "\n";
    std::cout << vec.size() << "\n";
    std::cout << vec.capacity() << "\n";
    std::cout << vec.empty() << "\n";
    if (i > 0)
    {
        std::cout << vec.front().j << "\n";
        std::cout << vec.back().j << "\n";
        std::cout << (*vec.begin()).j << "\n";
        std::cout << (*--vec.end()).j << "\n";
        std::cout << (*vec.rbegin()).j << "\n";
        std::cout << (*--vec.rend()).j << "\n";
    }
    std::cout << "\n";
}

int main()
{
    int x1 = 241;
    int x2 = 801; 
    int x3 = 72;
    int x4 = 112;
    int x5 = 8;
    int    tab1[] = {218, -92, 8081, 218, -29, 1097, 921, 823012, 932, -9212, 80, 88, 21, 38, -19, -1255, 48256, -37, 8923, -217}; //18
    ft::vector<int>::iterator beg1(tab1);
    ft::vector<int>::iterator end1(&tab1[20]);
    ft::vector<int> vec1(beg1, end1);
    int    tab11[]= {9, 712, 821, 14, -291}; //5
    ft::vector<int>::iterator beg11(tab11);
    ft::vector<int>::iterator end11(&tab11[5]);
    ft::vector<int> vec11(beg11, end11);
    ft::vector<int> vec12(x1, 12);

    char    tab2[] = "bouyachaka miyachaka oupalinda";
    ft::vector<char>::iterator beg2(tab2);
    ft::vector<char>::iterator end2(&tab2[31]);
    ft::vector<char> vec2(x2, 'W');
    ft::vector<char> vec21(beg2, end2);

    std::string         tab3[] = {"bebe", "ne", "revient", "pas", "prend", "tes", "affaires", "rentre", "chez", "toi" };
    ft::vector<std::string>::iterator beg3(tab3);
    ft::vector<std::string>::iterator end3(&tab3[10]);
    ft::vector<std::string> vec3(beg3, end3);
    ft::vector<std::string> vec31(x3, "OOOHHH!!!");

    struct a            tab4 = {4.2f};
    struct a            tab41[] = {{4.2f}, {-8.12f}, {-93.7f}, {-105.19}, {112.4f}, {2202.5f}, {8404.9f}, {2008.6f}, {-14.6f}};
    ft::vector<struct a>::iterator beg41(tab41);
    ft::vector<struct a>::iterator end41(&tab41[9]);
    ft::vector<struct a> vec4(x4, tab4); 
    ft::vector<struct a> vec41(beg41, end41);

    //int
    print(vec1, 19);
    print(vec1, 12);
    print(vec1, 11);
    print(vec1, 1);
    print(vec1, 0);
    print(vec1, 9);
    print(vec1, 6);
    //
    print(vec1, 8, 10);
    print(vec1, 0, 4);
    print(vec1, 1, 2);
    print(vec1, 2, 2);
    //print(vec1, 26); seg
    //print(vec1, 10, 2); ind

    print(vec11, 0);
    print(vec11, 1);
    print(vec11, 2);
    print(vec11, 1);
    print(vec11, 0);
    print(vec11, 0, 0);
    vec11.push_back(5); vec11.push_back(5); vec11.push_back(2); vec11.push_back(1); vec11.push_back(3);
    print(vec11, 2, 4);
    print(vec11, 0, 3);

    print(vec12, 200);
    print(vec12, 210);
    print(vec12, 231);
    print(vec12, 0, 25);
    print(vec12, 111, 132);
    print(vec12, 41, 43);
    print(vec12, 22, 22);
    print(vec12, 70, 170);
    //print(vec12, 0, 255); seg
    //print(vec12, 255, 0); seg


    //char
    print(vec2, 412, 800);
    print(vec2, 51, 72);
    print(vec2, 49, 49);
    print(vec2, 50, 51);
    print(vec2, 22, 254);

    print(vec21, 30);
    print(vec21, 5, 15);
    print(vec21, 7, 12);
    print(vec21, 12);
    print(vec21, 8);
    print(vec21, 0, 13);

    
    //std::string
    print(vec31, 42, 50);
    print(vec31, 18, 31);
    print(vec31, 10, 12);
    print(vec31, 21, 21);;
    print(vec31, 0, 1);
    print(vec31, 0);
    print(vec31, 26);
    print(vec31, 21);
    print(vec31, 0, vec3.size());

    print(vec3, 4);
    print(vec3, 6);
    print(vec3, 4, 8);
    print(vec3, 0, 4);
    print(vec3, 0, 0);

    //struct a
    print(vec4, 111, 112);
    print(vec4, 12);
    print(vec4, 36);
    print(vec4, 94);
    print(vec4, 23, 46);
    print(vec4, 57, 59);
    print(vec4, 8, 31);

    print(vec41, 0, 1);
    print(vec41, 3);
    print(vec41, 0, 5);
    print(vec41, 0, 2);


    return (0);
}
