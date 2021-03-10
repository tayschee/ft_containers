#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <string>
#include <deque>

template<class T, class C>
void    test(const std::queue<T, C> &s)
{
    std::cout << s.size();
    std::cout << s.empty();
}

template<class T, class C>
void    cmp(const std::queue<T, C> &s1, const std::queue<T, C> &s2)
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
void    pop(std::queue<T, C> &s, size_t size)
{
    size_t i = 0;
    while (i < size)
    {
        std::cout << s.front() << "\n";
        std::cout << s.back() << "\n";
        s.pop();
        ++i;
    }
}

template<class T, class C>
void    push(std::queue<T, C> &s, T *tab, size_t size)
{
    size_t i = 0;
    while (i < size)
    {
        s.push(tab[i]);
        std::cout << s.front() << "\n";
        std::cout << s.back() << "\n";
        ++i;
    }
}

template<class T, class C>
void    test_all(std::queue<T, C> s, size_t del1, T *tab, size_t size, size_t del2)
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
    std::list<int>       lst(tabi, tabi + 14);
    std::queue<int, std::list<int> >      si1;
    std::queue<int, std::list<int> >      si2(lst);

    std::string         s1("abc"), s2("uvk"), s3("j'en ai marre"), s4("pffffff..."), s5("8");
    std::string         tabs[] = {s1, s2, s3, s4, s5};
    std::deque<std::string>       vec(tabs, tabs + 5);
    std::queue<std::string, std::deque<std::string> >      ss1;
    std::queue<std::string, std::deque<std::string> >      ss2(vec);

    char                 tabc1[] = "rgjiqebfreiqugbfuoyg34ty2890478910rp][P;[Q;RL[Pllp[k342p[koprejfgovnuhpuwtre"
                                    "fnrijrgiwp[4p[kop45[]3o[ia0I908-09u890u8a90uUIJFOINTJW54JF0=9048352Y9"
                                    "jfneihiuhwu8t4y923y908743top[4'l5p[2k,lmvfklgjkou5402ut89yqwrtpgpfksd'";
    char                 tabc2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::list<char>       lstc1(tabc1, tabc1 + 216);
    std::list<char>       lstc2(tabc2, tabc2 + 27);
    std::queue<char, std::list<char> >      sc1(lstc1);
    std::queue<char, std::list<char> >      sc2(lstc2);

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