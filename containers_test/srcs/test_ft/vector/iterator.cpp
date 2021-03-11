#include "vector.hpp"
#include <iostream>
#include <string>

template<typename T>
void cmp(typename ft::vector<T>::iterator it1, typename ft::vector<T>::iterator it2)
{
    typename ft::vector<T>::const_iterator const_it1(it1);
    typename ft::vector<T>::const_iterator const_it2(it2);

    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << " ";

    std::cout << (it1 > it2) << " ";
    std::cout << (it2 > it1) << " ";
    std::cout << (it1 < it2) << " ";
    std::cout << (it2 < it1) << " ";

    std::cout << (it1 >= it2) << " ";
    std::cout << (it2 >= it1) << " ";
    std::cout << (it1 <= it2) << " ";
    std::cout << (it2 <= it1) << " ";



    std::cout << (const_it1 == const_it2) << " ";
    std::cout << (const_it2 == const_it1) << " ";
    std::cout << (const_it1 != const_it2) << " ";
    std::cout << (const_it2 != const_it1) << " ";

    std::cout << (const_it1 > const_it2) << " ";
    std::cout << (const_it2 > const_it1) << " ";
    std::cout << (const_it1 < const_it2) << " ";
    std::cout << (const_it2 < const_it1) << " ";

    std::cout << (const_it1 >= const_it2) << " ";
    std::cout << (const_it2 >= const_it1) << " ";
    std::cout << (const_it1 <= const_it2) << " ";
    std::cout << (const_it2 <= const_it1) << " ";


    std::cout << (const_it1 == it2) << " ";
    std::cout << (it2 == const_it1) << " ";
    std::cout << (const_it1 != it2) << " ";
    std::cout << (it2 != const_it1) << " ";

    std::cout << (const_it1 > it2) << " ";
    std::cout << (it2 > const_it1) << " ";
    std::cout << (const_it1 < it2) << " ";
    std::cout << (it2 < const_it1) << " ";

    std::cout << (const_it1 >= it2) << " ";
    std::cout << (it2 >= const_it1) << " ";
    std::cout << (const_it1 <= it2) << " ";
    std::cout << (it2 <= const_it1) << " ";


    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << " ";

    std::cout << (it1 > it2) << " ";
    std::cout << (it2 > it1) << " ";
    std::cout << (it1 < it2) << " ";
    std::cout << (it2 < it1) << " ";

    std::cout << (it1 >= it2) << " ";
    std::cout << (it2 >= it1) << " ";
    std::cout << (it1 <= it2) << " ";
    std::cout << (it2 <= it1) << " "; 
}

template<typename T>
void reverse_cmp(typename ft::vector<T>::reverse_iterator it1, typename ft::vector<T>::reverse_iterator it2)
{
    typename ft::vector<T>::const_reverse_iterator const_it1(it1);
    typename ft::vector<T>::const_reverse_iterator const_it2(it2);

    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << " ";

    std::cout << (it1 > it2) << " ";
    std::cout << (it2 > it1) << " ";
    std::cout << (it1 < it2) << " ";
    std::cout << (it2 < it1) << " ";

    std::cout << (it1 >= it2) << " ";
    std::cout << (it2 >= it1) << " ";
    std::cout << (it1 <= it2) << " ";
    std::cout << (it2 <= it1) << " ";


    std::cout << (const_it1 == const_it2) << " ";
    std::cout << (const_it2 == const_it1) << " ";
    std::cout << (const_it1 != const_it2) << " ";
    std::cout << (const_it2 != const_it1) << " ";

    std::cout << (const_it1 > const_it2) << " ";
    std::cout << (const_it2 > const_it1) << " ";
    std::cout << (const_it1 < const_it2) << " ";
    std::cout << (const_it2 < const_it1) << " ";

    std::cout << (const_it1 >= const_it2) << " ";
    std::cout << (const_it2 >= const_it1) << " ";
    std::cout << (const_it1 <= const_it2) << " ";
    std::cout << (const_it2 <= const_it1) << " ";


    std::cout << (const_it1 == it2) << " ";
    std::cout << (it2 == const_it1) << " ";
    std::cout << (const_it1 != it2) << " ";
    std::cout << (it2 != const_it1) << " ";

    std::cout << (const_it1 > it2) << " ";
    std::cout << (it2 > const_it1) << " ";
    std::cout << (const_it1 < it2) << " ";
    std::cout << (it2 < const_it1) << " ";

    std::cout << (const_it1 >= it2) << " ";
    std::cout << (it2 >= const_it1) << " ";
    std::cout << (const_it1 <= it2) << " ";
    std::cout << (it2 <= const_it1) << " ";


    std::cout << (it1 == it2) << " ";
    std::cout << (it2 == it1) << " ";
    std::cout << (it1 != it2) << " ";
    std::cout << (it2 != it1) << " ";

    std::cout << (it1 > it2) << " ";
    std::cout << (it2 > it1) << " ";
    std::cout << (it1 < it2) << " ";
    std::cout << (it2 < it1) << " ";

    std::cout << (it1 >= it2) << " ";
    std::cout << (it2 >= it1) << " ";
    std::cout << (it1 <= it2) << " ";
    std::cout << (it2 <= it1) << " ";
}

template<typename T>
ft::vector<T>     create(ft::vector<T> lst)
{
    return(ft::vector<T>(lst));
}

template<typename T>
ft::vector<T>     create(size_t end_nb, T *tab)
{
    typename ft::vector<T>::iterator beg(tab);
    typename ft::vector<T>::iterator end(&tab[end_nb]);

    return(ft::vector<T>(beg, end));
}

template<typename T>
ft::vector<T>     create(size_t size, const T &val)
{
    return(ft::vector<T>(size, val));
}

template<typename T>
ft::vector<T>     create(size_t size)
{
    return(ft::vector<T>(size));
}

template<typename T>
ft::vector<T>     create()
{
    return(ft::vector<T>());
}

template <typename T>
void    func(ft::vector<T> &lst1)
{
    size_t i = 0;
    typename ft::vector<T>::iterator it(lst1.begin());
    typename ft::vector<T>::iterator const_it(it);
    typename ft::vector<T>::iterator beg(lst1.begin());
    typename ft::vector<T>::iterator end(lst1.end());

    while (it < end)
    {
        std::cout << *it++ << " ";
        std::cout << *const_it++ << " ";
    }
    std::cout << "\n";

    while (it > beg)
    {
        std::cout << *--it << " ";
         std::cout << *--const_it << " ";
    }
    std::cout << "\n";

    while (it < end)
    {
        std::cout << *it << " ";
        std::cout << *const_it << " ";
        ++it;
        ++const_it;
    }
    std::cout << "\n";

    while (it > beg)
    {
        if (it == end)
        {
            --it;
            --const_it;
        }
        else
        {
            std::cout << *it-- << " ";
            std::cout << *const_it-- << " ";
        }
    }
    std::cout << "\n";

    while(it + i < end)
    {
        std::cout << *(it + i) << " ";
        std::cout << *(const_it + i++) << " ";
    }
    i = 0;
    while(it - i > beg)
    {
        if (it != end)
        {
            std::cout << *(it - i) << " ";
            std::cout << *(const_it - i--) << " ";
        }
    }

    i = 0;
    while(it + i < end)
    {
        it += i;
        std::cout << *it << " ";
        it -= i;
        std::cout << *it << " ";
        ++i;
    }
}

template <typename T>
void    rev_func(ft::vector<T> &lst1)
{
    size_t i = 0;
    typename ft::vector<T>::reverse_iterator it(lst1.begin());
    typename ft::vector<T>::const_reverse_iterator const_it(it);
    typename ft::vector<T>::reverse_iterator beg(lst1.begin());
    typename ft::vector<T>::reverse_iterator end(lst1.end());

    while (it < end)
    {
        std::cout << *it-- << " ";
        std::cout << *const_it-- << " ";
    }
    std::cout << "\n";

    while (it > beg)
    {
        std::cout << *++it << " ";
         std::cout << *++const_it << " ";
    }
    std::cout << "\n";

    while (it < end)
    {
        std::cout << *it << " ";
        std::cout << *const_it << " ";
        --it;
        --const_it;
    }
    std::cout << "\n";

    while (it > beg)
    {
        if (it == end)
        {
            ++it;
            ++const_it;
        }
        else
        {
            std::cout << *it++ << " ";
            std::cout << *const_it++ << " ";
        }
    }
    std::cout << "\n";

    while(it - i < end)
    {
        std::cout << *(it - i) << " ";
        std::cout << *(const_it - i--) << " ";
    }
    i = 0;
    while(it + i > beg)
    {
        if (it != end)
        {
            std::cout << *(it + i) << " ";
            std::cout << *(const_it + i++) << " ";
        }
    }

    i = 0;
    while(it - i < end)
    {
        it -= i;
        std::cout << *it << " ";
        it += i;
        std::cout << *it << " ";
        --i;
    }
}

template <typename T>
void    test_all(T val, size_t size, T *tab, size_t size1, T val2, size_t size2)
{
    size_t i = 0;
    size_t j = 0;
    ft::vector<T>   lst1(size, val);
    ft::vector<T>   lst2(size2, val2);
    ft::vector<T>   lst3(create(size1, tab));
    ft::vector<T>   lst4(size1);
    ft::vector<T>   lst5(size, val);
    ft::vector<T>   tab_lst[] = {lst1, lst2, lst3, lst4, lst5};

    lst5.push_back(val2);
    while(i < 5)
    {
        j = 0;
        rev_func(tab_lst[i]);
        while(j < 5)
        {
            cmp<T>(tab_lst[i].begin(), tab_lst[i].begin() + 1);
            cmp<T>(tab_lst[j].begin(), tab_lst[j].begin() + 1);
            cmp<T>(tab_lst[i].begin(), tab_lst[j].begin());

            reverse_cmp<T>(tab_lst[i].rbegin(), tab_lst[i].rbegin() + 1);
            reverse_cmp<T>(tab_lst[j].rbegin(), tab_lst[j].rbegin() + 1);
            reverse_cmp<T>(tab_lst[i].rbegin(), tab_lst[j].rbegin());
            ++j;
        }
        ++i;
    }
}

int main()
{
    int tab_int[] = {12, 24, 96, -18, -124, 36, 152, -17, 99, 41, 27, 46, 96, 205, 211, -27, 4, 3, 6, 9, 98, 99,
                    100, -266, 1052, -99, -206, -8};
    char    tab_char[] = "enkqwj4u43'2[epwlfrn32[gfp24i3[jfrifq2p'[g2'q[34tjmfpk32][tfm5igmq][pwmgfqnirtq5jgioqr'q[23n"
                        "nfjieqwhuiqp3r43p;]342][54]32']5][235p3]-0=0295=19534591`mkmnklrewnejrtpo4rkpwop[w3qjjfriw["
                        "kfioqphir3o1il]p[ro098y21rt9yr79quwkeqmdflvmlr,2prejmcfoeqwjroi[432tfowor]gkro[wkgo[j2giow2"
                        "huie2  bidiuoqghfiqehbnfiur3nipu2ty90324u85r9uifncieoqnhfguidenjqpfhhhgurejrnjwipnrgiwenijg"
                        "jfiqrjfjhu9w4uy82378y458y23785y754hjkewndjkfnijnijewpfohnjinrghiuhriewpghruiewhgiuwhighuiwg"
                        "jdfoqiprh3uiyr5u972958943265yhjkfdhfgdf'akq]rkfop[dksop[32krtop[jtopjgfijnijbqrporkgmoqjipg"
                        "jifoeqhuhfiwhdiufhriqhefhjfdhiouuy89759205y7864't2k4[ppo3p[oopjfdkqhohj324hj5lrtjljdjaoighjro"
                        "kdfweoqjrui3u45947986239hjkfdhjkgbfnihshduifh8734tyrhdjkahf94ythurheuty84uhryruiewhtu42h2uhtg"
                        "io234ujt3uy934y28ryut;435[[][[fewg[ep[riopjifh3j21b4hjvhj4kq78g90a789gyanjkfnewnfijfngdhipah"
                        "o*i192  bidi*oqgokiq19obnki*r3nip*2ty92324*85r9*iknci19oqnokg*id19njqpkooog*r19jrnjwipnrgiw19nijg"
                        "jkiqrjkjo*9w4*y82378y458y23785y754ojk19wndjkknijnij19wpkoonjinrgoi*ori19wpgor*i19wogi*woigo*iwg"
                        "jdkoqipro3*iyr5*972958943265yojkkdokgdk'akq]rkkop[dksop[32krtop[jtopjgkijnijbqrporkgmoqjipg"
                        "jiko19qo*okiwodi*koriqo19kojkdoio**y89759225y7864't2k4[ppo3p[oopjkdkqoooj324oj5lrtjljdjaoigojro"
                        "kdkw19oqjr*i3*45947986239ojkkdojkgbkniosod*iko8734tyrodjkaok94yto*ro19*ty84*oryr*i19wot*42o2*otg"
                        "io234*jt3*y934y28ry*t;435[[][[k19wg[19p[riopjiko3j21b4ojvoj4kq78g92a789gyanjkkn19wnkijkngdoipao";
    double  tab_db[] = {12.97, 42.92, 105.17, 18.150, -42.14, -51.10};
    std::string str("string1");
    std::string str1("string2");
    std::string str2("abracadabra");
    std::string str3("oulaoup");
    std::string str4("yes challenge");
    std::string str5("a toi de jouer");
    std::string str6("c'est l'heure du du dud du duel");
    std::string str7("oupqlinda");
    std::string str8("-------X");
    std::string str9("...");
    std::string str10("");
    std::string str11("c");
    std::string tab_str[] = {str, str1, str2, str3, str4, str5, str6, str7, str8, str8, str10, str11};

    test_all(12, 431, tab_int, 28, 42, 801);
    test_all('c', 231, tab_char, 1395, 'S', 1);
    test_all(12.94, 40, tab_db, 6, 90.18, 331);
    test_all(str1, 20, tab_str, 12, str5, 912);
}
   