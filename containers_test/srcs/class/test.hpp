#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>

template <typename T>
class test
{
    private:
        T   value;
    public:
        //CONSTRUCTOR DESTRUTOR
        test(): value(T()){}
        test(const T &value) : value(value){}
        test(const test &x) : value(x.value){}
        ~test(){}
        //OPERATOR
        test &operator=(const test<T> &x)
        {
            value = x.value;
            return (*this);
        }
        test &operator++(){ value++; return (*this); }
        test &operator--(){ value++; return (*this); }
        test operator++(int n)
        {
            test    a(value);

            (void)n;
            value++;
            return (a);
        }
        test operator--(int n)
         {
            test    a(value);

            (void)n;
            value--;
            return (a);
        }
        bool operator==(const test &x){return (value == x.value ? 1 : 0);}
        bool operator!=(const test &x){return (value != x.value ? 1 : 0);}
        bool operator<(const test &x){return (value < x.value ? 1 : 0);}
        bool operator>(const test &x){return (value > x.value ? 1 : 0);}
        bool operator>=(const test &x){return (value >= x.value ? 1 : 0);}
        bool operator<=(const test &x){return (value <= x.value ? 1 : 0);}

        T   &operator[](unsigned int n){ (void)n; return (value); }
        T   &operator*(){ return (value); }
        T   &operator->(){ return (value); }

        T   get_value()
        {
            return (value);
        }
};

template <typename T>
std::ostream&    operator<<(std::ostream &os, test<T> &t)
{
    os << t.get_value();
    return (os);
}

#endif