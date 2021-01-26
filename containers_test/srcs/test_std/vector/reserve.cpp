#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h> //sleep

template<typename T>
void print(std::vector<T> &vec, size_t j)
{
    size_t i;

    try
    {
        vec.reserve(j);
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

template<typename T>
void print(std::vector<T *> &vec, size_t j)
{
    size_t i;
    size_t i2;

    try
    {
        vec.reserve(j);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    for(i = 0; i < vec.size(); i++)
    {
        for (i2 = 0; vec[i][i2] != 0; i2++)
            std::cout << vec[i][i2] << " ";
        std::cout << "-";
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
    int x1 = 12;
    int x2 = 210; 
    int x3 = 11;
    int x4 = 5241;
    int x5 = 712;
    char    tab[6]= "test";
    std::vector<int> vec1(x1, 12);
    std::vector<char> vec2(x2, 'c');
    std::vector<std::string> vec3(x3, "yup");
    std::vector<double> vec4(x4, 12.25);
    std::vector<char *> vec5(x5, tab);

    // > capacity > size 
    print(vec1, 50);
    print(vec2, 27);
    print(vec3, x3 + 18);
    print(vec4, x4 + 60);
    print(vec5, x5 + 112);

    // < capacity > size
    print(vec1, 28);
    print(vec2, 25);
    print(vec3, x3 + 13);
    print(vec4, x4 + 12);
    print(vec5, x5 + 12);

    // < capacity > size
    print(vec1, x1 + 1);
    print(vec2, x2 + 1);
    print(vec3, x3 + 1);
    print(vec4, x4 + 1);
    print(vec5, x5 + 1);

    // > capacity = sizes
    print(vec1, x1);
    print(vec2, x2);
    print(vec3, x3);
    print(vec4, x4);
    print(vec5, x5);
    
    // > capacity > size
    print(vec1, 72);
    print(vec2, 31);
    print(vec3, x3 + 21);
    print(vec4, x4 + 11);
    print(vec5, x5 + 18);

    // > capacity = size
    print(vec1, x1);
    print(vec2, x2);
    print(vec3, x3);
    print(vec4, x4);
    print(vec5, x5);
    
    // < capacity < size
    print(vec1, 2);
    print(vec1, x2 - 1);
    print(vec3, x3 - 5);
    print(vec4, x4 - 1800);
    print(vec5, x5 - 100);
    
    // 0 capacity 0 size
    print(vec1, 0);
    print(vec2, 0);
    print(vec3, 0);
    print(vec4, 0);
    print(vec5, 0);

    //max value + 1
    print(vec1, vec1.max_size() + 1);
    print(vec2, vec2.max_size() + 1);
    print(vec3, vec3.max_size() + 1);
    print(vec4, vec4.max_size() + 1);
    print(vec5, vec5.max_size() + 1);

    //max value
    print(vec1, vec1.max_size());
    print(vec2, vec2.max_size());
    print(vec3, vec3.max_size());
    print(vec4, vec4.max_size());
    print(vec5, vec5.max_size());

    
    return (0);
}
