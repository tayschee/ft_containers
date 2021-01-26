#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h> //sleep

template<typename T>
void print(std::vector<T> &vec)
{
    size_t i;

    try
    {
        for(i = 0; 1; i++)
            std::cout << vec.at(i) << " ";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    std::cout << vec.max_size() << "\n";
    std::cout << vec.size() << "\n";
    std::cout << vec.capacity() << "\n";
    std::cout << vec.empty() << "\n";
    if (i > 0)
    {
        std::cout << vec.front() << "\n";
        std::cout << vec.back() << "\n";
        std::cout << *vec.begin() << "\n";
        std::cout << *--vec.end() << "\n";
        std::cout << *vec.rbegin() << "\n";
        std::cout << *--vec.rend() << "\n";
    }
    std::cout << "\n";
}

template<typename T>
void print(std::vector<T *> &vec)
{
    size_t i;
    size_t j;

    try
    {
        for(i = 0; 1; i++)
        {
            for(j = 0; vec.at(i)[j] != 0; j++)
                std::cout << vec.at(i)[j] << " ";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    std::cout << vec.max_size() << "\n";
    std::cout << vec.size() << "\n";
    std::cout << vec.capacity() << "\n";
    std::cout << vec.empty() << "\n";
    /*if (i > 0)
    {
        std::cout << vec.front() << "\n";
        std::cout << vec.back() << "\n";
        std::cout << *vec.begin() << "\n";
        std::cout << *--vec.end() << "\n";
        std::cout << *vec.rbegin() << "\n";
        std::cout << *--vec.rend() << "\n";
    }*/
    std::cout << "\n";
}

int main()
{
    int x1 = 90;
    int x2 = 802; 
    int x3 = 2;
    int x4 = 34;
    int x5 = 4201;
    int    tab[]= {3, 8, 6, 12, -95, 11045, -4312, 48530, 14, 457, -5425, -24593, 123403, -41235, -314344, -12212, 414,
    432, 5920, 1234, 12905, 0123, 111902, 239401, 123, 0};
    std::vector<int> vec1(x1, 89);
    std::vector<char> vec2(x2, '$');
    std::vector<std::string> vec3(x3, "texte tres long de toute facon il y a peu d'affichage");
    std::vector<double> vec4(x4, -92.5);
    std::vector<int *> vec5(x5, tab);

    std::vector<int> vec11(0, 89);
    std::vector<char> vec21(0, '$');
    std::vector<std::string> vec31(0, "texte tres long de toute facon il y a peu d'affichage");
    std::vector<double> vec41(0, -92.5);
    std::vector<int *> vec51(0, tab);

    std::vector<int> vec12(1, 89);
    std::vector<char> vec22(1, '$');
    std::vector<std::string> vec32(1, "texte tres long de toute facon il y a peu d'affichage");
    std::vector<double> vec42(1, -92.5);
    std::vector<int *> vec52(1, tab);

    int             tab1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 92, 207, 8912, 13};
    std::vector<int>::iterator beg1(tab1);
    std::vector<int>::iterator end1(&tab1[13]);
    std::vector<int> vec13(beg1, end1);

    char             tab2[] = {34, 63, 78, 123, 45, 46, 76, 89, 88, 90, 53, 68, 82, 98, 106, 118, 126, 94};
    std::vector<char>::iterator beg2(tab2);
    std::vector<char>::iterator end2(&tab2[18]);
    std::vector<char> vec23(beg2, end2);

    std::string             tab3[] = {"napolitain", "exorciste", "cucurbitave", "oreo", "boreale", "antartique",
    "ninjustsu", "des", "mots", "termine"};
    std::vector<std::string>::iterator beg3(tab3);
    std::vector<std::string>::iterator end3(&tab3[10]);
    std::vector<std::string> vec33(beg3, end3);

    double             tab4[] = {12.4, 13.2};
    std::vector<double>::iterator beg4(tab4);
    std::vector<double>::iterator end4(&tab4[2]);
    std::vector<double> vec43(beg4, end4);

    int                 *tab5 = new int[14];
    size_t           i;
    for(i = 0; i < 14; i++)
        tab5[i] = i * 2;
    tab5[i - 1] = 0;
    std::vector<int *>::iterator beg5(&tab5);
    std::vector<int *>::iterator end5(&++tab5);
    std::vector<int *> vec53(beg5, end5);

    print(vec1);
    print(vec2);
    print(vec3);
    print(vec4);
    print(vec5);

    print(vec11);
    print(vec21);
    print(vec31);
    print(vec41);
    print(vec51);

    print(vec12);
    print(vec22);
    print(vec32);
    print(vec42);
    print(vec52);

    print(vec13);
    print(vec23);
    print(vec33);
    print(vec43);
    print(vec53);

    delete[] (--tab5);
    return (0);
}
