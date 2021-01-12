#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> //std::allocator<T>
# include <cstddef> //ptrdiff_t to difference_type
# include <stdexcept> //exception
# include "iterator.hpp"
# include <iostream> 

namespace   ft
{   
    template <typename T, class Alloc = std::allocator<T> >
    class   vector
    {
        public : //ITERATOR
            class iterator : public iterator_traits<T *>
            {
                public : //ITERATOR TYPEDEF
                    typedef typename iterator_traits<T *>::iterator_category iterator_category;
                    typedef typename iterator_traits<T *>::value_type value_type;
                    typedef typename iterator_traits<T *>::difference_type difference_type;
                    typedef typename iterator_traits<T *>::pointer pointer;
                    typedef typename iterator_traits<T *>::reference reference;
                private :
                    pointer array_pointer;
                public :
                    //ITERATOR CONSTRUCTOR
                    iterator(){ array_pointer = NULL; } //peut etre pas NULL
                    iterator(T *array_pointer) : array_pointer(array_pointer){}
                    iterator(const iterator &x){ array_pointer = x.array_pointer; }
                    //ITERATOR DESTRUCTOR
                    ~iterator(){}
                    //ITERATOR OPERATOR
                    iterator &operator=(const iterator &x){ array_pointer = x.array_pointer; return (*this); }

                    reference   operator[](unsigned int n){ return (array_pointer[n]); }
                    reference   &operator*(){ return (*array_pointer); }
                    pointer     operator->(){ return (array_pointer); }
                    
                    bool operator==(const iterator &x){ return (array_pointer == x.array_pointer ? 1 : 0); }
                    bool operator!=(const iterator &x){ return (array_pointer != x.array_pointer ? 1 : 0); }
                    bool operator<(const iterator &x){ return (array_pointer < x.array_pointer ? 1 : 0); }
                    bool operator>(const iterator &x){ return (array_pointer > x.array_pointer ? 1 : 0); }
                    bool operator>=(const iterator &x){ return (array_pointer >= x.array_pointer ? 1 : 0); }
                    bool operator<=(const iterator &x){ return (array_pointer <= x.array_pointer ? 1 : 0); }

                    iterator &operator+=(int n){ array_pointer += n; return (*this); }
                    iterator &operator-=(int n){ array_pointer -= n; return (*this); }
                    iterator &operator++(int n){ (void)n; ++array_pointer; return (*this); }
                    iterator &operator--(int n){ (void)n; --array_pointer; return (*this); }
                    iterator &operator++(){ array_pointer++; return (*this); }
                    iterator &operator--(){ array_pointer--; return (*this); }
                    iterator operator+(int n)
                    {
                        iterator x(*this);

                        x.array_pointer += n;
                        return (x);
                    }
                    iterator operator-(int n){ return (*this + (-n)); }

            };

        public : //TYPEDEF
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            //typedef pointer iterator;
            typedef const_pointer const_iterator;
            //typedef ??? reverse_iterator;
            //typedef ??? const_reverse_iterator;
            typedef ptrdiff_t difference_type; // a verifier
            typedef size_t size_type; // a verifier

        private : //PRIVATE VALUE
                allocator_type alloc;
                value_type  *array;
                size_t      array_capacity;
                size_t      array_size;

        public : //FUNCTION
            //CONSTRUCTOR
            explicit vector(const allocator_type& alloc = allocator_type()) : alloc(alloc)
            {
                array = NULL;
                array_capacity = 0;
                array_size = 0;
            }
            vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : alloc(alloc)
            {
                array = (this->alloc).allocate(static_cast<size_t>(n));
                for (array_capacity = 0; array_capacity < n; array_capacity++)
                    (this->alloc).construct(&array[array_capacity], val);
                array_size = array_capacity;
            }
            /*template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
            {
                InputIterator &first_copy = first;
                int            i;

                this->alloc = alloc;
                for(array_capacity = 0; first != last; first++)
                    array_capacity++;
                array = (this->alloc).allocate(static_cast<size_t>(array_capacity));

                first = first_copy;
                for(i = 0; first != last; i++)
                    (this->alloc).construct(&array[i], first++); //non verifier
                array_size = array_capacity;
            }*/
            vector(const vector &x)
            {
                size_type i;

                this->array_capacity = x.array_capacity;
                this->alloc = x.alloc;
                this->array_size = x.array_size;
                this->array = (this->alloc).allocate(static_cast<size_t>(array_capacity));
                for (i = 0; i < array_capacity; i++)
                    this->array[i] = x.array[i];
            }
            //DESTRUCTOR
            ~vector(void)
            {
                size_t  i;

                for (i = 0; i < array_size; i++)
                    (this->alloc).destroy(&array[i]);
                (this->alloc).deallocate(array, array_capacity);
            }
            //OPERATOR
            vector &operator=(const vector &x) // SUREMENT PAS BON MUST PRESERVE ALLOCATION
            {
                size_type i;

                this->~vector();
                this->array_capacity = x.array_capacity;
                this->alloc = x.alloc;
                this->array = (this->alloc).allocate(static_cast<size_t>(array_capacity));
                for (i = 0; i < array_capacity; i++)
                    this->array[i] = x.array[i];
                this->array_size = x.array_size;
                return (*this);
            } 
            reference   operator[](size_type n) //ADJUSTMENT
            {
                return(array[n]);
            }
            //ARRAY CAPACITY
            size_type  size() const
            {
                return (array_size);
            }
            size_type  max_size() const
            {
                return (alloc.max_size());
            }
            void    resize(size_type n, value_type val = value_type()) //ADJUSTMENT
            {
                int i;

                if (n > array_capacity)
                {
                    this->resize(n);
                }
                if (n > array_size)
                {
                    for (i = 0; i < array_capacity(); i++)
                        push_back(val);
                }
                else if (n < array_size)
                {
                    while (array_size-- > n)
                        (this->alloc).destroy(&array[array_size]);
                    (this->alloc).deallocate(&array[n], array_capacity);
                }

            }
            size_type   capacity() const
            {
                return(array_capacity);
            }
            bool    empty() const
            {
                return(array_size == 0 ? 1 : 0);
            }
            void reserve(size_type n) //EXCEPTION ALLOC
            {
                if (n > max_size())
                {
                    //probale throw
                }

                value_type  *new_array = alloc.allocate(static_cast<size_t>(n));
                size_t      i;

                if (n > array_capacity)
                {
                    for (i = 0; i < array_size; i++)
                        new_array[i] = array[i];
                    for (i = 0; i < array_size; i++)
                        (this->alloc).destroy(&array[i]);
                    (this->alloc).deallocate(array, array_capacity);
                    array_capacity = n;
                    array = new_array;
                }
                    
            }
            //MODIFIER
            void    push_back(const value_type &val) //that seems ok
            {
                size_type i = 0; 
                int n = array_capacity < 1 ? array_capacity + 1 : array_capacity * 2;
                value_type  *new_array;

                if (array_size < array_capacity)
                {
                    array[array_size] = val;
                }
                else
                {  
                    new_array = alloc.allocate(static_cast<size_t>(n));
                    for (i = 0; i < array_size; i++)
                        new_array[i] = array[i];
                    new_array[i] = val;
                    for (i = 0; i < array_size; i++)
                        (this->alloc).destroy(&array[i]);
                    (this->alloc).deallocate(array, array_capacity);
                    array_capacity = n;
                    array = new_array;
                }
                this->array_size++;
            }
            void    pop_back()
            {
                if (array_capacity > 0)
                    alloc.destroy(&array[--array_size]);
            }
    };

    /*template <Alloc>
    vector<bool>::vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : alloc(alloc)
        {
            n = n % 64 != 0 ? n / 64 + 64 : n / 64;
            array = (this->alloc).allocate(static_cast<size_t>(n));
            for (array_capacity = 0; array_capacity < n; array_capacity++)
                (this->alloc).construct(&array[array_capacity], val);
            array_size = array_capacity;
        }

    };*/

}

#endif