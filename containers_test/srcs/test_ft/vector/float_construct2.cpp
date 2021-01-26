#include "vector.hpp"
#include <iostream>

int main()
{
    size_t  i;
    float    tab1[] = {1.1f, 2.0f, 3.7f, 4.8f, 5.31f, 6.53f, 7.1f, 8.52f, 9.52f, -0.414f};
    for (i = 0; tab1[i] < 0; ++i);
    ft::vector<float>::iterator beg1(tab1);
    ft::vector<float>::iterator end1(&tab1[i]);
    ft::vector<float>    vec1(beg1, end1);

    float    tab2[] = {9.4f, -0.4f};
    for (i = 0; tab2[i] < 0; ++i);
    ft::vector<float>::iterator beg2(tab2);
    ft::vector<float>::iterator end2(&tab2[i]);
    ft::vector<float>    vec2(beg2, end2);

    float    tab3[] = {-0.1f};
    for (i = 0; tab3[i] < 0; ++i);
    ft::vector<float>::iterator beg3(tab3);
    ft::vector<float>::iterator end3(&tab3[i]);
    ft::vector<float>    vec3(beg3, end3);

    float    tab4[] = {1.423f, 2.431f, 4.24f, 6.643f, 7.542f, 99.651f, 33.53f, 66.643f,24.531f, 64.567f, 234.987f, 7.24f, 3553.0f,
     14.12f, 759.12f, 4531.64f, 622.65f, 764.52f, 265.65f, 123.35f, 364.21f, 111.15f, 235.12f, 234.12f,
     354.25f, 3452.11f, 126.90f, 323.32f, 123.12f, 543.1f, 123.0f, 531.34f, 53.24f, -5.0f};
    for (i = 0; tab4[i] != 0; ++i);
    ft::vector<float>::const_iterator beg4(tab4);
    ft::vector<float>::const_iterator end4(&tab4[i]);
    ft::vector<float>    vec4(beg4, end4);

    float    tab5[] = {12, 35,124, 0};
    for (i = 0; tab5[i] != 0; ++i);
    ft::vector<float>::const_iterator beg5(tab5);
    ft::vector<float>::const_iterator end5(&tab5[i]);
    ft::vector<float>    vec5(beg5, end5);

    ft::vector<float>    vec6(12, 12);


    for(i = 0; i < vec1.size(); i++)
    {
        std::cout << vec1[i] << " ";
    }
    std::cout << "\n";
    std::cout << vec1.empty() << "\n";
    std::cout << vec1.size() << "\n";
    std::cout << vec1.max_size() << "\n";
    std::cout << vec1.capacity() << "\n";
    std::cout << "\n";

    for(i = 0; i < vec2.size(); i++)
    {
        std::cout << vec2[i] << " ";
    }
    std::cout << "\n";
    std::cout << vec2.empty() << "\n";
    std::cout << vec2.size() << "\n";
    std::cout << vec2.max_size() << "\n";
    std::cout << vec2.capacity() << "\n";
    std::cout << "\n";


    for(i = 0; i < vec3.size(); i++)
    {
        std::cout << vec3[i] << " ";
    }
    std::cout << "\n";
    std::cout << vec3.empty() << "\n";
    std::cout << vec3.size() << "\n";
    std::cout << vec3.max_size() << "\n";
    std::cout << vec3.capacity() << "\n";
    std::cout << "\n";

    for(i = 0; i < vec4.size(); i++)
    {
        std::cout << vec4[i] << " ";
    }
    std::cout << "\n";
    std::cout << vec4.empty() << "\n";
    std::cout << vec4.size() << "\n";
    std::cout << vec4.max_size() << "\n";
    std::cout << vec4.capacity() << "\n";
    std::cout << "\n";

    for(i = 0; i < vec5.size(); i--)
    {
        std::cout << vec5[i] << " ";
    }
    std::cout << "\n";
    std::cout << vec5.empty() << "\n";
    std::cout << vec5.size() << "\n";
    std::cout << vec5.max_size() << "\n";
    std::cout << vec5.capacity() << "\n";
    std::cout << "\n";

    for(i = 0; i < vec6.size(); i++)
    {
        std::cout << vec6[i] << " ";
    }
    std::cout << "\n";
    std::cout << vec6.empty() << "\n";
    std::cout << vec6.size() << "\n";
    std::cout << vec6.max_size() << "\n";
    std::cout << vec6.capacity() << "\n";
    std::cout << "\n";

    
    return (0);
}