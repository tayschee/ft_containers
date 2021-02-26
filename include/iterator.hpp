#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef> //ptrdiff_t
# include "utils.hpp"

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
            explicit reverse_iterator(const iterator_type &it_to_reverse){ it = it_to_reverse; }

            template<class It>
            reverse_iterator(const reverse_iterator<It> &x){ it = x.base(); }

            ~reverse_iterator(){}

            iterator_type base() const { return (it); }

            //REVERSE_ITERATOR OPERATOR
            template<class It>
            reverse_iterator &operator=(const reverse_iterator<It> &x){ it = x.base(); return (*this); }

            reference   operator[](difference_type n) const { return ( it[-n - 1]); }
            reference   operator*() const { return (*--base()); }
            pointer     operator->() const { return (&(*--base())); }

            template<class It>
            bool operator==(const reverse_iterator<It> &x) const { return (it == x.base() ? 1 : 0); } //why ???
            template<class It>
            bool operator!=(const reverse_iterator<It> &x) const { return (it != x.base() ? 1 : 0); } //why ???
            template<class It>
            bool operator<(const reverse_iterator<It> &x) const { return (it > x.base() ? 1 : 0); }
            template<class It>
            bool operator>(const reverse_iterator<It> &x) const { return (it < x.base() ? 1 : 0); }
            template<class It>
            bool operator>=(const reverse_iterator<It> &x) const { return (it <= x.base() ? 1 : 0); }
            template<class It>
            bool operator<=(const reverse_iterator<It> &x) const { return (it >= x.base() ? 1 : 0); }

            reverse_iterator &operator+=(int n){ it -= n; return (*this); }
            reverse_iterator &operator-=(int n){ it += n; return (*this); }
            reverse_iterator &operator++(){ --it; return (*this); }
            reverse_iterator &operator--(){ ++it; return (*this); }
            reverse_iterator operator++(int n)
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