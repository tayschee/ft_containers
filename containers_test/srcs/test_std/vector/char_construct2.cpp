#include <vector>
#include <iostream>

int main()
{
    size_t  i;
    char    tab1[] = "abcdefghijklmopqrstuvwxyz";
    for (i = 0; tab1[i] != 0; ++i);
    std::vector<char>::iterator beg1(tab1);
    std::vector<char>::iterator end1(&tab1[i]);
    std::vector<char>    vec1(beg1, end1);

    char    tab2[] = "a";
    for (i = 0; tab2[i] != 0; ++i);
    std::vector<char>::iterator beg2(tab2);
    std::vector<char>::iterator end2(&tab2[i]);
    std::vector<char>    vec2(beg2, end2);

    char    tab3[] = "";
    for (i = 0; tab3[i] != 0; ++i);
    std::vector<char>::iterator beg3(tab3);
    std::vector<char>::iterator end3(&tab3[i]);
    std::vector<char>    vec3(beg3, end3);

    char    tab4[] = "123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354\
    5556575859606162636465666676869707172737475767778798081828384858687888990919293949596979899100";
    for (i = 0; tab4[i] != 0; ++i);
    std::vector<char>::const_iterator beg4(tab4);
    std::vector<char>::const_iterator end4(&tab4[i]);
    std::vector<char>    vec4(beg4, end4);

    char    tab5[] = "const ok";
    for (i = 0; tab5[i] != 0; ++i);
    std::vector<char>::const_iterator beg5(tab5);
    std::vector<char>::const_iterator end5(&tab5[i]);
    std::vector<char>    vec5(beg5, end5);

    std::vector<char>    vec6(12, 12);


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