#include <vector>
#include <iostream>

int main()
{
    size_t  i;
    int    tab1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (i = 0; tab1[i] != 0; ++i);
    std::vector<int>::iterator beg1(tab1);
    std::vector<int>::iterator end1(&tab1[i]);
    std::vector<int>    vec1(beg1, end1);

    int    tab2[] = {1, 0};
    for (i = 0; tab2[i] != 0; ++i);
    std::vector<int>::iterator beg2(tab2);
    std::vector<int>::iterator end2(&tab2[i]);
    std::vector<int>    vec2(beg2, end2);

    int    tab3[] = {0};
    for (i = 0; tab3[i] != 0; ++i);
    std::vector<int>::iterator beg3(tab3);
    std::vector<int>::iterator end3(&tab3[i]);
    std::vector<int>    vec3(beg3, end3);

    int    tab4[] = {1, 2, 4, 6, 7,99, 33, 66,24, 64, 234, 7, 3553, 14, 759, 4531, 622, 764, 265, 123, 364, 111,
    235, 234, 354, 3452, 126, 323, 123, 543, 123, 531, 53, 18, 0};
    for (i = 0; tab4[i] != 0; ++i);
    std::vector<int>::const_iterator beg4(tab4);
    std::vector<int>::const_iterator end4(&tab4[i]);
    std::vector<int>    vec4(beg4, end4);

    int    tab5[] = {12, 35,124, 0};
    for (i = 0; tab5[i] != 0; ++i);
    std::vector<int>::const_iterator beg5(tab5);
    std::vector<int>::const_iterator end5(&tab5[i]);
    std::vector<int>    vec5(beg5, end5);

    std::vector<int>    vec6(12, 12);


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