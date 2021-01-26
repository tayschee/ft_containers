#include "vector.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h> //sleep

template<typename T>
void print(ft::vector<T> &vec, size_t x, size_t y, T *tab)
{
    size_t i;

    try
    {
        typename ft::vector<T>::iterator beg(&tab[x]);
        typename ft::vector<T>::iterator end(&tab[y]);
        vec.assign(beg, end);
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
void print(ft::vector<T> &vec, size_t x, const T &val)
{
    size_t i;

    try
    {
        vec.assign(x, val);
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
void print(ft::vector<T *> &vec, size_t x, size_t y, T *tab)
{
    size_t i;
    size_t j;

    try
    {
        typename ft::vector<T>::iterator beg(&tab[x]);
        typename ft::vector<T>::iterator end(&tab[y]);
        vec.assign(beg, end);
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
void print(ft::vector<T *> &vec, size_t x, T *val)
{
    size_t i;
    size_t j;

    try
    {
        vec.assign(x, val);
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

int main()
{
    int x2 = 761; 
    int x4 = 29;
    int x5 = 8;
    int    tab1[]= {101, -92, 808, 218, -29, 1097, 921, 8000000, 932, -9212, 80, 88, 21, -30, -19, -1255, 48256, -37}; //18
    int    tab11[]= {8, 100, 81, 218, -29, 1097, -921, 8012, 936, -9212, 81}; //11
    int    tab12[]= {29, 211, 908, 95, 37, -1909, 18012003, 491202391, -444, 94, 99, 50}; //12
    int    tab13[] = {1, 2, 3, 4, 5}; //5
    int    tab14[] = {1, 0}; //2
    ft::vector<int>::iterator beg1(tab12);
    ft::vector<int>::iterator end1(&tab12[11]);
    ft::vector<int> vec1(beg1, end1);

    char    tab2[] = "test2qualite";
    char    tab21[] = "ODD";
    char    tab22[] = "absoluteqwertyjtrgewqhtegfdejeyjioeqjroqiendiniervdnbvijbefigerbqnpiberiwbripgbanibnfgiwebngreirbnegijwnrijbfneiwbnigfrbgi;bgeipwowt539pq34a;ownfgq3phorht5p9rnjgiowhrp942h3iqwbnep'k][q[eQJFOJQfjeiorwgibnweiubriabeb34i2g9gv8rb23yq9gr";
    char    tab23[] = "18000000001234563    254236";
    ft::vector<char> vec2(x2, ':');

    std::string         tab3[] = {"moulaga", "push", "emberlificote", "cesar", "periode", "gros", "adoubement"};
    std::string         tab31[] = {"rien", "a", "dire"};
    std::string         tab32[] = {"ok", "."};
    std::string         tab33[] = {"gros", "nickel", "bien", "ou", "bien", "street", "la", "wesh", "a", "z"};
    ft::vector<std::string>::iterator beg3(tab3);
    ft::vector<std::string>::iterator end3(&tab3[5]);
    ft::vector<std::string> vec3(beg3, end3);

    size_t              i;
    double              tab4[651];
    for (i = 0; i < 651; i++)
        tab4[i] = static_cast<double>(i) * 2.45;
    double              tab41[] = {28.2, -41.8, 72.0, 89.28, 2212.9, -4099.27};
    ft::vector<double> vec4(x4, -89.18);
    char                tab5[] = "un message a communique";
    char                tab51[] = "un second msg";
    char                tab52[] = "un text";
    char                tab53[] = "un sms";
    char                *tab54[] = {tab5, tab51, tab52, tab53, tab53, tab53, tab53, tab52, tab51, tab52, tab5, tab5, tab52, tab52};
    ft::vector<char *> vec5(x5, tab5);

    //int
    print(vec1, 0, 11, tab1); //=
    print(vec1, 0, 12, tab11); // +
    print(vec1, 0, 11, tab12); // -
    print(vec1, 0, 2, tab14); //-
    print(vec1, 0, 2, tab11); //=
    print(vec1, 15, 16, tab1);//-
    print(vec1, 1, 1, tab14); //- && 0
    print(vec1, 1, 3, tab13); //+
    print(vec1, 0, 8, tab1);//+
    print(vec1, 0, 16, tab1);//+
    print(vec1, 0, 16, tab11);//=
    print(vec1, 0, 0, tab13);//0
    print(vec1, 2, 10, tab12);//+
    print(vec1, 800, 1, tab1); //error
    print(vec1, 15, 1, tab1); //error
    print(vec1, 1000, 1000, tab12); //0
    print(vec1, 120341, 120341, tab12); //0
    //print(vec1, 1, 100, tab1); //indetermine

    print(vec1, 1, 2);//+
    print(vec1, 16, 8);//+
    print(vec1, 16, 2);//=
    print(vec1, 3, 99);//-
    print(vec1, 0, 0);//- 0
    print(vec1, 18552, 442);//+
    print(vec1, 20000, 6);//+
    print(vec1, 5, 12);//-


    //char
    print(vec2, 761, '>'); //=
    print(vec2, 439, ';'); //-
    print(vec2, 0, 'X');//- 0
    print(vec2, 24, 'e');//+
    print(vec2, 12, 'e');//-
    print(vec2, 0, 'j');//- 0

    print(vec2, 0, 13, tab2); //+
    print(vec2, 0, 4, tab21); //-
    print(vec2, 12, 28, tab23); //+
    print(vec2, 5202, '*'); //+
    print(vec2, 0, 233, tab22);//-
    print(vec2, 233, 0, tab22);//indetermine
    print(vec2, 2002, 2002, tab22);//-

    //std::string
    print(vec3, 0, 7, tab3);//=
    print(vec3, 1, 7, tab3);//-
    print(vec3, 3, 6, tab33);//+
    print(vec3, 2, 9, tab33);//+
    print(vec3, 0, 10, tab33);//+
    print(vec3, 1, 3, tab31);//-
    print(vec3, 1, 2, tab32);//-
    print(vec3, 10, 10, tab33);//-
    print(vec3, 21234, 21234, tab33);//0
    print(vec3, 98, 98, tab31);//0
    print(vec3, 21235, 21234, tab33);//0
    print(vec3, 18001282, 62014, tab31);//0 

    print(vec3, 3, static_cast<std::string>("YOP"));//-
    print(vec3, 0, static_cast<std::string>("YOP2"));//- 0
    print(vec3, 0, static_cast<std::string>("YOP2"));//= 0
    print(vec3, 1, static_cast<std::string>("geox"));//+
    print(vec3, 6, static_cast<std::string>("la chaussure"));//+
    print(vec3, 25012, static_cast<std::string>("qui respire"));//+
    print(vec3, 25012, static_cast<std::string>("nike"));//=
    print(vec3, 1114, static_cast<std::string>("just do it"));//+

    //double
    print(vec4, 0, 22.22);//--
    print(vec4, 12, 27.98);//++
    print(vec4, 400, 92.47);//++
    print(vec4, 8, 639, tab4);//++
    print(vec4, 0, 72, tab4);//--
    print(vec4, 72, 81.8);//=
    print(vec4, 0, 6, tab41);//-
    print(vec4, 0, 2, tab41);//-
    print(vec4, 0, 6, tab41);//-
    print(vec4, 291, 6086.27);
    print(vec4, 0, 651, tab4);//++
    print(vec4, 430, 12.19);//--
    print(vec4, 27, 8, tab41);//ind
    print(vec4, 98, 98, tab41);//0

    //void *
    print(vec5, 12, (tab52));//++
    print(vec5, 3,  (tab5));//--
    print(vec5, 0,  (tab51));//--
    print(vec5, 4, (tab53));//++;
    print(vec5, 4, (tab52));//++;
    print(vec5, 0, 14, (tab54));//++
    print(vec5, 6, 12, (tab54));//--
    print(vec5, 50, (tab52));//++
    print(vec5, 9, 12, (tab54));//--


    return (0);
}
