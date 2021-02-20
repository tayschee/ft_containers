#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> //std::allocator<T>
# include <stdexcept> //exception
# include "iterator.hpp"
# include <iostream> 
# include <algorithm> //pas sur
# include <sstream> //conversion int to string (for exception)

namespace   ft
{   
    template <typename T, class Alloc = std::allocator<T> >
    class   vector
    {
        public :
            class const_iterator;
            class iterator
            {
                public : //iterator TYPEDEF
                    typedef typename iterator_traits<T *>::iterator_category iterator_category;
                    typedef typename iterator_traits<T *>::value_type value_type;
                    typedef typename iterator_traits<T *>::difference_type difference_type;
                    typedef typename iterator_traits<T *>::pointer pointer;
                    typedef typename iterator_traits<T *>::reference reference;
                private :
                    pointer array_pointer;
                public :
                    //iterator CONSTRUCTOR
                    explicit iterator(){ array_pointer = NULL; } //peut etre pas NULL
                    explicit iterator(pointer array_pointer) : array_pointer(array_pointer){}
                    iterator(const iterator &x){ array_pointer = x.array_pointer; }
                    //iterator DESTRUCTOR
                    ~iterator(){}
                    //iterator OPERATOR
                    iterator &operator=(const iterator &x){ array_pointer = x.array_pointer; return (*this); }

                    reference   operator[](unsigned int n) const { return (array_pointer[n]); }
                    reference   operator*() const { return (*array_pointer); }
                    pointer     operator->() const { return (array_pointer); }
                    
                    //it cmp
                    bool operator==(const iterator &x) const { return (array_pointer == x.array_pointer ? 1 : 0); }
                    bool operator!=(const iterator &x) const { return (array_pointer != x.array_pointer ? 1 : 0); }
                    bool operator<(const iterator &x) const { return (array_pointer < x.array_pointer ? 1 : 0); }
                    bool operator>(const iterator &x) const { return (array_pointer > x.array_pointer ? 1 : 0); }
                    bool operator>=(const iterator &x) const { return (array_pointer >= x.array_pointer ? 1 : 0); }
                    bool operator<=(const iterator &x) const { return (array_pointer <= x.array_pointer ? 1 : 0); }
                    //const_it cmp
                    bool operator==(const const_iterator &x) const { return (array_pointer == &*x ? 1 : 0); }
                    bool operator!=(const const_iterator &x) const { return (array_pointer != &*x ? 1 : 0); }
                    bool operator<(const const_iterator &x) const { return (array_pointer < &*x ? 1 : 0); }
                    bool operator>(const const_iterator &x) const { return (array_pointer > &*x ? 1 : 0); }
                    bool operator>=(const const_iterator &x) const { return (array_pointer >= &*x ? 1 : 0); }
                    bool operator<=(const const_iterator &x) const { return (array_pointer <= &*x ? 1 : 0); }

                    iterator &operator+=(int n){ array_pointer += n; return (*this); }
                    iterator &operator-=(int n){ array_pointer -= n; return (*this); }
                    iterator &operator++(){ array_pointer++; return (*this); }
                    iterator &operator--(){ array_pointer--; return (*this); }

                    iterator operator++(int n)
                    {
                        iterator    copy(*this);

                        (void)n;
                        ++array_pointer;
                        return (copy);
                    }
                    iterator operator--(int n)
                    {
                        iterator    copy(*this);
                        
                        (void)n; 
                        --array_pointer;
                        return (copy);
                    }

                    iterator operator+(int n) const
                    {
                        iterator x(*this);

                        x.array_pointer += n;
                        return (x);
                    }
                    iterator operator-(int n) const
                    {
                        iterator x(*this);

                        x.array_pointer -= n;
                        return (x);
                    }

            };

        public :
            class const_iterator
            {
                public : //const_iterator TYPEDEF
                    typedef typename iterator_traits<const T *>::iterator_category iterator_category;
                    typedef typename iterator_traits<const T *>::value_type value_type;
                    typedef typename iterator_traits<const T *>::difference_type difference_type;
                    typedef typename iterator_traits<const T *>::pointer pointer;
                    typedef typename iterator_traits<const T *>::reference reference;

                private :
                    pointer array_pointer;

                public :
                    //const_iterator CONSTRUCTOR
                    explicit const_iterator(){ array_pointer = NULL; }
                    explicit const_iterator(pointer array_pointer) : array_pointer(array_pointer){}
                    const_iterator(const const_iterator &x){ array_pointer = x.array_pointer; }
                    const_iterator(const iterator &x){ array_pointer = &*x; }
                    //const_iterator DESTRUCTOR
                    ~const_iterator(){}
                    //const_iterator OPERATOR
                    const_iterator &operator=(const const_iterator &x){ array_pointer = x.array_pointer; return (*this); }
                    const_iterator &operator=(const iterator &x){ array_pointer = &*x; return (*this); }

                    reference   operator[](unsigned int n) const { return (array_pointer[n]); }
                    reference   operator*() const { return (*array_pointer); }
                    pointer     operator->() const { return (array_pointer); }
                    
                    //it cmp
                    bool operator==(const const_iterator &x) const { return (array_pointer == x.array_pointer ? 1 : 0); }
                    bool operator!=(const const_iterator &x) const { return (array_pointer != x.array_pointer ? 1 : 0); }
                    bool operator<(const const_iterator &x) const { return (array_pointer < x.array_pointer ? 1 : 0); }
                    bool operator>(const const_iterator &x) const { return (array_pointer > x.array_pointer ? 1 : 0); }
                    bool operator>=(const const_iterator &x) const { return (array_pointer >= x.array_pointer ? 1 : 0); }
                    bool operator<=(const const_iterator &x) const { return (array_pointer <= x.array_pointer ? 1 : 0); }

                    const_iterator &operator+=(int n){ array_pointer += n; return (*this); } //retirer la ref sur tous ?
                    const_iterator &operator-=(int n){ array_pointer -= n; return (*this); }
                    const_iterator &operator++(){ array_pointer++; return (*this); }
                    const_iterator &operator--(){ array_pointer--; return (*this); }

                    const_iterator operator++(int n)
                    {
                        const_iterator    copy(*this);

                        (void)n;
                        ++array_pointer;
                        return (copy);
                    }
                    const_iterator operator--(int n)
                    {
                        const_iterator    copy(*this);
                        
                        (void)n; 
                        --array_pointer;
                        return (copy);
                    }

                    const_iterator operator+(int n) const
                    {
                        const_iterator x(*this);

                        x.array_pointer += n;
                        return (x);
                    }
                    const_iterator operator-(int n) const
                    {
                        const_iterator x(*this);

                        x.array_pointer -= n;
                        return (x);
                    }
            };

        public : //TYPEDEF
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            //typedef typename ft::vector<value_type, allocator_type>::iterator iterator;
            //typedef typename ft::vector<value_type, allocator_type>::const_iterator const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef typename iterator::difference_type difference_type;
            typedef size_t size_type;

        private : //PRIVATE VALUE
                allocator_type  alloc;
                value_type      *array;
                size_type       array_capacity;
                size_type       array_size;

        private : //PRIVATE FUNCTION
            size_t  more_capacity(size_t new_cap1 = 0)
            {
                size_type new_cap2 = array_capacity > 0 ? array_capacity * 2 : 1;

                return(new_cap1 > new_cap2 ? new_cap1 : new_cap2);
            }

        public : //FUNCTION
            //CONSTRUCTOR
            explicit vector(const allocator_type& alloc = allocator_type()) : alloc(alloc)
            {
                array = NULL;
                array_capacity = 0;
                array_size = 0;
            }
            explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : alloc(alloc)
            {
                array = (this->alloc).allocate(static_cast<size_type>(n));
                for (array_capacity = 0; array_capacity < n; array_capacity++)
                    (this->alloc).construct(&array[array_capacity], val);
                array_size = array_capacity;
            }

            template <class InputIterator, class = typename InputIterator::value_type>
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
            {
                InputIterator copy_first = first;
                size_t          i;

                this->alloc = alloc;
                for(array_capacity = 0; first != last; first++)
                    array_capacity++;
                array = (this->alloc).allocate(static_cast<size_t>(array_capacity));

                first = copy_first;
                for(i = 0; first != last; i++)
                    (this->alloc).construct(&array[i], *first++);
                array_size = array_capacity;
            }
            vector(const vector &x)
            {
                size_type i;

                (void)i;
                this->array_capacity = x.array_capacity;
                this->alloc = allocator_type();
                this->array_size = x.array_size;
                this->array = (this->alloc).allocate(static_cast<size_type>(array_capacity));
                for (i = 0; i < array_size; i++)
                    (this->alloc).construct(&array[i], x.array[i]);
            }
            //DESTRUCTOR
            ~vector(void)
            {
                clear();
                alloc.deallocate(array, array_capacity);
            }
            //OPERATOR
            vector &operator=(const vector &x) // SUREMENT PAS BON MUST PRESERVE ALLOCATION
            {
                size_type i;

                //this->~vector();
                clear(); //verif capacity
                alloc.deallocate(array, array_capacity);
                this->array_capacity = x.array_capacity;
                this->alloc = x.alloc;
                this->array = (this->alloc).allocate(static_cast<size_type>(array_capacity));
                for (i = 0; i < array_capacity; i++)
                    alloc.construct(&this->array[i], x.array[i]); //seems better than equal
                this->array_size = x.array_size;
                return (*this);
            } 
            //ARRAY ITERATOR
            iterator    begin()
            {
                return (iterator(array));
            }
            const_iterator begin() const
            {
                return (const_iterator(array));
            }

            iterator    end()
            {
                return (iterator(array + array_size));
            }
            const_iterator    end() const
            {
                return (iterator(array + array_size));
            }

            reverse_iterator    rbegin()
            {
                return (reverse_iterator(end()));
            }
            const_reverse_iterator    rbegin() const
            {
                return (const_reverse_iterator(end()));
            }

            reverse_iterator    rend()
            {
                return (reverse_iterator(begin()));
            }
            const_reverse_iterator    rend() const
            {
                return (const_reverse_iterator(begin()));
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
            void    resize(size_type n, value_type val = value_type()) //VERIFY ABSOLUTLY
            {
                if (n > array_capacity) //exception check_inside reserve
                {
                    reserve(n);
                }
                if (n > array_size)
                {
                    while (array_size < n)
                        push_back(val);
                }
                else if (n < array_size)
                {
                    while (array_size > n)
                        alloc.destroy(&array[--array_size]);
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
            void reserve(size_type n)
            {
                value_type  *new_array;
                size_type      i;

                if (n > max_size())
                {
                    throw std::length_error("vector::reserve"); //je ne sais pas qu'elle txt mettre
                }

                if (n > array_capacity)
                {
                    new_array = alloc.allocate(static_cast<size_type>(n));
                    for (i = 0; i < array_size; i++)
                        alloc.construct(&new_array[i], array[i]); // = seem not good
                    for (i = 0; i < array_size; i++)
                        alloc.destroy(&array[i]);
                    alloc.deallocate(array, array_capacity);
                    array_capacity = n;
                    array = new_array;
                }
                    
            }
            //ELEMENT ACCESS
            reference   operator[](size_type n)
            {
                return(array[n]);
            }
            reference at(size_type n)
            {
                if (n >= array_size)
                {
                    std::stringstream ss;
                    ss << "ft::vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is "
                    << array_size << ")";
                    throw std::out_of_range(ss.str());
                    //vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)
                }
                return (array[n]);
            }
            const_reference at(size_type n) const
            {
                if (n >= array_size)
                {
                    throw std::out_of_range("std::vector"); //texte a verifier
                    //vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)
                }
                return (array[n]);
            }

            reference front()
            {
                return(*array);
            }
            const_reference front() const
            {
                return(*array);
            }

            reference back()
            {
                return(array[array_size - 1]);
            }
            const_reference back() const
            {
                return(array[array_size - 1]);
            }

            //ARRAY MODIFIERS
            void    assign(size_type n, const value_type &val) //a refaire
            {
                if (n > array_capacity) //exception ? 
                    reserve(n);
                clear();
                while (array_size < n)
                {
                    alloc.construct(&array[array_size], val);
                    ++array_size;
                }
            }
            template <class InputIterator, class = typename InputIterator::value_type>
            void    assign(InputIterator first, InputIterator last) //a refaire
            {
                size_t          range_it = &*last - &*first;

                if (range_it > array_capacity) //not good exception
                    reserve(range_it);
                clear();
                while (array_size < range_it)
                {
                    alloc.construct(&array[array_size], *first++);
                    ++array_size;
                }
            }

            void    push_back(const value_type &val) //that seems ok
            {
                size_type i; 
                size_type n;
                value_type  *new_array;

                if (array_size >= array_capacity)
                {
                    n = more_capacity();
                    new_array = alloc.allocate(static_cast<size_type>(n));
                    for (i = 0; i < array_size; i++)
                        alloc.construct(&new_array[i], array[i]); //seems better than equal
                    for (i = 0; i < array_size; i++)
                        (this->alloc).destroy(&array[i]);
                    (this->alloc).deallocate(array, array_capacity);
                    array_capacity = n;
                    array = new_array;
                }
                alloc.construct(array + array_size, val);
                ++array_size;
            }
            void    pop_back()
            {
                if (array_capacity > 0)
                    alloc.destroy(&array[--array_size]);
            }

            iterator    insert(iterator position, const value_type &val)
            {
                iterator    it;
                size_t      new_capacity;
                size_t      pos_nb = &*position - &*begin();
                size_t      i;
                value_type  *new_array;

                if (array_size == array_capacity)
                {
                    it = begin();
                    new_capacity = more_capacity();
                    new_array = alloc.allocate(static_cast<size_type>(new_capacity));
                    array_size = array_size + 1;
                    for(i = 0; i < array_size; i++)
                    {
                        if (it == position)
                        {
                            alloc.construct(&new_array[i], val); //verifier si c'est pas la fin
                            if (i + 1 < array_size)
                                alloc.construct(&new_array[++i], *it++);
                        }
                        else
                            alloc.construct(&new_array[i], *it++);
                    }
                    clear();
                    array = new_array;
                    array_size = i;
                    array_capacity = new_capacity;
                    return (this->begin() + pos_nb );
                }
                alloc.construct(&array[array_size], val);
                array_size++;
                it  = this->end();
                while (position < --it)
                    *it = *(it - 1); //*it ; --it;
                *it = val;
                return (position); //a verifier;   
            }
            void    insert(iterator position, size_type n, const value_type &val) //verif = to replace alloc.construct
            {
                size_type new_capacity;
                size_type i;
                iterator beg(array);
                iterator end(this->end());
                value_type  *new_array;

                if (array_size + n > array_capacity)
                {
                    new_capacity = more_capacity(array_size + n);
                    new_array = alloc.allocate(static_cast<size_type>(new_capacity));
                    
                    for(i = 0; beg != position; i++) //verif i < array_size
                        alloc.construct(&new_array[i], *beg++);

                    while (n-- > 0)
                        alloc.construct(&new_array[i++], val);

                    while (beg != end) //verif i < array_size
                        alloc.construct(&new_array[i++], *beg++);
                    clear();
                    array_capacity = new_capacity;
                    array_size = i;
                    array = new_array;
                }
                else
                {
                    for (i = 0; i < n; i++)
                        alloc.construct(&array[array_size++], val);
                    if (i > 0)
                    {
                        end = this->end();
                        position += n;
                        while (position < end)
                            *--end = *(end - n - 1);
                    }
                    for (i = 0; i < n; i++)
                        *--end = val;
                }
            }
            template <class InputIterator, class = typename InputIterator::value_type>
            void    insert(iterator position, InputIterator first, InputIterator last)
            {
                size_type new_capacity;
                size_type i;
                size_type it_diff = last - first;
                iterator beg(array);
                iterator end(this->end);
                value_type  *new_array;
                
                if (array_size + it_diff >= array_capacity)
                {
                    new_capacity = more_capacity(array_size + it_diff);
                    new_array = alloc.allocate(static_cast<size_type>(new_capacity));
                    
                    for(i = 0; beg != position; i++) //verif i < array_size
                        alloc.construct(&new_array[i], *beg++);

                    while (first != last)
                        alloc.construct(&new_array[i++], *first++);

                    while (beg != end)
                        alloc.construct(&new_array[i++], *beg++);
                    clear();
                    array_capacity = new_capacity;
                    array_size = array_capacity();
                    array = new_array;
                }
                else
                {
                    for (i = 0; i < it_diff ; i++)
                       alloc.construct(&array[array_size + i], *(position + i));

                    for(i = 0; i < it_diff; i++)
                    {
                        *(position + i) = first++;
                    }
                    array_size += it_diff;
                }
            }

            iterator   erase(iterator position) //possible segfault
            {
                iterator replace(position);
                iterator end(this->end());

                while (position + 1 != end)
                    *position++ = *(position + 1);
                alloc.destroy(&*position);
                --array_size;
                return (replace);
            }
            iterator   erase(iterator first, iterator last) //dont know how they didn't seg
            {
                iterator return_it(first);
                iterator end(this->end());
                size_t   it_diff = &*last - &*first;

                while (last < end)
                {
                    *first++ = *last++;
                }
                while (first < end)
                {
                    alloc.destroy(&*(++first));
                    array_size--;
                }
                return (return_it);
            }
            void swap(vector &x)
            {
                T   *save;
                size_type save_size;
                size_type save_capacity;

                save = x.array;
                save_size = x.array_size;
                save_capacity = x.array_capacity;

                x.array = this->array;
                x.array_size = this->array_size;
                x.array_capacity = this->array_capacity;

                this->array = save;
                this->array_size = save_size;
                this->array_capacity = save_capacity;
            }

            void    clear()
            {
                size_type   n;

                for(n = 0; n < array_size; n++)
                    alloc.destroy(&array[n]);
                array_size = 0;
            }
    };
    template <class T, class Alloc>
    void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
    {
        x.swap(y);
    }
};

#endif