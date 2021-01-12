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
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;

        private :
            pointer array_pointer;

        public :
            //REVERSE_ITERATOR CONSTRUCTOR
            reverse_iterator(){ array_pointer = NULL; } //peut etre pas NULL
            reverse_iterator(Iterator &it_to_reverse) : array_pointer(&*(it_to_reverse - 1)){}
            reverse_iterator(const reverse_iterator &x){ array_pointer = x.array_pointer; }
            //REVERSE_ITERATOR DESTRUCTOR
            ~reverse_iterator(){}
            //REVERSE_ITERATOR OPERATOR
            reverse_iterator &operator=(const reverse_iterator &x){ array_pointer = x.array_pointer; return (*this); }
            reverse_iterator &operator+=(int n){ array_pointer.Iterator::operator-=(n); return (*this); }
            reverse_iterator &operator-=(int n){ array_pointer.Iterator::operator+=(n); return (*this); }
            reverse_iterator &operator++(int n){ array_pointer.Iterator::operator--(n); return (*this); }
            reverse_iterator &operator--(int n){ array_pointer.Iterator::operator++(n); return (*this); }
            reverse_iterator &operator++(){ array_pointer.Iterator::operator--(); return (*this); }
            reverse_iterator &operator--(){ array_pointer.Iterator::operator++(); return (*this); }
            reverse_iterator operator+(int n){ return(array_pointer.Iterator::operator-(n)); }
            reverse_iterator operator-(int n){ return(array_pointer.Iterator::operator+(n)); }
    };

};


#endif