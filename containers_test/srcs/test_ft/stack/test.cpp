#include <iostream>
#include "stack.hpp"
#include "list.hpp"
#include "vector.hpp"
#include <string>

template<class T, class C>
void    test(const ft::stack<T, C> &s)
{
    std::cout << s.size();
    std::cout << s.empty();
}

template<class T, class C>
void    cmp(const ft::stack<T, C> &s1, const ft::stack<T, C> &s2)
{
    std::cout << (s1 == s2) << " ";
    std::cout << (s2 == s1) << " ";
    std::cout << (s1 != s2) << " ";
    std::cout << (s2 != s1) << " ";
    std::cout << (s1 < s2) << " ";
    std::cout << (s2 < s1) << " ";
    std::cout << (s1 > s2) << " ";
    std::cout << (s2 > s1) << " ";
    std::cout << (s1 >= s2) << " ";
    std::cout << (s2 >= s1) << " ";
    std::cout << (s1 <= s2) << " ";
    std::cout << (s2 <= s1) << " ";
}

template<class T, class C>
void    pop(ft::stack<T, C> &s, size_t size)
{
    size_t i = 0;
    while (i < size)
    {
        std::cout << s.top() << "\n";
        s.pop();
        ++i;
    }
}

template<class T, class C>
void    push(ft::stack<T, C> &s, T *tab, size_t size)
{
    size_t i = 0;
    while (i < size)
    {
        s.push(tab[i]);
        std::cout << s.top() << "\n";
        ++i;
    }
}

template<class T, class C>
void    test_all(ft::stack<T, C> s, size_t del1, T *tab, size_t size, size_t del2)
{
    test(s);
    pop(s, del1);
    test(s);
    push(s, tab, size);
    test(s);
    pop(s, del2);
}

int main()
{
    int                 tabi[] = {12, 34, 84, 72, 37, 27, 90, 21, 8, 12, 24, 29, 32, 64};
    ft::list<int>       lst(tabi, tabi + 14);
    ft::stack<int, ft::list<int> >      si1;
    ft::stack<int, ft::list<int> >      si2(lst);

    std::string         s1("abc"), s2("uvk"), s3("j'en ai marre"), s4("pffffff..."), s5("8");
    std::string         tabs[] = {s1, s2, s3, s4, s5};
    ft::vector<std::string>       vec(tabs, tabs + 5);
    ft::stack<std::string, ft::vector<std::string> >      ss1;
    ft::stack<std::string, ft::vector<std::string> >      ss2(vec);

    char                 tabc1[] = "rgjiqebfreiqugbfuoyg34ty2890478910rp][P;[Q;RL[Pllp[k342p[koprejfgovnuhpuwtre"
                                    "fnrijrgiwp[4p[kop45[]3o[ia0I908-09u890u8a90uUIJFOINTJW54JF0=9048352Y9"
                                    "jfneihiuhwu8t4y923y908743top[4'l5p[2k,lmvfklgjkou5402ut89yqwrtpgpfksd'";
    char                 tabc2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ft::list<char>       lstc1(tabc1, tabc1 + 216);
    ft::list<char>       lstc2(tabc2, tabc2 + 27);
    ft::stack<char, ft::list<char> >      sc1(lstc1);
    ft::stack<char, ft::list<char> >      sc2(lstc2);

    test_all(si2, 8, tabi, 5, 4);
    test_all(si1, 0, tabi, 14, 14);
    cmp(si2, si2);
    cmp(si1, si1);
    cmp(si1, si2);

    test_all(ss2, 2, tabs, 3, 5);
    test_all(ss1, 0, tabs, 5, 5);
    cmp(ss2, ss2);
    cmp(ss1, ss1);
    cmp(ss1, ss2);

    test_all(sc1, 105, tabc2, 20, 100);
    test_all(sc2, 0, tabc1, 200, 227);
    cmp(sc2, sc2);
    cmp(sc1, sc1);
    cmp(sc1, sc2);



    
}