#include <vector>
#include <iostream>

void    test(vector )
int main(int argc, char **argv)
{
    size_t           i;
    size_t           x = 634;
    std::vector<double> vec;
    std::vector<double> vec1(0);
    std::vector<double> vec2(81);
    std::vector<double> vec3(8012);
    std::vector<double> vec4(143, 12.901);
    std::vector<double> vec5(x, 6);
    std::vector<double> vec6(2973, 871.999);
    std::vector<double> vec7(60578, 1.1111);
    std::vector<double> vec8(vec4);
    std::vector<double> vec9(vec5);
    std::vector<double> vec10(vec6);
    std::vector<double> vec11(vec3);

    (void)argc;
    std::cout << "VECTOR double" << std::endl << std::endl;
    
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
        std::cout << vec4[i] << " ";
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
        std::cout << vec5[i] << " ";
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
        std::cout << vec6[i] << " ";
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
            std::cout << vec7[i] << " ";
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
    vec8[0] = 9.0;

    for(i = 0; i < vec8.size(); i++)
    {
        std::cout << vec8[i] << " ";
    }
    std::cout << std::endl;
    std::cout << vec8.size() << std::endl;
    std::cout << vec8.max_size() << std::endl;
    std::cout << vec8.empty() << std::endl;
    std::cout << vec8.capacity() << std::endl;
    for(i = 0; i < vec4.size(); i++)
    {
        std::cout << vec4[i] << " ";
    }
    std::cout << std::endl;
    std::cout << vec4.size() << std::endl;
    std::cout << vec4.max_size() << std::endl;
    std::cout << vec4.empty() << std::endl;
    std::cout << vec4.capacity() << std::endl;
    std::cout << std::endl;
    
    std::cout << "9 :\n";
    vec9[x - 1] = 8.2193;

    for(i = 0; i < vec9.size(); i++)
    {
        std::cout << vec9[i] << " ";
    }
    std::cout << std::endl;
    std::cout << vec9.size() << std::endl;
    std::cout << vec9.max_size() << std::endl;
    std::cout << vec9.empty() << std::endl;
    std::cout << vec9.capacity() << std::endl;
    for(i = 0; i < vec5.size(); i++)
    {
        std::cout << vec5[i] << " ";
    }
    std::cout << std::endl;
    std::cout << vec5.size() << std::endl;
    std::cout << vec5.max_size() << std::endl;
    std::cout << vec5.empty() << std::endl;
    std::cout << vec5.capacity() << std::endl;
    std::cout << std::endl;

    std::cout << "10 :\n";
    vec10[777] = 707.777;

    for(i = 0; i < vec10.size(); i++)
    {
        std::cout << vec10[i] << " ";
    }
    std::cout << std::endl;
    std::cout << vec10.size() << std::endl;
    std::cout << vec10.max_size() << std::endl;
    std::cout << vec10.empty() << std::endl;
    std::cout << vec10.capacity() << std::endl;
    for(i = 0; i < vec6.size(); i++)
    {
        std::cout << vec6[i] << " ";
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
        vec3[5008] = 1505.7581;

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