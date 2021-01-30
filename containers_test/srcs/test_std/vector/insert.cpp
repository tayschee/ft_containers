#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h> //sleep

template<typename T>
void print(std::vector<T> &vec, size_t pos, const T &val)
{
    size_t i;

    try
    {
        typename std::vector<T>::iterator it_pos(vec.begin() + pos);
        typename std::vector<T>::iterator verif_it;
        verif_it = vec.insert(it_pos, val);
        while (verif_it != vec.end())
            std::cout << *verif_it++ << " ";
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    for(i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
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

int main()
{
    int x1 = 48;
    int x2 = 422; 
    int x3 = 5006;
    int x4 = 127;
    int x5 = 18;
    char    tab[6]= "test";
    std::vector<int> vec1(x1, -47);
    std::vector<int> vec2(3, 3);
    /*std::vector<char> vec2(x2, 'c');
    std::vector<std::string> vec3(x3, "yup");
    std::vector<double> vec4(x4, 12.25);
    std::vector<char *> vec5(x5, tab);*/

    //int
    print(vec1, 6, 18);
    print(vec1, 1, 9);

   
    
    return (0);
}
