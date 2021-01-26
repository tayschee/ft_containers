#include "vector.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h> //sleep

template<typename T>
void print(ft::vector<T> &vec1)
{
    size_t i;

    try
    {
        for(i = 0; i < vec1.size(); i++)
            std::cout << vec1[i] << " ";
        std::cout << "\n";
        std::cout << vec1.max_size() << "\n";
        std::cout << vec1.size() << "\n";
        std::cout << vec1.capacity() << "\n";
        std::cout << vec1.empty() << "\n";
        if (i > 0)
        {
            std::cout << vec1.front() << "\n";
            std::cout << vec1.back() << "\n";
            std::cout << *vec1.begin() << "\n";
            std::cout << *--vec1.end() << "\n";
            std::cout << *vec1.rbegin() << "\n";
            std::cout << *--vec1.rend() << "\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

template<typename T>
void print(ft::vector<T> &vec1, ft::vector<T> &vec2)
{
    size_t i;

    try
    {
        for(i = 0; i < vec1.size(); i++)
            std::cout << vec1[i] << " ";
        std::cout << "\n";
        std::cout << vec1.max_size() << "\n";
        std::cout << vec1.size() << "\n";
        std::cout << vec1.capacity() << "\n";
        std::cout << vec1.empty() << "\n";
        if (i > 0)
        {
            std::cout << vec1.front() << "\n";
            std::cout << vec1.back() << "\n";
            std::cout << *vec1.begin() << "\n";
            std::cout << *--vec1.end() << "\n";
            std::cout << *vec1.rbegin() << "\n";
            std::cout << *--vec1.rend() << "\n";
        }

        for(i = 0; i < vec2.size(); i++)
            std::cout << vec2[i] << " ";
        std::cout << "\n";
        std::cout << vec2.max_size() << "\n";
        std::cout << vec2.size() << "\n";
        std::cout << vec2.capacity() << "\n";
        std::cout << vec2.empty() << "\n";
        if (i > 0)
        {
            std::cout << vec2.front() << "\n";
            std::cout << vec2.back() << "\n";
            std::cout << *vec2.begin() << "\n";
            std::cout << *--vec2.end() << "\n";
            std::cout << *vec2.rbegin() << "\n";
            std::cout << *--vec2.rend() << "\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

template<typename T>
void print(ft::vector<T *> &vec1, ft::vector<T *> &vec2)
{
    size_t i;
    size_t j;

    try
    {
        for(i = 0; i < vec1.size(); i++)
        {
            for(j = 0; vec1[i][j] > 0; j++)
                std::cout << vec1[i][j] << " ";
        }
        std::cout << "\n";
        std::cout << vec1.max_size() << "\n";
        std::cout << vec1.size() << "\n";
        std::cout << vec1.capacity() << "\n";
        std::cout << vec1.empty() << "\n";
        if (i > 0)
        {
            std::cout << *vec1.front() << "\n";
            std::cout << *vec1.back() << "\n";
            std::cout << **vec1.begin() << "\n";
            std::cout << **--vec1.end() << "\n";
            std::cout << **vec1.rbegin() << "\n";
            std::cout << **--vec1.rend() << "\n";
        }

        for(i = 0; i < vec2.size(); i++)
        {
            for(j = 0; vec2[i][j] > 0; j++)
                std::cout << vec2[i][j] << " ";
        }
        std::cout << "\n";
        std::cout << vec2.max_size() << "\n";
        std::cout << vec2.size() << "\n";
        std::cout << vec2.capacity() << "\n";
        std::cout << vec2.empty() << "\n";
        if (i > 0)
        {
            std::cout << *vec2.front() << "\n";
            std::cout << *vec2.back() << "\n";
            std::cout << **vec2.begin() << "\n";
            std::cout << **--vec2.end() << "\n";
            std::cout << **vec2.rbegin() << "\n";
            std::cout << **--vec2.rend() << "\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
}

template<typename T>
void print(ft::vector<T *> &vec1)
{
    size_t i;
    size_t j;

    try
    {
        for(i = 0; i < vec1.size(); i++)
        {
            for(j = 0; vec1[i][j] > 0; j++)
                std::cout << vec1[i][j] << " ";
        }
        std::cout << "\n";
        std::cout << vec1.max_size() << "\n";
        std::cout << vec1.size() << "\n";
        std::cout << vec1.capacity() << "\n";
        std::cout << vec1.empty() << "\n";
        if (i > 0)
        {
            std::cout << *vec1.front() << "\n";
            std::cout << *vec1.back() << "\n";
            std::cout << **vec1.begin() << "\n";
            std::cout << **--vec1.end() << "\n";
            std::cout << **vec1.rbegin() << "\n";
            std::cout << **--vec1.rend() << "\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
}

int main()
{
    int x1 = 18;
    int x2 = 817; 
    int x3 = 201;
    int x4 = 4002;

    int     tab13[] = {12, 32, 64, 128, 296, 31901, -145, -2891, -18, -27, 36};
    int     tab14[] = {121, 322, 643, -123, -216, 901, -1451, 891, 1832, 27901, 36184, 734, 522, 7521, 72, -25, -5256,
    -235, 1563, 25923, 20601, -54320, -1352, -3259, 1537, 13728, 18291, 183, 0217, 4691, 610, -145, 7581, 5675123,
    -124542, -14, 5678, 76312, 7193, 8753, -234};
    ft::vector<int>::iterator beg13(tab13);
    ft::vector<int>::iterator end13(&tab13[11]);
    ft::vector<int>::iterator beg14(tab14);
    ft::vector<int>::iterator end14(&tab14[41]);
    ft::vector<int> vec1;
    ft::vector<int> vec11(x1, 27);
    ft::vector<int> vec12(x1 + 88, -21);
    ft::vector<int> vec13(beg13, end13);
    ft::vector<int> vec14(beg14, end14);

    char     tab23[] = "fdbo123eq'[p412 qewas][3    mji[j2341rhnoehni3pu2h4513pb53b43bqwren ds']/.';ds,kmwkae4235a";
    char     tab24[] = "uhegjfadn";
    ft::vector<char>::iterator beg23(tab23);
    ft::vector<char>::iterator end23(&tab23[91]);
    ft::vector<char>::iterator beg24(tab24);
    ft::vector<char>::iterator end24(&tab24[10]);
    ft::vector<char> vec2;
    ft::vector<char> vec21(x2, 'X');
    ft::vector<char> vec22(x2 + 3, 'Y');
    ft::vector<char> vec23(beg23, end23);
    ft::vector<char> vec24(beg24, end24);

    std::string     tab33[] = {"test", "singulier", "qu'est ce que", "j'en", "ai", "marre", "abuser", "comme ", "c'est", "relou"};
    std::string     tab34[] = {"oui", "fioup", "plouf"};
    ft::vector<std::string>::iterator beg33(tab33);
    ft::vector<std::string>::iterator end33(&tab33[10]);
    ft::vector<std::string>::iterator beg34(tab34);
    ft::vector<std::string>::iterator end34(&tab34[3]);
    ft::vector<std::string> vec3;
    ft::vector<std::string> vec31(x3, "olalala");
    ft::vector<std::string> vec32(x3 + 51, "rate");
    ft::vector<std::string> vec33(beg33, end33);
    ft::vector<std::string> vec34(beg34, end34);

    int    tab411[] = {32, 27, 28, 161, 248, -17, -21, -218, 3451, 812, 410, 82, -22, 135325, -53452, 1235, 8395, 3582, 513, 0};
    int    tab412[] = {1, 2, 3, 4, 5, 12, 27, -5, -92, -218, 5, -22, 0};
    int    tab413[] = {-127, -128, -129, 0};
    int    tab414[] = {100, 1092, -126, 239, 8096, 122, 0};
    int    tab415[] = {1, 1, 1, 1, 1, 1,1 ,1, 1, 1, 1,1 ,6, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
    int    *tab43[] = {tab411, tab412, tab413, tab414, tab415};
    int    *tab44[] = {tab411, tab412, tab413, tab414, tab415, tab415, tab414, tab413, tab412, tab411};
    ft::vector<int *>::iterator beg43(tab43);
    ft::vector<int *>::iterator end43(&tab43[5]);
    ft::vector<int *>::iterator beg44(tab44);
    ft::vector<int *>::iterator end44(&tab44[10]);
    ft::vector<int *> vec4;
    ft::vector<int *> vec41(x4, tab411);
    ft::vector<int *> vec42(x4 + 122, tab413);
    ft::vector<int *> vec43(beg43, end43);
    ft::vector<int *> vec44(beg44, end44);

    //int
    print(vec1, vec11);
    vec1.swap(vec11);
    print(vec1, vec11);
    ft::swap(vec11, vec1);
    print(vec1, vec11);

    vec12.swap(vec11);
    print(vec12, vec11);
    ft::swap(vec11, vec12);
    print(vec12, vec11);

    vec13.swap(vec14);
    print(vec13, vec14);
    vec14.swap(vec13);
    print(vec13, vec14);

    ft::swap(vec13, vec12);
    print(vec13, vec12);
    ft::swap(vec1, vec12);
    print(vec12, vec1);
    vec1.swap(vec11);
    print(vec1, vec11);

    //char
    print(vec2, vec21);
    vec2.swap(vec21);
    print(vec2, vec21);
    ft::swap(vec21, vec2);
    print(vec2, vec21);

    vec22.swap(vec21);
    print(vec22, vec21);
    ft::swap(vec21, vec22);
    print(vec22, vec21);

    vec23.swap(vec24);
    print(vec23, vec24);
    vec24.swap(vec23);
    print(vec23, vec24);

    ft::swap(vec23, vec22);
    print(vec23, vec22);
    ft::swap(vec2, vec22);
    print(vec22, vec2);
    vec2.swap(vec21);
    print(vec2, vec21);

    //string
    print(vec3, vec31);
    vec3.swap(vec31);
    print(vec3, vec31);
    ft::swap(vec31, vec3);
    print(vec3, vec31);

    vec32.swap(vec31);
    print(vec32, vec31);
    ft::swap(vec31, vec32);
    print(vec32, vec31);

    vec33.swap(vec34);
    print(vec33, vec34);
    vec34.swap(vec33);
    print(vec33, vec34);

    ft::swap(vec33, vec32);
    print(vec33, vec32);
    ft::swap(vec3, vec32);
    print(vec32, vec3);
    vec3.swap(vec31);
    print(vec3, vec31);

    //int *
    print(vec4, vec41);
    vec4.swap(vec41);
    print(vec4, vec41);
    ft::swap(vec41, vec4);
    print(vec4, vec41);

    vec42.swap(vec41);
    print(vec42, vec41);
    ft::swap(vec41, vec42);
    print(vec42, vec41);

    vec43.swap(vec44);
    print(vec43, vec44);
    vec44.swap(vec43);
    print(vec43, vec44);

    ft::swap(vec43, vec42);
    print(vec43, vec42);
    ft::swap(vec4, vec42);
    print(vec42, vec4);
    vec4.swap(vec41);
    print(vec4, vec41);

    //clear
    vec1.clear();
    print(vec1);
    vec11.clear();
    print(vec11);
    vec12.clear();
    print(vec12);
    vec13.clear();
    print(vec13);
    vec14.clear();
    print(vec14);

    vec2.clear();
    print(vec2);
    vec21.clear();
    print(vec21);
    vec22.clear();
    print(vec22);
    vec23.clear();
    print(vec23);
    vec24.clear();
    print(vec24);

    vec3.clear();
    print(vec3);
    vec31.clear();
    print(vec31);
    vec32.clear();
    print(vec32);
    vec33.clear();
    print(vec33);
    vec34.clear();
    print(vec34);

    vec4.clear();
    print(vec4);
    vec41.clear();
    print(vec41);
    vec42.clear();
    print(vec42);
    vec43.clear();
    print(vec43);
    vec44.clear();
    print(vec44);


    return (0);
}
