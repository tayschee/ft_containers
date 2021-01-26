#include "vector.hpp"
#include <iostream>
#include <string>

int main()
{
    size_t  i;
    std::string    tab1[] = {"abc", "cde", "fghij", "klmop",  "qrstuvwxyz", ""};
    for (i = 0; tab1[i] != ""; ++i);
    ft::vector<std::string>::iterator beg1(tab1);
    ft::vector<std::string>::iterator end1(&tab1[i]);
    ft::vector<std::string>    vec1(beg1, end1);

    std::string    tab2[] = {"word", ""};
    for (i = 0; tab2[i] != ""; ++i);
    ft::vector<std::string>::iterator beg2(tab2);
    ft::vector<std::string>::iterator end2(&tab2[i]);
    ft::vector<std::string>    vec2(beg2, end2);

    std::string    tab3[] = {""};
    for (i = 0; tab3[i] != ""; ++i);
    ft::vector<std::string>::iterator beg3(tab3);
    ft::vector<std::string>::iterator end3(&tab3[i]);
    ft::vector<std::string>    vec3(beg3, end3);

    std::string    tab4[] = {"test", "123", "qqc", "encore", "phrase", "flemme", "oui", "place", "boom",  "aloa",
    "slim", "jean", "poiuytrewq", ";'", "llla", "ouistiti", "ouistiti", ""};
    for (i = 0; tab4[i] != ""; ++i);
    ft::vector<std::string>::const_iterator beg4(tab4);
    ft::vector<std::string>::const_iterator end4(&tab4[i]);
    ft::vector<std::string>    vec4(beg4, end4);

    std::string    tab5[] = {"const", "is", "ok", ""};
    for (i = 0; tab5[i] != ""; ++i);
    ft::vector<std::string>::const_iterator beg5(tab5);
    ft::vector<std::string>::const_iterator end5(&tab5[i]);
    ft::vector<std::string>    vec5(beg5, end5);

    ft::vector<std::string>    vec6(12, "oui");


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