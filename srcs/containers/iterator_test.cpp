#include <vector>
#include <iostream>

struct a
{
    const int m;
};

int main()
{
    a               b[3] = {{126}, {127}, {128}};
    size_t          i;
    int             tab[] = {10, 11, 12, 13, 14};
    std::vector<int>::iterator iterator(tab);
    std::vector<int>::iterator iteratorb = iterator;
    std::vector<int>::iterator iterator1;
    std::vector<a>::iterator iteratora(b);

    std::cout << (iterator < iterator1) << std::endl;
    std::cout << (iterator > iterator1) << std::endl;
    std::cout << (iterator >= iterator1) << std::endl;
    std::cout << (iterator >= iteratorb) << std::endl;
    std::cout << (iterator <= iterator1) << std::endl;
    std::cout << (iterator <= iteratorb) << std::endl;
    std::cout << (iterator == iteratorb) << std::endl;
    std::cout << (iterator != iteratorb) << std::endl;
    std::cout << (iterator == iterator1) << std::endl;
    std::cout << (iterator != iterator1) << std::endl;

    iterator++;
    ++iterator;
    ++iterator;
    std::cout << (iterator < iterator1) << std::endl;
    std::cout << (iterator > iterator1) << std::endl;
    std::cout << (iterator >= iterator1) << std::endl;
    std::cout << (iterator >= iteratorb) << std::endl;
    std::cout << (iterator <= iterator1) << std::endl;
    std::cout << (iterator <= iteratorb) << std::endl;
    std::cout << (iterator == iteratorb) << std::endl;
    std::cout << (iterator != iteratorb) << std::endl;
    std::cout << (iterator == iterator1) << std::endl;
    std::cout << (iterator != iterator1) << std::endl;

    iterator--;
    --iterator;
    std::cout << (iterator < iterator1) << std::endl;
    std::cout << (iterator > iterator1) << std::endl;
    std::cout << (iterator >= iterator1) << std::endl;
    std::cout << (iterator >= iteratorb) << std::endl;
    std::cout << (iterator <= iterator1) << std::endl;
    std::cout << (iterator <= iteratorb) << std::endl;
    std::cout << (iterator == iteratorb) << std::endl;
    std::cout << (iterator != iteratorb) << std::endl;
    std::cout << (iterator == iterator1) << std::endl;
    std::cout << (iterator != iterator1) << std::endl;

    std::cout <<  "\n" <<*iterator << "\n";
    for(i = 0; i < 4; i++)
    {
        std::cout << iterator[i] << " ";
    }
    std::cout << "\n" <<*iteratorb << "\n";
    for(i = 0; i < 4; i++)
    {
        std::cout << iteratorb[i] << " ";
    }


    *iterator = 5;
    std::cout <<  "\n" << *iterator << "\n";
    for(i = 0; i < 4; i++)
    {
        std::cout << iterator[i] << " ";
    }
    std::cout << "\n" <<*iteratorb << "\n";
    for(i = 0; i < 4; i++)
    {
        std::cout << iteratorb[i] << " ";
    }

    *iterator++;
    std::cout << "\n" << *iterator << "\n";
    for(i = 0; i < 3; i++)
    {
        std::cout << iterator[i] << " ";
    }
    std::cout << "\n" << *iteratorb << "\n";
    for(i = 0; i < 3; i++)
    {
        std::cout << iteratorb[i] << " ";
    }

    iterator--;
    std::cout << "\n" << *iterator << "\n";
    for(i = 0; i < 3; i++)
    {
        std::cout << *(iterator  + i) << " ";
    }
    std::cout << "\n" << *iteratorb << "\n";
    for(i = 0; i < 3; i++)
    {
        std::cout << *(iteratorb + i) << " ";
    }

    iterator++;
    iterator++;
    iterator++;
    iteratorb++;
    iteratorb++;
    iteratorb++;
    std::cout << "\n" << *iterator << "\n";
    for(i = 0; i < 3; i++)
    {
        std::cout << *(iterator  - i) << " ";
    }
    std::cout << "\n" << *iteratorb << "\n";
    for(i = 0; i < 3; i++)
    {
        std::cout << *(iteratorb - i) << " ";
    }

    for (i = 0; i < 3; i++)
    {
        std::cout << (iteratora + i)->m << "\n";
    }
    std::cout << "\n";
    return (0);
}