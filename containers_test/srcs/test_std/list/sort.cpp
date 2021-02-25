#include <list>
#include <vector>
#include <iostream>
#include <string>

template<typename T>
int     func1(T value1, T value2)
{
    (void)value1;
    (void)value2;
    return (value1 > value2);
}

template<typename T>
int     func2(T value1, T value2)
{
    (void)value1;
    (void)value2;
    return (0);
}

template<typename T>
int     func3(T value1, T value2)
{
    return (static_cast<bool>(value1) < static_cast<bool>(value2));
}

template<>
int     func3<std::string>(std::string value1, std::string value2)
{
    return (value1.size() < value2.size());
}

template<typename T>
int     func4(T value1, T value2)
{
    return (value1 < value2);
}

template <typename T>
void    test(std::list<T>  &list, typename std::list<T>::iterator old_it, size_t n)
{
    size_t i;
    try
    {
        for (i = 0; i < n; i++)
        {
            if (old_it != list.end())
                std::cout << *old_it++ << " ";
        }
        std::cout << "\n";
        for (i = 0; i < n; i++)
        {
            if (old_it != list.end())
                std::cout << *++old_it << " ";
        }
        std::cout << "\n";

        typename std::list<T>::iterator it(list.begin());
        for (i = 0; i < list.size(); i++)
        {
            std::cout << *it++ << " ";
        }
        std::cout << "\n";
        for (i = 0; i < list.size(); i++)
        {
            std::cout << *++it << " ";
        }
        std::cout << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << list.empty() << " ";
    std::cout << list.size() << " ";
    std::cout << list.max_size() << " ";
    if (list.size() > 0)
    {
        std::cout << *list.begin() << " ";
        std::cout << *--list.end() << " "; // a partir de la indefini
        std::cout << *list.rbegin() << " ";
        std::cout << *--list.rend() << " ";
        std::cout << list.front() << " ";
        std::cout << list.back() << " ";
    }
    else
    {
        std::cout << (list.begin() == list.end()) << " ";
        std::cout << (list.rbegin() == list.rend()) << " ";
        list.front();
        list.back();
    }
    std::cout << "\n";
}

template <typename T>
void    test(std::list<T *>  &list, typename std::list<T>::iterator old_it, size_t n)
{
    size_t i;
    size_t j;
    try
    {
        for (i = 0; i < n; i++)
        {
            if (old_it != list.end())
            {
                for (j = 0; (*old_it)[j] != 0; j++)
                    std::cout << (*old_it)[j];
            std::cout << " ";
            }
            old_it++;
        }
        std::cout << "\n";
        for (i = 0; i < n; i++)
        {
            if (old_it != list.end())
            {
                ++old_it;
                for (j = 0; (*old_it)[j] != 0; j++)
                    std::cout << (*old_it)[j];
                std::cout << " ";
            }
        }
        std::cout << "\n";

        typename std::list<T *>::iterator it(list.begin());
        for (i = 0; i < list.size(); i++)
        {
            for (j = 0; (*it)[j] != 0; j++)
                std::cout << (*it)[j];
            std::cout << " ";
            it++;
        }
        std::cout << "\n";
        for (i = 0; i < list.size(); i++)
        {
            ++it;
            for (j = 0; (*it)[j] != 0; j++)
                std::cout << (*it)[j];
            std::cout << " ";
        }
        std::cout << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << list.empty() << " ";
    std::cout << list.size() << " ";
    std::cout << list.max_size() << " ";
    if (list.size() > 0)
    {
        std::cout << **list.begin() << " ";
        std::cout << **list.rbegin() << " ";
        std::cout << **--list.end() << " "; // a partir de la indefini
        std::cout << **--list.rend() << " ";
        std::cout << *list.front() << " ";
        std::cout << *list.back() << " ";
    }
    else
    {
        std::cout << (list.begin() == list.end()) << " ";
        std::cout << (list.rbegin() == list.rend()) << " ";
        list.front();
        list.back();
    }
    
    std::cout << "\n";
}

template <typename T>
void            test_func(std::list<T> lst, int (*func)(T, T))
{
    typename std::list<T>::iterator old_it(lst.begin());

    lst.sort(func);
    test(lst, old_it, lst.size());
}

template <typename T>
void            test_func(std::list<T> lst)
{
    typename std::list<T>::iterator old_it(lst.begin());

    lst.sort();
    test(lst, old_it, lst.size());
    
}

template <typename T>
std::list<T>        create(T *tab, size_t size)
{
    typename std::vector<T>::iterator beg(tab);
    typename std::vector<T>::iterator end(tab + size);

    std::list<T>     lst(beg, end);

    return (lst);
}

template<typename T>
void    test_all(T *tab, size_t size, T *tab1, size_t size1, T *tab2, size_t size2, T val, size_t size3)
{
    size_t  i = 0;
    int (*func[])(T, T) = {func1, func2, func3, func4};
    std::list<T> lst(create(tab, size));
    std::list<T> lst1(create(tab1, size1));
    std::list<T> lst2(create(tab2, size2));
    std::list<T> lst3(size3, val);
    std::list<T> lst4(1, val);
    std::list<T> lst5;

    test_func(lst);
    test_func(lst1);
    test_func(lst2);
    test_func(lst3);
    test_func(lst4);
    test_func(lst5);

    while(i < 4)
    {
        test_func(lst, func[i]);
        test_func(lst1, func[i]);
        test_func(lst2, func[i]);
        test_func(lst3, func[i]);
        test_func(lst4, func[i]);
        test_func(lst5, func[i]);
        ++i;
    }
}

template<typename T>
void    test_all(T *tab, size_t size)
{
    size_t  i = 0;
    int (*func[])(T, T) = {func1, func2, func3, func4};
    std::list<T> lst(create(tab, size));


    test_func(lst);

    while(i < 4)
    {
        test_func(lst, func[i]);
        ++i;
    }
}

int main()
{
    std::string     str1("test1");
    std::string     str2("test2");
    std::string     str3("test3hertgsfehe");
    std::string     str4("oups");
    std::string     str5("allezfrwegrewbre");
    std::string     str6("word");
    std::string     str7("oulaoup");
    std::string     str8("pause");
    std::string     str9("poseyyetrgevsdevfdsfv");
    std::string     str10("bouyachaka");
    std::string     tab_str[] = {str1, str1, str2, str3, str4, str5, str6, str7, str8, str9, str10, str7};
    std::string     tab_str1[] = {str1, str2, str3, str4, str5, str6, str7, str8, str9, str10, str7};
    std::string     tab_str2[] = {str1, str1, str4, str2, str3, str2, str3, str4, str5, str7, str8, str9, str6, str10, str7};
    int             tab_int[] = {73981, 348120, 341, 431289, 3123, 8902, 12, 3412, 93, 1324932, 432198};
    int             tab_int1[] = {0, 21, 37, 48, 99, 205, 253, 412 ,442, 803, 851, 8009};
    int             tab_int2[] = {-51432, 54, -5423, -4523, 5423, 5421, 12354, 635, -25, -425, 5423, -2435, 2345, -25, 2543};
    int             tab_int3[] = {-12, 96, 8255, -601, -92, -17, 607, 694, 632, 4005, 918, 441, -100023, 90321,
                                5421, 12354, 635, -25, -425, 5423, -2435, 2345, -25, 2543, 901, 442, 665, 741, 301, -10000,
                                441, 801283, -10233, 8123, 901, -441, -603, -18921, 341, -401, -702, -701, -703, 704, 18012,
                                648, 217233, 524, -6525, -5632, -4632, 56225, 4236324, 643264, 6236, 435, 235, 6236, 2346, 623};
    double          tab_db[] = {12.94, 488.17, 901.12, 900.3};
    double          tab_db1[] = {12.94, 488.17, 1442.21, 901.12, 900.13, 19.14};
    double          tab_db2[] = {12.94, 488.17, 1442.21, 901.12, 441.12, 234.542, 542.34};
    char             tab_char[] = "BCADEFGHIJKLMNOPQRSTUVW";
    char             tab_char1[] = "JHUGYVHJBDAHSGigbihguyhv[]';456734][pkofmpvkd csjdbhrgjrfadjnh34q45264352]3=32fda";
    char             tab_char2[] = "dc";
     char             tab_char3[] = "geh21eyftvfhbe280y9wuoherjewokj;frewlfpo[jf;rt3mkefi]j[ghojnt4'rwekfoi[h"
                                    "gubjtgnrwekfqloib[hgonrtkmfoej[ihgojenr;fkmejighr[eujwnfkdmobj[g"
                                    "bjfekwqnfjdohjebrknwmfkjnbk rmfelbnkmgergtreeth;5[6'43[]243565yt't3456'"
                                    "ejfwnkddhijeknmjdhngkemkdjohgnkre mwfkjbhuijfkln ew3'2p4k153t3yt"
                                    "ghrjl2knefjhjebre2nmrwjfghoerjnkm2eejhlntk3mjertkn"
                                    "hrj2kbeqnwfhugirbj2nkwihuigrbj423nekwjrfhuriejk3op4'5k3lpo]i"
                                    "ihujnewqrkguhtirjb243knerqwiuho;tjnlk23k    eopqrwji;nk345m3l1p25[o6jl78p432[kop1j"
                                    "3iouh5j2k4nmlrituohj4nkl53m2p[erowjklmt52;34p[oreigejp;kelmy/,.6534lqrkofjbdksmjsnbkf"
                                    "iothrj23nekrfgiuhjnre2mrkwejiohknrm2elqwkfojihnrkemw,qdflkopijnrke2mwkfodpijfkn"
                                    "rie2hb  kjnwqhugoiewhduo3l456468953208374592037ytuihjk543trwe8gfdvu9ihjont5mk4o132ir9twe-"
                                    "gdu0iojklreqwpo]-p[peq-0hojnerfkojibghorjenrthu4iejqrwnfhurtjwnkrjhijgfwrjewnkdfjighfjn"
                                    "lfegklnmrwfddjsnerwmfdsdjfbhfknemkwfjdhfkbnemdfwjbfnem4rno23tjio4nrffgiup345rmok2gnpo"
                                    "nfem fwsdjnkfmew,fkjdnfkmewr rfjnfdk emwf,djnkfemw ,fdnbkf emfwjdhnkrm13243u5uio3'@#"
                                    "jngkr emqwhugtbjrn23kerqwhuettbjnrewjeihgbnm,rewl;rwlpgr4tojuy634kop4ji924uhtjmn2ko3";

    //std::cout << "a\n";
    test_all(tab_int, 11, tab_int1, 12, tab_int2, 15, 4, 8);
    test_all(tab_char, 24, tab_char1, 82, tab_char2, 3, 'X', 151);
    test_all(tab_db, 4, tab_db1, 6, tab_db2, 7, 47.14, 10027);
    test_all(tab_str, 12, tab_str1, 11, tab_str2, 15, static_cast<std::string>("j"), 310);
    test_all(tab_int3, 60);
    test_all(tab_char3, 1057);

    return (0);
}