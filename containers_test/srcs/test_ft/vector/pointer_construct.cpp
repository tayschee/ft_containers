#include "vector.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    size_t           i;
    size_t           j;
    size_t           x = 405;
    char            tab[] = "abcdefghijklmopqrstuvwxyz";
    int             tab1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0};
    double          tab2[] = {1.1, 2.2, 3.3, 4.4, -6.1};
    std::string     tab3[] = {"une", "phrase", "ecrite", ""};
    int             tab4[] = {10, 20, 30, 40, 50, 60, 0};
    double          tab5[] = {1.111111, 2.222222, 3.333333, 4.4444444, 5.5555555, 6.6666666, 7.777777, -1.0};
    std::string     tab6[] = {"une", "nouvelle", "phrase", ""};
    char            tab7[] = "0123457890";

    ft::vector<void *> vec;
    ft::vector<void *> vec1(0);
    ft::vector<void *> vec2(67);
    ft::vector<void *> vec3(811);
    ft::vector<void *> vec4(21, tab);
    ft::vector<void *> vec5(x, tab1);
    ft::vector<void *> vec6(2973, tab2);
    ft::vector<void *> vec7(60578, tab3);
    ft::vector<void *> vec8(vec4);
    ft::vector<void *> vec9(vec5);
    ft::vector<void *> vec10(vec6);
    ft::vector<void *> vec11(vec3);

    (void)argc;
    std::cout << "VECTOR void *" << std::endl << std::endl;
    
    std::cout << "0 :\n";
    for(i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << vec.size() << std::endl;
    std::cout << vec.max_size() << std::endl;
    std::cout << vec.empty() << std::endl;
    std::cout << vec.capacity() << std::endl << "\n";
    std::cout << std::endl;

    std::cout << "1 :\n";
    for(i = 0; i < vec1.size(); i++)
    {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << vec1.size() << std::endl;
    std::cout << vec1.max_size() << std::endl;
    std::cout << vec1.empty() << std::endl;
    std::cout << vec1.capacity() << std::endl;
    std::cout << std::endl;

    std::cout << "2 :\n";
    for(i = 0; i < vec2.size(); i++)
    {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;
    std::cout << vec2.size() << std::endl;
    std::cout << vec2.max_size() << std::endl;
    std::cout << vec2.empty() << std::endl;
    std::cout << vec2.capacity() << std::endl;
    std::cout << std::endl;

    if (argv[1] && argv[1][0] == '1')
    {
        std::cout << "3 :\n";
        for(i = 0; i < vec3.size(); i++)
        {
            std::cout << vec3[i] << " ";
        }
        std::cout << std::endl;
        std::cout << vec3.size() << std::endl;
        std::cout << vec3.max_size() << std::endl;
        std::cout << vec3.empty() << std::endl;
        std::cout << vec3.capacity() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "4 :\n";
    for(i = 0; i < vec4.size(); i++)
    {
        for(j = 0; static_cast<char *>(vec4[i])[j] != 0; j++)
        {
            std::cout << static_cast<char *>(vec4[i])[j] << " ";
        }
        std::cout << "-- ";
    }
    std::cout << std::endl;
    std::cout << vec4.size() << std::endl;
    std::cout << vec4.max_size() << std::endl;
    std::cout << vec4.empty() << std::endl;
    std::cout << vec4.capacity() << std::endl;
    std::cout << std::endl;

    std::cout << "5 :\n";
    for(i = 0; i < vec5.size(); i++)
    {
        for(j = 0; static_cast<int *>(vec5[i])[j] != 0; j++)
        {
            std::cout << static_cast<int *>(vec5[i])[j] << " ";
        }
        std::cout << "-- ";
    }
    std::cout << std::endl;
    std::cout << vec5.size() << std::endl;
    std::cout << vec5.max_size() << std::endl;
    std::cout << vec5.empty() << std::endl;
    std::cout << vec5.capacity() << std::endl;
    std::cout << std::endl;

    std::cout << "6 :\n";
    for(i = 0; i < vec6.size(); i++)
    {
         for(j = 0; static_cast<double *>(vec6[i])[j] > 0; j++)
        {
            std::cout << static_cast<double *>(vec6[i])[j] << " ";
        }
        std::cout << "-- ";
    }
    std::cout << std::endl;
    std::cout << vec6.size() << std::endl;
    std::cout << vec6.max_size() << std::endl;
    std::cout << vec6.empty() << std::endl;
    std::cout << vec6.capacity() << std::endl;
    std::cout << std::endl;

    if (argv[1] && argv[1][0] == '1')
    {
        std::cout << "7 :\n";
        for(i = 0; i < vec7.size(); i++)
        {
            for(j = 0; static_cast<std::string *>(vec7[i])[j] != ""; j++)
            {
                std::cout << static_cast<std::string *>(vec7[i])[j] << " ";
            }
            std::cout << "-- ";
        }
        std::cout << std::endl;
        std::cout << vec7.size() << std::endl;
        std::cout << vec7.max_size() << std::endl;
        std::cout << vec7.empty() << std::endl;
        std::cout << vec7.capacity() << std::endl;
        std::cout << std::endl;
    }

    //CONSTRUCTEUR PAR COPIE


    std::cout << "8 :\n";
    vec8[0] = tab7;

     for(i = 0; i < vec8.size(); i++)
    {
        for(j = 0; static_cast<char *>(vec8[i])[j] != 0; j++)
        {
            std::cout << static_cast<char *>(vec8[i])[j] << " ";
        }
        std::cout << "-- ";
    }
    std::cout << std::endl;
    std::cout << vec8.size() << std::endl;
    std::cout << vec8.max_size() << std::endl;
    std::cout << vec8.empty() << std::endl;
    std::cout << vec8.capacity() << std::endl;
    for(i = 0; i < vec4.size(); i++)
    {
        for(j = 0; static_cast<char *>(vec4[i])[j] != 0; j++)
        {
            std::cout << static_cast<char *>(vec4[i])[j] << " ";
        }
        std::cout << "-- ";
    }
    std::cout << std::endl;
    std::cout << vec4.size() << std::endl;
    std::cout << vec4.max_size() << std::endl;
    std::cout << vec4.empty() << std::endl;
    std::cout << vec4.capacity() << std::endl;
    std::cout << std::endl;
    
    std::cout << "9 :\n";
    vec9[x - 1] = tab4;

    for(i = 0; i < vec5.size(); i++)
    {
        for(j = 0; static_cast<int *>(vec5[i])[j] != 0; j++)
        {
            std::cout << static_cast<int *>(vec5[i])[j] << " ";
        }
        std::cout << "-- ";
    }
    std::cout << std::endl;
    std::cout << vec9.size() << std::endl;
    std::cout << vec9.max_size() << std::endl;
    std::cout << vec9.empty() << std::endl;
    std::cout << vec9.capacity() << std::endl;
    for(i = 0; i < vec5.size(); i++)
    {
        for(j = 0; static_cast<int *>(vec5[i])[j] != 0; j++)
        {
            std::cout << static_cast<int *>(vec5[i])[j] << " ";
        }
        std::cout << "-- ";
    }
    std::cout << std::endl;
    std::cout << vec5.size() << std::endl;
    std::cout << vec5.max_size() << std::endl;
    std::cout << vec5.empty() << std::endl;
    std::cout << vec5.capacity() << std::endl;
    std::cout << std::endl;

    std::cout << "10 :\n";
    vec10[404] = tab5;

    for(i = 0; i < vec10.size(); i++)
    {
         for(j = 0; static_cast<double *>(vec10[i])[j] > 0; j++)
        {
            std::cout << static_cast<double *>(vec10[i])[j] << " ";
        }
        std::cout << "-- ";
    }
    std::cout << std::endl;
    std::cout << vec10.size() << std::endl;
    std::cout << vec10.max_size() << std::endl;
    std::cout << vec10.empty() << std::endl;
    std::cout << vec10.capacity() << std::endl;
    for(i = 0; i < vec6.size(); i++)
    {
         for(j = 0; static_cast<double *>(vec6[i])[j] > 0; j++)
        {
            std::cout << static_cast<double *>(vec6[i])[j] << " ";
        }
        std::cout << "-- ";
    }
    std::cout << std::endl;
    std::cout << vec6.size() << std::endl;
    std::cout << vec6.max_size() << std::endl;
    std::cout << vec6.empty() << std::endl;
    std::cout << vec6.capacity() << std::endl;
    std::cout << std::endl;

    if (argv[1] && argv[1][0] == '1')
    {
        std::cout << "11 :\n";
        vec3[5008] = tab6;

        for(i = 0; i < vec11.size(); i++)
        {
            std::cout << vec11[i] << " ";
        }
        std::cout << std::endl;
        std::cout << vec11.size() << std::endl;
        std::cout << vec11.max_size() << std::endl;
        std::cout << vec11.empty() << std::endl;
        std::cout << vec11.capacity() << std::endl;
        for(i = 0; i < vec3.size(); i++)
        {
            std::cout << vec3[i] << " ";
        }
        std::cout << std::endl;
        std::cout << vec3.size() << std::endl;
        std::cout << vec3.max_size() << std::endl;
        std::cout << vec3.empty() << std::endl;
        std::cout << vec3.capacity() << std::endl;
        std::cout << std::endl;
    }
    return (0);
}