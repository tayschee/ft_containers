#include <vector>
#include <iostream>

struct a
{
    double a;
};

int main()
{
    size_t  i;
    struct a    tab1[] = {{1.3}, {8.6}, {4.12}, {12.12}, {1234.1}, {-12.3}};
    for (i = 0; tab1[i].a > 0.0; ++i);
    std::vector<struct a>::iterator beg1(tab1);
    std::vector<struct a>::iterator end1(&tab1[i]);
    std::vector<struct a>    vec1(beg1, end1);

    struct a    tab2[] = {{12.17}, {-5.0}};
    for (i = 0; tab2[i].a > 0.0; ++i);
    std::vector<struct a>::iterator beg2(tab2);
    std::vector<struct a>::iterator end2(&tab2[i]);
    std::vector<struct a>    vec2(beg2, end2);

    struct a    tab3[] = {{-5.0}};
    for (i = 0; tab3[i].a > 0.0; ++i);
    std::vector<struct a>::iterator beg3(tab3);
    std::vector<struct a>::iterator end3(&tab3[i]);
    std::vector<struct a>    vec3(beg3, end3);

    struct a    tab4[] = {{1.1}, {2.2}, {3.3}, {4.4}, {5.5}, {6.6}, {7.7}, {8.8}, {9.9}, {1.11}, {2.22}, {3.33},
    {4.44}, {5.55}, {6.66}, {7.77}, {8.88}, {9.99}, {11.1}, {22.2}, {33.3}, {44.4}, {55.5}, {66.6}, {77.7}, {88.8},
    {99.9}, {-5.0}};
    for (i = 0; tab4[i].a > 0.0; ++i);
    std::vector<struct a>::const_iterator beg4(tab4);
    std::vector<struct a>::const_iterator end4(&tab4[i]);
    std::vector<struct a>    vec4(beg4, end4);

    struct a    tab5[] = {{12.4}, {13.6}, {11.5}, {-4.0}};
    for (i = 0; tab5[i].a > 0.0; ++i);
    std::vector<struct a>::const_iterator beg5(tab5);
    std::vector<struct a>::const_iterator end5(&tab5[i]);
    std::vector<struct a>    vec5(beg5, end5);

    struct a    ex = {6};
    std::vector<struct a>    vec6(12, ex);


    for(i = 0; i < vec1.size(); i++)
    {
        std::cout << vec1[i].a << " ";
    }
    std::cout << "\n";
    std::cout << vec1.empty() << "\n";
    std::cout << vec1.size() << "\n";
    std::cout << vec1.max_size() << "\n";
    std::cout << vec1.capacity() << "\n";
    std::cout << "\n";

    for(i = 0; i < vec2.size(); i++)
    {
        std::cout << vec2[i].a << " ";
    }
    std::cout << "\n";
    std::cout << vec2.empty() << "\n";
    std::cout << vec2.size() << "\n";
    std::cout << vec2.max_size() << "\n";
    std::cout << vec2.capacity() << "\n";
    std::cout << "\n";


    for(i = 0; i < vec3.size(); i++)
    {
        std::cout << vec3[i].a << " ";
    }
    std::cout << "\n";
    std::cout << vec3.empty() << "\n";
    std::cout << vec3.size() << "\n";
    std::cout << vec3.max_size() << "\n";
    std::cout << vec3.capacity() << "\n";
    std::cout << "\n";

    for(i = 0; i < vec4.size(); i++)
    {
        std::cout << vec4[i].a << " ";
    }
    std::cout << "\n";
    std::cout << vec4.empty() << "\n";
    std::cout << vec4.size() << "\n";
    std::cout << vec4.max_size() << "\n";
    std::cout << vec4.capacity() << "\n";
    std::cout << "\n";

    for(i = 0; i < vec5.size(); i--)
    {
        std::cout << vec5[i].a << " ";
    }
    std::cout << "\n";
    std::cout << vec5.empty() << "\n";
    std::cout << vec5.size() << "\n";
    std::cout << vec5.max_size() << "\n";
    std::cout << vec5.capacity() << "\n";
    std::cout << "\n";

    for(i = 0; i < vec6.size(); i++)
    {
        std::cout << vec6[i].a << " ";
    }
    std::cout << "\n";
    std::cout << vec6.empty() << "\n";
    std::cout << vec6.size() << "\n";
    std::cout << vec6.max_size() << "\n";
    std::cout << vec6.capacity() << "\n";
    std::cout << "\n";

    
    return (0);
}