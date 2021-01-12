#include "vector.hpp"
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char **v)
{
    size_t             i;
    size_t              j;
    std::vector<int> vec_int;
    std::vector<int> vec_int_0_3(0, 3);
    std::vector<int> vec_int_0(0);
    std::vector<int> vec_int_2_3(2, 3);
    std::vector<int> vec_int_8_6(8, 6);
    std::vector<int> vec_int_4(4);
    std::vector<int> vec_int_8000000(800000);
    std::vector<int> vec_int_12349_intmax(12349, 2147483647);

    (void)v;
    std::cout << "VECTOR INT" << std::endl << std::endl;
    
    std::cout << "default constructeur :\n";
    for(i = 0; i < vec_int.size(); i++)
    {
        std::cout << vec_int[i] << std::endl;
    }
    std::cout << "\n" << vec_int.size() << std::endl;
    std::cout << vec_int.max_size() << std::endl;
    std::cout << vec_int.capacity() << std::endl << "\n";

    std::cout << "0, 3 :\n";
    for(i = 0; i < vec_int_0_3.size(); i++)
    {
        std::cout << vec_int_0_3[i] << std::endl;
    }
    std::cout << "\n" << vec_int_0_3.size() << std::endl;
    std::cout << vec_int_0_3.max_size() << std::endl;
    std::cout << vec_int_0_3.capacity() << std::endl;

    std::cout << "0 :\n";
    for(i = 0; i < vec_int_0.size(); i++)
    {
        std::cout << vec_int_0[i] << std::endl;
    }
    std::cout << "\n" << vec_int_0.size() << std::endl;
    std::cout << vec_int_0.max_size() << std::endl;
    std::cout << vec_int_0.capacity() << std::endl << "\n";

    std::cout << "2, 3 :\n";
    for(i = 0; i < vec_int_2_3.size(); i++)
    {
        std::cout << vec_int_2_3[i] << std::endl;
    }
    std::cout << "\n" << vec_int_2_3.size() << std::endl;
    std::cout << vec_int_2_3.max_size() << std::endl;
    std::cout << vec_int_2_3.capacity() << std::endl << "\n";

    std::cout << "8 6 :\n";
    for(i = 0; i < vec_int_8_6.size(); i++)
    {
        std::cout << vec_int_8_6[i] << std::endl;
    }
    std::cout << "\n" << vec_int_8_6.size() << std::endl;
    std::cout << vec_int_8_6.max_size() << std::endl;
    std::cout << vec_int_8_6.capacity() << std::endl << "\n";

    std::cout << "4 :\n";
    for(i = 0; i < vec_int_4.size(); i++)
    {
        std::cout << vec_int_4[i] << std::endl;
    }
    std::cout << "\n" << vec_int_4.size() << std::endl;
    std::cout << vec_int_4.max_size() << std::endl;
    std::cout << vec_int_4.capacity() << std::endl << "\n";

    if (argc > 1)
    {
        std::cout << "8000000 :\n";
        for(i = 0; i < vec_int_8000000.size(); i++)
        {
            std::cout << vec_int_8000000[i];
        }
        std::cout << std::endl;
        std::cout << "\n" << vec_int_8000000.size() << std::endl;
        std::cout << vec_int_8000000.max_size() << std::endl;
        std::cout << vec_int_8000000.capacity() << std::endl << "\n";

        std::cout << "12349, intmax :\n";
        for(i = 0; i < vec_int_12349_intmax.size(); i++)
        {
            std::cout << vec_int_12349_intmax[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "\n" << vec_int_12349_intmax.size() << std::endl;
        std::cout << vec_int_12349_intmax.max_size() << std::endl;
        std::cout << vec_int_12349_intmax.capacity() << std::endl << "\n";
    }

    std::vector<char> vec_char;
    std::vector<char> vec_char_0_9(0, 'c');
    std::vector<char> vec_char_0(0);
    std::vector<char> vec_char_4_c(4, 'c');
    std::vector<char> vec_char_12_e(12, 'e');
    std::vector<char> vec_char_90(90);
    std::vector<char> vec_char_16004(16004);
    std::vector<char> vec_char_456012_(456012, '{');

    std::cout << "VECTOR char" << std::endl << std::endl;
    
    std::cout << "default constructeur :\n";
    for(i = 0; i < vec_char.size(); i++)
    {
        std::cout << vec_char[i] << std::endl;
    }
    std::cout << "\n" << vec_char.size() << std::endl;
    std::cout << vec_char.max_size() << std::endl;
    std::cout << vec_char.capacity() << std::endl << "\n";

    std::cout << "0, 3 :\n";
    for(i = 0; i < vec_char_0_9.size(); i++)
    {
        std::cout << vec_char_0_9[i] << std::endl;
    }
    std::cout << "\n" << vec_char_0_9.size() << std::endl;
    std::cout << vec_char_0_9.max_size() << std::endl;
    std::cout << vec_char_0_9.capacity() << std::endl;

    std::cout << "0 :\n";
    for(i = 0; i < vec_char_0.size(); i++)
    {
        std::cout << vec_char_0[i] << std::endl;
    }
    std::cout << "\n" << vec_char_0.size() << std::endl;
    std::cout << vec_char_0.max_size() << std::endl;
    std::cout << vec_char_0.capacity() << std::endl << "\n";

    std::cout << "2, 3 :\n";
    for(i = 0; i < vec_char_4_c.size(); i++)
    {
        std::cout << vec_char_4_c[i] << std::endl;
    }
    std::cout << "\n" << vec_char_4_c.size() << std::endl;
    std::cout << vec_char_4_c.max_size() << std::endl;
    std::cout << vec_char_4_c.capacity() << std::endl << "\n";

    std::cout << "8 6 :\n";
    for(i = 0; i < vec_char_12_e.size(); i++)
    {
        std::cout << vec_char_12_e[i] << std::endl;
    }
    std::cout << "\n" << vec_char_12_e.size() << std::endl;
    std::cout << vec_char_12_e.max_size() << std::endl;
    std::cout << vec_char_12_e.capacity() << std::endl << "\n";

    std::cout << "4 :\n";
    for(i = 0; i < vec_char_90.size(); i++)
    {
        std::cout << vec_char_90[i] << std::endl;
    }
    std::cout << "\n" << vec_char_90.size() << std::endl;
    std::cout << vec_char_90.max_size() << std::endl;
    std::cout << vec_char_90.capacity() << std::endl << "\n";

    if (argc > 1)
    {
        std::cout << "8000000 :\n";
        for(i = 0; i < vec_char_16004.size(); i++)
        {
            std::cout << vec_char_16004[i];
        }
        std::cout << std::endl;
        std::cout << "\n" << vec_char_16004.size() << std::endl;
        std::cout << vec_char_16004.max_size() << std::endl;
        std::cout << vec_char_16004.capacity() << std::endl << "\n";

        std::cout << "12349, charmax :\n";
        for(i = 0; i < vec_char_456012_.size(); i++)
        {
            std::cout << vec_char_456012_[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "\n" << vec_char_456012_.size() << std::endl;
        std::cout << vec_char_456012_.max_size() << std::endl;
        std::cout << vec_char_456012_.capacity() << std::endl << "\n";
    }

    std::vector<std::string> vec_str;
    std::vector<std::string> vec_str1(0, "salami");
    std::vector<std::string> vec_str2(0);
    std::vector<std::string> vec_str3(9, "orang outan");
    std::vector<std::string> vec_str4(14, "marsupilami");
    std::vector<std::string> vec_str5(112);
    std::vector<std::string> vec_str6(8080);
    std::vector<std::string> vec_str7(456012, "ca on s'en fout");

    std::cout << "VECTOR STR" << std::endl << std::endl;
    
    std::cout << "default constructeur :\n";
    for(i = 0; i < vec_str.size(); i++)
    {
        std::cout << vec_str[i] << std::endl;
    }
    std::cout << "\n" << vec_str.size() << std::endl;
    std::cout << vec_str.max_size() << std::endl;
    std::cout << vec_str.capacity() << std::endl << "\n";

    std::cout << "1 :\n";
    for(i = 0; i < vec_str1.size(); i++)
    {
        std::cout << vec_str1[i] << std::endl;
    }
    std::cout << "\n" << vec_str1.size() << std::endl;
    std::cout << vec_str1.max_size() << std::endl;
    std::cout << vec_str1.capacity() << std::endl;

    std::cout << "2 :\n";
    for(i = 0; i < vec_str2.size(); i++)
    {
        std::cout << vec_str2[i] << std::endl;
    }
    std::cout << "\n" << vec_str2.size() << std::endl;
    std::cout << vec_str2.max_size() << std::endl;
    std::cout << vec_str2.capacity() << std::endl << "\n";

    std::cout << "3 :\n";
    for(i = 0; i < vec_str3.size(); i++)
    {
        std::cout << vec_str3[i] << std::endl;
    }
    std::cout << "\n" << vec_str3.size() << std::endl;
    std::cout << vec_str3.max_size() << std::endl;
    std::cout << vec_str3.capacity() << std::endl << "\n";

    std::cout << "4 :\n";
    for(i = 0; i < vec_str4.size(); i++)
    {
        std::cout << vec_str4[i] << std::endl;
    }
    std::cout << "\n" << vec_str4.size() << std::endl;
    std::cout << vec_str4.max_size() << std::endl;
    std::cout << vec_str4.capacity() << std::endl << "\n";

    std::cout << "5 :\n";
    for(i = 0; i < vec_str5.size(); i++)
    {
        std::cout << vec_str5[i] << std::endl;
    }
    std::cout << "\n" << vec_str5.size() << std::endl;
    std::cout << vec_str5.max_size() << std::endl;
    std::cout << vec_str5.capacity() << std::endl << "\n";

    if (argc > 1)
    {
        std::cout << "6 :\n";
        for(i = 0; i < vec_str6.size(); i++)
        {
            std::cout << vec_str6[i];
        }
        std::cout << std::endl;
        std::cout << "\n" << vec_str6.size() << std::endl;
        std::cout << vec_str6.max_size() << std::endl;
        std::cout << vec_str6.capacity() << std::endl << "\n";

        std::cout << "7 :\n";
        for(i = 0; i < vec_str7.size(); i++)
        {
            std::cout << vec_str7[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "\n" << vec_str7.size() << std::endl;
        std::cout << vec_str7.max_size() << std::endl;
        std::cout << vec_str7.capacity() << std::endl << "\n";
    }

    std::vector<double> vec_double;
    std::vector<double> vec_double1(0, 12.12);
    std::vector<double> vec_double2(0);
    std::vector<double> vec_double3(9, 128.43);
    std::vector<double> vec_double4(14, 16.3);
    std::vector<double> vec_double5(112);
    std::vector<double> vec_double6(8080);
    std::vector<double> vec_double7(456012, 16800.653);

    std::cout << "VECTOR DOUBLE" << std::endl << std::endl;
    
    std::cout << "default constructeur :\n";
    for(i = 0; i < vec_double.size(); i++)
    {
        std::cout << vec_double[i] << std::endl;
    }
    std::cout << "\n" << vec_double.size() << std::endl;
    std::cout << vec_double.max_size() << std::endl;
    std::cout << vec_double.capacity() << std::endl << "\n";

    std::cout << "1 :\n";
    for(i = 0; i < vec_double1.size(); i++)
    {
        std::cout << vec_double1[i] << std::endl;
    }
    std::cout << "\n" << vec_double1.size() << std::endl;
    std::cout << vec_double1.max_size() << std::endl;
    std::cout << vec_double1.capacity() << std::endl;

    std::cout << "2 :\n";
    for(i = 0; i < vec_double2.size(); i++)
    {
        std::cout << vec_double2[i] << std::endl;
    }
    std::cout << "\n" << vec_double2.size() << std::endl;
    std::cout << vec_double2.max_size() << std::endl;
    std::cout << vec_double2.capacity() << std::endl << "\n";

    std::cout << "3 :\n";
    for(i = 0; i < vec_double3.size(); i++)
    {
        std::cout << vec_double3[i] << std::endl;
    }
    std::cout << "\n" << vec_double3.size() << std::endl;
    std::cout << vec_double3.max_size() << std::endl;
    std::cout << vec_double3.capacity() << std::endl << "\n";

    std::cout << "4 :\n";
    for(i = 0; i < vec_double4.size(); i++)
    {
        std::cout << vec_double4[i] << std::endl;
    }
    std::cout << "\n" << vec_double4.size() << std::endl;
    std::cout << vec_double4.max_size() << std::endl;
    std::cout << vec_double4.capacity() << std::endl << "\n";

    std::cout << "5 :\n";
    for(i = 0; i < vec_double5.size(); i++)
    {
        std::cout << vec_double5[i] << std::endl;
    }
    std::cout << "\n" << vec_double5.size() << std::endl;
    std::cout << vec_double5.max_size() << std::endl;
    std::cout << vec_double5.capacity() << std::endl << "\n";

    if (argc > 1)
    {
        std::cout << "6 :\n";
        for(i = 0; i < vec_double6.size(); i++)
        {
            std::cout << vec_double6[i];
        }
        std::cout << std::endl;
        std::cout << "\n" << vec_double6.size() << std::endl;
        std::cout << vec_double6.max_size() << std::endl;
        std::cout << vec_double6.capacity() << std::endl << "\n";

        std::cout << "7 :\n";
        for(i = 0; i < vec_double7.size(); i++)
        {
            std::cout << vec_double7[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "\n" << vec_double7.size() << std::endl;
        std::cout << vec_double7.max_size() << std::endl;
        std::cout << vec_double7.capacity() << std::endl << "\n";
    }

    int     test[4] = {12345, 653, 980, 1234};
    char    test1[] = "abcdefghijklmnopqrstuvwxyz";
    double  test2[] = {123.3, 54.1, 654.33, 5678.6, 5.3, 1.1};
    std::string test3[] = {"tres", "confiant", "de", "ce", "test"};
    std::vector<void *> vec_void;
    std::vector<void *> vec_void1(0, test);
    std::vector<void *> vec_void2(0);
    std::vector<void *> vec_void3(93, NULL);
    std::vector<void *> vec_void4(709, test1);
    std::vector<void *> vec_void5(1187);
    std::vector<void *> vec_void6(808043);
    std::vector<void *> vec_void7(4560123, test2);

    std::cout << "VECTOR void" << std::endl << std::endl;
    
    std::cout << "default constructeur :\n";
    for(i = 0; i < vec_void.size(); i++)
    {
        std::cout << vec_void[i] << std::endl;
    }
    std::cout << "\n" << vec_void.size() << std::endl;
    std::cout << vec_void.max_size() << std::endl;
    std::cout << vec_void.capacity() << std::endl << "\n";

    std::cout << "1 :\n";
    for(i = 0; i < vec_void1.size(); i++)
    {
        std::cout << vec_void1[i] << std::endl;
    }
    std::cout << "\n" << vec_void1.size() << std::endl;
    std::cout << vec_void1.max_size() << std::endl;
    std::cout << vec_void1.capacity() << std::endl;

    std::cout << "2 :\n";
    for(i = 0; i < vec_void2.size(); i++)
    {
        std::cout << vec_void2[i] << std::endl;
    }
    std::cout << "\n" << vec_void2.size() << std::endl;
    std::cout << vec_void2.max_size() << std::endl;
    std::cout << vec_void2.capacity() << std::endl << "\n";

    std::cout << "3 :\n";
    for(i = 0; i < vec_void3.size(); i++)
    {
        std::cout << vec_void3[i] << std::endl;
    }
    std::cout << "\n" << vec_void3.size() << std::endl;
    std::cout << vec_void3.max_size() << std::endl;
    std::cout << vec_void3.capacity() << std::endl << "\n";

    std::cout << "4 :\n";
    for(i = 0; i < vec_void4.size(); i++)
    {
        for(j = 0; j < 26; j++)
            std::cout << static_cast<char *>(vec_void4[i])[j] << " ";
    }
    std::cout << "\n" << vec_void4.size() << std::endl;
    std::cout << vec_void4.max_size() << std::endl;
    std::cout << vec_void4.capacity() << std::endl << "\n";

    std::cout << "5 :\n";
    for(i = 0; i < vec_void5.size(); i++)
    {
        std::cout << vec_void5[i] << " ";
    }
    std::cout << "\n" << vec_void5.size() << std::endl;
    std::cout << vec_void5.max_size() << std::endl;
    std::cout << vec_void5.capacity() << std::endl << "\n";

    if (argc > 1)
    {
        std::cout << "6 :\n";
        for(i = 0; i < vec_void6.size(); i++)
        {
            std::cout << vec_void6[i];
        }
        std::cout << std::endl;
        std::cout << "\n" << vec_void6.size() << std::endl;
        std::cout << vec_void6.max_size() << std::endl;
        std::cout << vec_void6.capacity() << std::endl << "\n";

        std::cout << "7 :\n";
        for(i = 0; i < vec_void7.size(); i++)
        {
            for(j = 0; j < 6; j++)
                std::cout << static_cast<double *>(vec_void7[i])[j] << " ";
        }
        std::cout << std::endl;
        std::cout << "\n" << vec_void7.size() << std::endl;
        std::cout << vec_void7.max_size() << std::endl;
        std::cout << vec_void7.capacity() << std::endl << "\n";
    }

    /*std::vector<bool> vec_bool;
    std::vector<bool> vec_bool1(0, 7);
    std::vector<bool> vec_bool2(0);
    std::vector<bool> vec_bool3(98, 0);
    std::vector<bool> vec_bool4(28, 1);
    std::vector<bool> vec_bool5(1187);
    std::vector<bool> vec_bool6(808043);
    std::vector<bool> vec_bool7(4560123, 1);

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
    }*/
}