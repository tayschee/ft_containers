#include <iterator>
#include <iostream>
#include <vector>

int main()
{
    size_t i;
    std::vector<int> test(5, 9);
    std::vector<int> test1(9, 18);
    std::vector<int>::iterator it;
    std::vector<int>::iterator it1;
    std::vector<int>::reference a = test.front();
    std::vector<int>::reference a1 = test1.front();


    it = test.begin();
    it1 = test1.begin();
    a = test.front();
    a1 = test1.front();
    test.swap(test1);
    for (i = 0; i < test.size(); i++)
    {
        std::cout << test[i] << "\n";
    }
    for (i = 0; i < test1.size(); i++)
    {
        std::cout << test1[i] << "\n";
    }
    std::cout << *it << " " << *it1 << "\n\n";
    a = 5;
    a1 = 8;
    for (i = 0; i < test.size(); i++)
    {
        std::cout << test[i] << "\n";
    }
    for (i = 0; i < test1.size(); i++)
    {
        std::cout << test1[i] << "\n";
    }
    std::cout << a << " " << a1 << "\n";
    std::cout << *it << "\n";
    std::cout << *++it << "\n";
    //std::cout << *it << "\n";


    return (0);
}