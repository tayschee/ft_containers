#include "vector.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h> //sleep

template<typename T>
void print(ft::vector<T> &vec, T val, size_t x)
{
    size_t i;

    try
    {
        while(x--)
            vec.push_back(val);
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

template<typename T>
void print(ft::vector<T> &vec, size_t x)
{
    size_t i;

    try
    {
        while (x--)
            vec.pop_back();
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

template<typename T>
void print(ft::vector<T *> &vec, T *val, size_t x)
{
    size_t i;
    size_t j;

    try
    {
        while (x--)
            vec.push_back(val);
        for(i = 0; 1; i++)
        {
            for (j = 0; vec.at(i)[j] != 0; j++)
                std::cout << vec.at(i)[j] << " ";
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
        std::cout << *vec.front() << "\n";
        std::cout << *vec.back() << "\n";
        std::cout << **vec.begin() << "\n";
        std::cout << **--vec.end() << "\n";
        std::cout << **vec.rbegin() << "\n";
        std::cout << **--vec.rend() << "\n";
    }
    std::cout << "\n";
}

template<typename T>
void print(ft::vector<T *> &vec, size_t x)
{
    size_t i;
    size_t j;

    try
    {
        while (x--)
            vec.pop_back();
        for(i = 0; 1; i++)
        {
            for (j = 0; vec.at(i)[j] != 0; j++)
                std::cout << vec.at(i)[j] << " ";
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
        //std::cout << *vec.front() << "\n";
        std::cout << *vec.back() << "\n";
        std::cout << **vec.begin() << "\n";
        std::cout << **--vec.end() << "\n";
        std::cout << **vec.rbegin() << "\n";
        std::cout << **--vec.rend() << "\n";
    }
    std::cout << "\n";
}

int main()
{
    int x1 = 101;
    int x2 = 402; 
    int x3 = 81;
    int x4 = 457;
    int x5 = 62;
    std::string    tab[]= {"abcde", "des mots", "orange", "rouge", "fruits", "lozere", "entourloupe", "youpi", ""};
    ft::vector<int> vec1(x1, 89);
    ft::vector<char> vec2(x2, '$');
    ft::vector<std::string> vec3(x3, "texte tres long de toute facon il y a peu d'affichage");


    double             tab4[] = {12.4, 13.2, 62.3, 18012.1, 63.90, 42.42, 808.17, 245.1, 92.1, 1.18, 2.37, 803.8, 235.9,
    401.6, 442.17, 8992.21, -608.17, -200005.9, -708, -97.8, -998.21, 12.7, -9.8, 82.5, 5.55, -954.6};
    ft::vector<double>::iterator beg4(tab4);
    ft::vector<double>::iterator end4(&tab4[26]);
    ft::vector<double> vec4(beg4, end4);

    int                 *tab5 = new int[14];
    int                 tab6[] = {12, 26, 87, 48, 12, 0};
    int                 tab7[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 16, 18, 22, 84, -102, -98, 3, 0};
    int                 tab8[] = {-2, -6, 0};
    size_t           i;
    for(i = 0; i < 14; i++)
        tab5[i] = i * 2;
    tab5[i - 1] = 0;
    ft::vector<int *>::iterator beg5(&tab5);
    ft::vector<int *>::iterator end5(&++tab5);
    ft::vector<int *> vec5(beg5, end5);

    //int
    print(vec1, 18, 3);
    print(vec1, 96, 1);
    print(vec1, 109, 16);
    print(vec1, 1, 12);
    print(vec1, 2218, 3);
    print(vec1, 2561, 14);
    print(vec1, 1802, 90);
    print(vec1, 128, 43);
    print(vec1, 1, 2);
    print(vec1, 16);
    print(vec1, 95);
    print(vec1, 18);
    print(vec1, 42, 27);
    print(vec1, 8);

    //char
    print(vec2, 402);
    print(vec2, 'X', 21);
    print(vec2, 'W', 341);
    print(vec2, 80);
    print(vec2, 'J', 8);
    print(vec2, 'e', 16);
    print(vec2, 'u', 1);

    //std::string
    print(vec3, static_cast<std::string>("rage"), 81);
    print(vec3, static_cast<std::string>("mesopotamie"), 74);
    print(vec3, 150);
    print(vec3, 23);
    print(vec3, 3);
    print(vec3, static_cast<std::string>("delete"), 10);
    print(vec3, 70); //si je me suis pas trompe dans mes compte
    print(vec3, static_cast<std::string>("to be continued"), 1);

    print(vec4, 0.0, 10000);
    print(vec4, 8000);
    print(vec4, 400);
    print(vec4, 1.1, 800);
    print(vec4, -1892.12, 811);
    print(vec4, 1);
    print(vec4, 2);
    print(vec4, 3);


    print(vec5, tab5, 2);
    print(vec5, tab5, 2);
    print(vec5, tab6, 12);
    print(vec5, 14);
    print(vec5, tab7, 6);
    print(vec5, tab8, 9);
    print(vec5, 12);

    delete[] --tab5;
   

    
    return (0);
}
