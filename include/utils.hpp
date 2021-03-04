#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef> //ptrdiff_t
# include <stdexcept>

namespace ft
{
    template <bool Cond, typename Result=void>
    struct enable_if { };

    template <typename Result>
    struct enable_if<true, Result>
    {
        typedef Result type;
    };

    template<typename T1, typename T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        T1      first;
        T2      second;
        
        pair() : first(first_type()), second(second_type()) {}

        template<class U, class V>
        pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}

        pair(const first_type &a, const second_type &b) : first(a), second(b) {}

        pair    &operator=(const pair &pr)
        {
            first = pr.first;
            second = pr.second;

            return (*this);
        }

        bool operator==(const pair &pr)
        {
            return (first == pr.first);
        }
        bool operator!=(const pair &pr)
        {
            return (first != pr.first);
        }
        bool operator<(const pair &pr)
        {
            return (first < pr.first);
        }
        bool operator>(const pair &pr)
        {
            return (first > pr.first);
        }
         bool operator<=(const pair &pr)
        {
            return (first <= pr.first);
        }
        bool operator>=(const pair &pr)
        {
            return (first >= pr.first);
        }
    };

    class   exception : public std::exception
    {
        private :
            exception    &operator=(const exception &x) { (void)x; return (*this); }
        public :
            exception(){}
            exception(const exception &x){}
            virtual ~exception() throw() {}
    };
    
    template<class Type>
    struct is_integral
    {
        static const bool value = false;
    };
    template<>
    struct is_integral<bool>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<char>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<signed char>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<wchar_t>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<short>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<unsigned short>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<int>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<long>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<unsigned long>
    {
        static const bool value = true;
    };
    
    template<>
    struct is_integral<float>
    {
        static const bool value = false;
    };
    template<>
    struct is_integral<double>
    {
        static const bool value = false;
    };
    template<>
    struct is_integral<long double>
    {
        static const bool value = false;
    };

};


#endif