#include "vector.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h> //sleep

template<typename T>
void print(ft::vector<T> &vec, size_t pos, const T &val)
{
    size_t i;

    try
    {
        typename ft::vector<T>::iterator it_pos(vec.begin() + pos);
        typename ft::vector<T>::iterator verif_it;
        verif_it = vec.insert(it_pos, val);
        while (verif_it != vec.end())
            std::cout << *verif_it++ << " ";
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    for(i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
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
void print(ft::vector<T> &vec, size_t pos, size_t n, const T &val)
{
    size_t i;

    try
    {
        typename ft::vector<T>::iterator it_pos(vec.begin() + pos);
        typename ft::vector<T>::iterator verif_it;
        vec.insert(it_pos, n, val);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    for(i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
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
void print(ft::vector<T *> &vec, size_t pos, size_t n, T *val)
{
    size_t i;

    try
    {
        typename ft::vector<T *>::iterator it_pos(vec.begin() + pos);
        typename ft::vector<T *>::iterator verif_it;
        vec.insert(it_pos, n, val);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    for(i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
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
void print(ft::vector<T *> &vec, size_t pos, T *val)
{
    size_t i;

    try
    {
        typename ft::vector<T *>::iterator it_pos(vec.begin() + pos);
        typename ft::vector<T *>::iterator verif_it;
        verif_it = vec.insert(it_pos, val);
        while (verif_it != vec.end())
            std::cout << *verif_it++ << " ";
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    for(i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
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


int main()
{
    int x1 = 48;
    int x2 = 422; 
    int x3 = 5006;
    int x4 = 18;
    char    tab1[] = "Aou";
    char    tab2[] = "isothermique";
    char    tab3[] = "excellent";
    char    tab4[] = "ouiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiI";
    char    tab5[] = "0123456789";
    char    tab6[] = "mission";
    char    tab7[] = "cleopatre";
    char    *tab[] = {tab1, tab2, tab3, tab4};
    ft::vector<char *>::iterator beg4(tab);
    ft::vector<char *>::iterator end4(&tab[4]);

    ft::vector<int> vec1(x1, -47);
    ft::vector<char> vec2(x2, 'c');
    ft::vector<std::string> vec3(x3, "yup");
    ft::vector<char *> vec4(beg4, end4);

    //int //insert(it pos, val)
    print(vec1, 6, 18);
    print(vec1, 1, 9);
    print(vec1, 50, 21);
    print(vec1, 21, 3);
    print(vec1, 0, 67);
    print(vec1, 0, -891);
    vec1.resize(32);
    print(vec1, 0, -32);
    vec1.resize(32);
    print(vec1, 32, 80812);
    vec1.resize(58);
    print(vec1, 21, 781246);

    //char //insert(it pos, val)
    print(vec2, 80, 'X');
    print(vec2, 121, '6');
    print(vec2, 50, 'l');
    print(vec2, 0, '0');
    vec2.resize(420);
    print(vec2, 0, '3');
    vec2.resize(420);
    print(vec2, 420, '8');
    vec2.resize(128);
    print(vec2, 114, '-');

    //string //insert(it pos, val)
    print(vec3, 3006, static_cast<std::string>("oupssssssssssssS"));
    print(vec3, 4001, static_cast<std::string>("sale"));
    print(vec3, 808, static_cast<std::string>("ouip"));
    print(vec3, 0, static_cast<std::string>("omega"));
    vec3.resize(4200);
    print(vec3, 4200, static_cast<std::string>("j'en ai marre!!!! c'est long -_-"));
    vec3.resize(4200);
    print(vec3, 0, static_cast<std::string>("OP"));
    vec3.resize(3608);
    print(vec3, 2095, static_cast<std::string>("--------------A"));

    //char * //insert(it pos, val)
    print(vec4, 2, tab5);
    print(vec4, 1, tab3);
    print(vec4, 1, tab6);
    print(vec4, 0, tab4);
    vec4.resize(4);
    print(vec4, 4, tab7);
    vec4.resize(4);
    print(vec4, 0, tab3);
    vec4.resize(5);
    print(vec4, 4, tab4);

    //int insert (pos, n, val)
    print(vec1, 59, 0, -32);
    print(vec1, 59, 1, -32);
    print(vec1, 60, 20, 58);
    print(vec1, 0, 0, 10294);
    print(vec1, 0, 1, 10294);
    print(vec1, 0, 8, 7);
    print(vec1, 26, 1, 8);
    print(vec1, 68, 6, 24);
    print(vec1, 41, 0, 24);
    vec1.resize(60);
    print(vec1, 60, 500, 56); //ici
    vec1.resize(60);
    print(vec1, 60, 0, 82);
    vec1.resize(60);
    print(vec1, 60, 1, -194);
    vec1.resize(60);
    print(vec1, 0, 29, 4402);
    vec1.resize(60);
    print(vec1, 0, 0, 44);
    vec1.resize(60);
    print(vec1, 0, 98, 44);
    vec1.resize(60);
    print(vec1, 27, 311, 8);
    vec1.resize(60);
    print(vec1, 27, 18, 2242);

    //char insert (pos, n, val)
    print(vec2, 129, 0, 'X');
    print(vec2, 129, 1, 'U');
    print(vec2, 129, 28, '-');
    print(vec2, 0, 0, '[');
    print(vec2, 0, 1, '"');
    print(vec2, 0, 16, ';');
    print(vec2, 26, 1, '|');
    print(vec2, 68, 22, 'A');
    print(vec2, 41, 0, 'a');
    vec2.resize(100);
    print(vec2, 100, 37, '*'); 
    vec2.resize(100);
    print(vec2, 100, 0, '?');
    vec2.resize(100);
    print(vec2, 100, 1, '\\');
    vec2.resize(100);
    print(vec2, 0, 72, '~');
    vec2.resize(100);
    print(vec2, 0, 0, '^');
    vec2.resize(100);
    print(vec2, 0, 1, 'J');
    vec2.resize(100);
    print(vec2, 83, 311, 'L');
    vec2.resize(100);
    print(vec2, 9, 18, 'Q');

    //string insert (pos, n, val)
    print(vec3, 3609, 0, static_cast<std::string>("objs"));
    print(vec3, 3609, 1, static_cast<std::string>("1234567890"));
    print(vec3, 3609, 9, static_cast<std::string>("T_T"));
    print(vec3, 0, 0, static_cast<std::string>("oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo"));
    print(vec3, 0, 1, static_cast<std::string>("O+O"));
    print(vec3, 0, 236, static_cast<std::string>("[]"));
    print(vec3, 26, 1, static_cast<std::string>("p"));
    print(vec3, 68, 98, static_cast<std::string>("********_______++++++++!"));
    print(vec3, 41, 0, static_cast<std::string>("opa"));
    vec3.resize(1100);
    print(vec3, 1100, 1500, static_cast<std::string>("puis")); 
    vec3.resize(1100);
    print(vec3, 1100, 0, static_cast<std::string>("allez"));
    vec3.resize(1100);
    print(vec3, 1100, 1, static_cast<std::string>("XD"));
    vec3.resize(1100);
    print(vec3, 0, 1221, static_cast<std::string>("AAAH"));
    vec3.resize(1100);
    print(vec3, 0, 0, static_cast<std::string>("PITCH"));
    vec3.resize(1100);
    print(vec3, 0, 1, static_cast<std::string>("()()()"));
    vec3.resize(1100);
    print(vec3, 830, 1311, static_cast<std::string>("!+!"));
    vec3.resize(1100);
    print(vec3, 750, 50, static_cast<std::string>("^^"));

    //char * insert (pos, n, val)
    print(vec4, 6, 0, tab2);
    print(vec4, 6, 1, tab3);
    print(vec4, 7, 9, tab3);
    print(vec4, 0, 0, tab4);
    print(vec4, 0, 1, tab5);
    print(vec4, 0, 2, tab7);
    print(vec4, 5, 1, tab3);
    print(vec4, 6, 3, tab1);
    print(vec4, 10, 0, tab2);
    vec4.resize(10);
    std::cout << "VEC" << vec4.capacity() << "\n";
    print(vec4, 10, 27, tab4); 
   /* vec4.resize(10);
    print(vec4, 10, 0, tab2);
    vec4.resize(10);
    print(vec4, 10, 1, tab3);
    vec4.resize(10);
    print(vec4, 0, 32, tab1);
    vec4.resize(10);
    print(vec4, 0, 0, tab2);
    vec4.resize(10);
    print(vec4, 0, 3, tab3);
    vec4.resize(10);
    print(vec4, 4, 2, tab5);
    vec4.resize(10);
    print(vec4, 6, 20, tab6);*/


    

   
    
    return (0);
}
