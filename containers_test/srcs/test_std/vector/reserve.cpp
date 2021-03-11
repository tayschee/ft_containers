#include <vector>
#include <iostream>
#include <string>

template <typename T>
void    test(std::vector<T> &vec)
{
    size_t i;

    for(i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
    try
    {
        for(i = 0; 1; i++)
            std::cout << vec.at(i) << " ";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << std::endl;
    std::cout << vec.size() << std::endl;
    std::cout << vec.max_size() << std::endl;
    std::cout << vec.empty() << std::endl;
    std::cout << vec.capacity() << std::endl;
    if (vec.size() != 0)
    {
        std::cout << *vec.begin() << std::endl;
        std::cout << *vec.rbegin() << std::endl;
        std::cout << *--vec.end() << std::endl;
        std::cout << *--vec.rend() << std::endl;
        std::cout << vec.front() << std::endl;
        std::cout << vec.back() << std::endl;
    }
    else
    {
        vec.begin();
        vec.rbegin();
        --vec.end();
        --vec.end();
    }
    std::cout << std::endl;
}

template<typename T>
std::vector<T>     create(std::vector<T> lst)
{
    return(std::vector<T>(lst));
}

template<typename T>
std::vector<T>     create(size_t end_nb, T *tab)
{
    typename std::vector<T>::iterator beg(tab);
    typename std::vector<T>::iterator end(&tab[end_nb]);

    return(std::vector<T>(beg, end));
}

template<typename T>
std::vector<T>     create(size_t size, const T &val)
{
    return(std::vector<T>(size, val));
}

template<typename T>
std::vector<T>     create(size_t size)
{
    return(std::vector<T>(size));
}

template<typename T>
std::vector<T>     create()
{
    return(std::vector<T>());
}

template <typename T>
void    func(std::vector<T> lst, size_t i)
{
    size_t  old_c = lst.capacity();
    typename std::vector<T>::iterator beg(lst.begin());
    typename std::vector<T>::iterator end(lst.end());

    try
    {
        lst.reserve(i);
        if (old_c == lst.capacity())
        {
            while (beg != end)
            {
                std::cout << *beg++ << " ";
            }
            std::cout << "\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    test(lst);

}

template <typename T>
void    test_all(T val, size_t size, size_t x)
{
    size_t i = 0;
    std::vector<T> vec(size, val);

    func(vec, x);
    func(vec, vec.max_size() + 1);
    func(vec, vec.max_size());
    func(vec, vec.max_size() - 1);
    while (i < x)
    {
        func(create<T>(), i);
        func(create(0, val), i);
        func(create(size, val), i);
        func(vec, i);
        ++i;
    }
}

int main()
{
    std::string str1("string2");

    test_all(12, 500, 750);
    test_all('c', 250, 600);
    test_all(12.94, 40, 60);
    test_all(str1, 20, 51);

}
   