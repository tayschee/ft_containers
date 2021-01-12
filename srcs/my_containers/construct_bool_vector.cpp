#include "vector.hpp"
#include <iostream>
#include <string>

int main(int argc, char **av)
{
    size_t  i;
    ft::vector<bool> vec_bool;
    ft::vector<bool> vec_bool1(0, 7);
    ft::vector<bool> vec_bool2(0);
    ft::vector<bool> vec_bool3(98, 0);
    ft::vector<bool> vec_bool4(28, 1);
    ft::vector<bool> vec_bool5(1187);
    ft::vector<bool> vec_bool6(808043);
    ft::vector<bool> vec_bool7(4560123, 1);

    (void)av;
    std::cout << "VECTOR bool" << std::endl << std::endl;
    
    std::cout << "default constructeur :\n";
    for(i = 0; i < vec_bool.size(); i++)
    {
        std::cout << vec_bool[i] << std::endl;
    }
    std::cout << "\n" << vec_bool.size() << std::endl;
    std::cout << vec_bool.max_size() << std::endl;
    std::cout << vec_bool.capacity() << std::endl << "\n";

    std::cout << "1 :\n";
    for(i = 0; i < vec_bool1.size(); i++)
    {
        std::cout << vec_bool1[i] << std::endl;
    }
    std::cout << "\n" << vec_bool1.size() << std::endl;
    std::cout << vec_bool1.max_size() << std::endl;
    std::cout << vec_bool1.capacity() << std::endl;

    std::cout << "2 :\n";
    for(i = 0; i < vec_bool2.size(); i++)
    {
        std::cout << vec_bool2[i] << std::endl;
    }
    std::cout << "\n" << vec_bool2.size() << std::endl;
    std::cout << vec_bool2.max_size() << std::endl;
    std::cout << vec_bool2.capacity() << std::endl << "\n";

    std::cout << "3 :\n";
    for(i = 0; i < vec_bool3.size(); i++)
    {
        std::cout << vec_bool3[i] << std::endl;
    }
    std::cout << "\n" << vec_bool3.size() << std::endl;
    std::cout << vec_bool3.max_size() << std::endl;
    std::cout << vec_bool3.capacity() << std::endl << "\n";

    std::cout << "4 :\n";
    for(i = 0; i < vec_bool4.size(); i++)
    {
        std::cout << vec_bool4[i] << " ";
    }
    std::cout << "\n" << vec_bool4.size() << std::endl;
    std::cout << vec_bool4.max_size() << std::endl;
    std::cout << vec_bool4.capacity() << std::endl << "\n";

    std::cout << "5 :\n";
    for(i = 0; i < vec_bool5.size(); i++)
    {
        std::cout << vec_bool5[i] << " ";
    }
    std::cout << "\n" << vec_bool5.size() << std::endl;
    std::cout << vec_bool5.max_size() << std::endl;
    std::cout << vec_bool5.capacity() << std::endl << "\n";

    if (argc > 1)
    {
        std::cout << "6 :\n";
        for(i = 0; i < vec_bool6.size(); i++)
        {
            std::cout << vec_bool6[i];
        }
        std::cout << std::endl;
        std::cout << "\n" << vec_bool6.size() << std::endl;
        std::cout << vec_bool6.max_size() << std::endl;
        std::cout << vec_bool6.capacity() << std::endl << "\n";

        std::cout << "7 :\n";
        for(i = 0; i < vec_bool7.size(); i++)
        {
            std::cout << vec_bool7[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "\n" << vec_bool7.size() << std::endl;
        std::cout << vec_bool7.max_size() << std::endl;
        std::cout << vec_bool7.capacity() << std::endl << "\n";
    }
}
