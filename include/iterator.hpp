#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef> //ptrdiff_t

namespace ft
{
    struct input_iterator_tag{};
    struct output_iterator_tag{};
    struct forward_iterator_tag{};
    struct bidirectional_iterator_tag{};
    struct random_access_iterator_tag{};

    template    <class Category,
                class T,
                class Distance = ptrdiff_t,
                class Pointer = T*,
                class Reference = T&>
    struct iterator
    {
            typedef Category    iterator_category;
            typedef T   value_type;
            typedef Distance difference_type;
            typedef Pointer pointer;
            typedef Reference reference;
    };

    template <class Iterator> class iterator_traits
    {
        public :
            typedef typename Iterator::iterator_category iterator_category;
            typedef typename Iterator::value_type value_type;
            typedef typename Iterator::difference_type difference_type;
            typedef typename Iterator::pointer pointer;
            typedef typename Iterator::reference reference;
    };

    template <class T> class iterator_traits<T *>
    {
        public :
            typedef ft::random_access_iterator_tag iterator_category;
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;

    };

    template <class T> class iterator_traits<const T *>
    {
        public :
            typedef ft::random_access_iterator_tag iterator_category;
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef const T* pointer;
            typedef const T& reference;
    };

    template <class Iterator> class reverse_iterator
    {
        public : //REVERSE_ITERATOR TYPEDEF
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;

        private:
            iterator_type it;
        
        public :
            //REVERSE_ITERATOR CONSTRUCTOR DESTRUCTOR
            explicit reverse_iterator(){ it = iterator_type(); }
            explicit reverse_iterator(const Iterator &it_to_reverse){ it = it_to_reverse - 1; }
            reverse_iterator(const reverse_iterator &x){ it = x.it; } 
            ~reverse_iterator(){}

            //REVERSE_ITERATOR OPERATOR
            reverse_iterator &operator=(const reverse_iterator &x){ it = x.it; return (*this); }

            reference   operator[](difference_type n) const { return ( it[-n]); }
            reference   operator*() const { return (*it); }
            pointer     operator->() const { return (&*it); }

            bool operator==(const reverse_iterator &x) const { return (it == x.it ? 1 : 0); } //why ???
            bool operator!=(const reverse_iterator &x) const { return (it != x.it ? 1 : 0); } //why ???
            bool operator<(const reverse_iterator &x) const { return (it < x.it ? 0 : 1); }
            bool operator>(const reverse_iterator &x) const { return (it > x.it ? 0 : 1); }
            bool operator>=(const reverse_iterator &x) const { return (it >= x.it ? 0 : 1); }
            bool operator<=(const reverse_iterator &x) const { return (it <= x.it ? 0 : 1); }

            reverse_iterator &operator+=(int n){ it -= n; return (*this); }
            reverse_iterator &operator-=(int n){ it += n; return (*this); }
            reverse_iterator &operator++(){ --it; return (*this); }
            reverse_iterator &operator--(){ ++it; return (*this); }
            reverse_iterator operator++(int n) //maybe x not necessary
            {
                reverse_iterator    x(*this);

                it.operator--(n);
                return(x);
            }
            reverse_iterator operator--(int n)
            {
                reverse_iterator    x(*this);

                it.operator++(n);
                return(x);
            }

            reverse_iterator operator+(int n) const
            {
                reverse_iterator    x(*this);

                x.it -= n;
                return(x);
            }
            reverse_iterator operator-(int n) const
            {
                reverse_iterator    x(*this);

                x.it += n;
                return(x);
            }
    };

};


#endif