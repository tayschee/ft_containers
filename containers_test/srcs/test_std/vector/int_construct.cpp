#include <vector>
#include <iostream>

int main(int argc, char **argv)
{
    size_t           i;
    size_t           x = 781;
    std::vector<int> vec;
    std::vector<int> vec1(0);
    std::vector<int> vec2(17);
    std::vector<int> vec3(90732);
    std::vector<int> vec4(88, 12604);
    std::vector<int> vec5(x, 6);
    std::vector<int> vec6(2981, 871);
    std::vector<int> vec7(571891, 673);
    std::vector<int> vec8(vec4);
    std::vector<int> vec9(vec5);
    std::vector<int> vec10(vec6);
    std::vector<int> vec11(vec3);

    (void)argc;
    std::cout << "VECTOR int" << std::endl << std::endl;
    
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
    vec8[0] = 118218;

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
    vec9[x - 1] = 1234;

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
    vec10[1001] = 43912;

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
        vec3[45009] = 1782379;

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