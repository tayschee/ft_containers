#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **av)
{
    size_t      i;
    std::vector<bool> vec_bool;
    std::vector<bool> vec_bool1(0, 7);
    std::vector<bool> vec_bool2(0);
    std::vector<bool> vec_bool3(98, 0);
    std::vector<bool> vec_bool4(28, 1);
    std::vector<bool> vec_bool5(1187);
    std::vector<bool> vec_bool6(808043);
    std::vector<bool> vec_bool7(4560123, 1);
    std::vector<bool> vec_bool8(1);
    std::vector<bool> vec_bool9(63);
    std::vector<bool> vec_bool10(64, 1);
    std::vector<bool> vec_bool11(65);
    std::vector<bool> vec_bool12(127);
    std::vector<bool> vec_bool13(128, 1);
    std::vector<bool> vec_bool14(129);
    std::vector<bool> vec_bool15(255);
    std::vector<bool> vec_bool16(256, 1);
    

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
    std::cout << "8 :\n";
    for(i = 0; i < vec_bool8.size(); i++)
    {
        std::cout << vec_bool8[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "\n" << vec_bool8.size() << std::endl;
    std::cout << vec_bool8.max_size() << std::endl;
    std::cout << vec_bool8.capacity() << std::endl << "\n";

    std::cout << "9 :\n";
    for(i = 0; i < vec_bool9.size(); i++)
    {
        std::cout << vec_bool9[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "\n" << vec_bool9.size() << std::endl;
    std::cout << vec_bool9.max_size() << std::endl;
    std::cout << vec_bool9.capacity() << std::endl << "\n";

    std::cout << "10 :\n";
    for(i = 0; i < vec_bool10.size(); i++)
    {
        std::cout << vec_bool10[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "\n" << vec_bool10.size() << std::endl;
    std::cout << vec_bool10.max_size() << std::endl;
    std::cout << vec_bool10.capacity() << std::endl << "\n";

    std::cout << "11 :\n";
    for(i = 0; i < vec_bool11.size(); i++)
    {
        std::cout << vec_bool11[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "\n" << vec_bool11.size() << std::endl;
    std::cout << vec_bool11.max_size() << std::endl;
    std::cout << vec_bool11.capacity() << std::endl << "\n";

    std::cout << "12 :\n";
    for(i = 0; i < vec_bool12.size(); i++)
    {
        std::cout << vec_bool12[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "\n" << vec_bool12.size() << std::endl;
    std::cout << vec_bool12.max_size() << std::endl;
    std::cout << vec_bool12.capacity() << std::endl << "\n";

    std::cout << "13 :\n";
    for(i = 0; i < vec_bool13.size(); i++)
    {
        std::cout << vec_bool13[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "\n" << vec_bool13.size() << std::endl;
    std::cout << vec_bool13.max_size() << std::endl;
    std::cout << vec_bool13.capacity() << std::endl << "\n";

    std::cout << "14 :\n";
    for(i = 0; i < vec_bool14.size(); i++)
    {
        std::cout << vec_bool14[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "\n" << vec_bool14.size() << std::endl;
    std::cout << vec_bool14.max_size() << std::endl;
    std::cout << vec_bool14.capacity() << std::endl << "\n";

    std::cout << "15 :\n";
    for(i = 0; i < vec_bool15.size(); i++)
    {
        std::cout << vec_bool15[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "\n" << vec_bool15.size() << std::endl;
    std::cout << vec_bool15.max_size() << std::endl;
    std::cout << vec_bool15.capacity() << std::endl << "\n";

    std::cout << "16 :\n";
    for(i = 0; i < vec_bool16.size(); i++)
    {
        std::cout << vec_bool16[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "\n" << vec_bool16.size() << std::endl;
    std::cout << vec_bool16.max_size() << std::endl;
    std::cout << vec_bool16.capacity() << std::endl << "\n";

}