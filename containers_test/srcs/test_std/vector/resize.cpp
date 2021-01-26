#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>

template<typename T>
void print(std::vector<T> &vec, size_t j)
{
    size_t i;

    try
    {
        vec.resize(j);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
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
void print(std::vector<T> &vec, size_t j, T val)
{
    size_t i;

    try
    {
        vec.resize(j, val);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
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
void print(std::vector<T *> &vec, size_t j, T *val)
{
    size_t i;
    size_t i2;

    try
    {
        vec.resize(j, val);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for(i = 0; i < vec.size(); i++)
    {
        for (i2 = 0; vec[i][i2] != 0; i2++)
        {
            std::cout << vec[i][i2];
        }
        std::cout << "-" << i << "-";
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
    int x1 = 9;
    int x2 = 112; 
    int x3 = 19;
    int x4 = 42;
    int x5 = 52;
    char    tabc[] = "une petit test de qualite";
    std::vector<char>::iterator begc(tabc);
    std::vector<char>::iterator endc(&tabc[26]);
    char    tab[10] = "oupalinda";
    std::vector<int> vec1(x1, 22);
    std::vector<char> vec2(begc, endc);
    std::vector<std::string> vec3(x3, "mmmmm...");
    std::vector<double> vec4(x4, 9.254);
    std::vector<char *> vec5(x5, tab);

    // > capacity > size 
    print(vec1, x1 + 42, 32);
    print(vec2, x2 + 31, ';');
    print(vec3, x3 + 180, static_cast<std::string>("pfff..."));
    print(vec4, x4 + 12343, 0.6);
    print(vec5, x5 + 112, tab);

    // > capacity > size
    print(vec1, x1 + 12);
    print(vec2, x2 + 25);
    print(vec3, x3 + 130);
    print(vec4, x4 + 12000);
    print(vec5, x5 + 3, tab);

    // < capacity < size
    print(vec1, x1 + 1, 22);
    print(vec2, x2 + 1, '[');
    print(vec3, x3 + 1, static_cast<std::string>("roooh..."));
    print(vec4, x4 + 1, 18.8);
    print(vec5, x5 + 1, tab);

    // = capacity = sizes
    print(vec1, x1 + 1, 31);
    print(vec2, x2 + 1, '"');
    print(vec3, x3 + 1, static_cast<std::string>("eeeeuh..."));
    print(vec4, x4 + 1, 912.12);
    print(vec5, x5 + 1, tab);

    // > capacity > size
    print(vec1, x1 + 98);
    print(vec2, x2 + 16);
    print(vec3, x3 + 30);
    print(vec4, x4 + 1111);
    print(vec5, x5 + 280, tab);

    // = capacity = size
    print(vec1, x1 + 98);
    print(vec2, x2 + 16);
    print(vec3, x3 + 30);
    print(vec4, x4 + 1111);
    print(vec5, x5 + 280, tab);

    // < capacity < size
    print(vec1, x1, 490);
    print(vec2, x2, '|');
    print(vec3, x3, static_cast<std::string>("zzz..."));
    print(vec4, x4, 77.7);
    print(vec5, x5, tab);
    
    // < capacity < size
    print(vec1, x1 - 3);
    print(vec1, x2 - 80);
    print(vec3, x3 - 12);
    print(vec4, x4 - 1231);
    print(vec5, x5 - 508, tab);
    
    // 0 capacity 0 size
    print(vec1, 0);
    print(vec2, 0);
    print(vec3, 0);
    print(vec4, 0);
    print(vec5, 0, tab);

    //max value + 1
    print(vec1, vec1.max_size() + 1);
    print(vec2, vec2.max_size() + 1);
    print(vec3, vec3.max_size() + 1);
    print(vec4, vec4.max_size() + 1);
    print(vec5, vec5.max_size() + 1, tab);

    //max value
    print(vec1, vec1.max_size(), 21);
    print(vec2, vec2.max_size(), '{');
    print(vec3, vec3.max_size(), static_cast<std::string>("chhh..."));
    print(vec4, vec4.max_size(), 88.01);
    print(vec5, vec5.max_size(), tab);

    //0 cap 0 size
    print(vec1, 0, 66);
    print(vec2, 0, '@');
    print(vec3, 0, static_cast<std::string>("..."));
    print(vec4, 0, 88.9);
    print(vec5, 0, tab);
    
    // > >
    print(vec1, x1, 490);
    print(vec2, x2, '|');
    print(vec3, x3, static_cast<std::string>("zzz..."));
    print(vec4, x4, 77.7);
    print(vec5, x5, tab);

    // < >
    vec1.reserve(x1 + 32);
    vec2.reserve(x2 + 58);
    vec3.reserve(x3 + 3);
    vec4.reserve(x4 + 147);
    vec5.reserve(x5 + 2001);
    print(vec1, x1 + 10, 4508);
    print(vec2, x2 + 21, '%');
    print(vec3, x3 + 1, static_cast<std::string>("!!!"));
    print(vec4, x4 + 111, 901.2);
    print(vec5, x5 + 4, tab);

    // < >
    print(vec1, x1 + 12, 3021);
    print(vec2, x2 + 25, '^');
    print(vec3, x3 + 1, static_cast<std::string>("???"));
    print(vec4, x4 + 32, 67.43);
    print(vec5, x5 + 1257, tab);
    
    return (0);
}
