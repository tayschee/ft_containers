#ifndef LIST_HPP
# define LIST_HPP

# include <memory> //std::allocator<T>
# include <stdexcept> //exception
# include "iterator.hpp"
# include <iostream> 

namespace   ft
{   
    template <typename T, class Alloc = std::allocator<T> >
    class   list
    {
        private : //NODE
            struct  node
            {
                T           value;
                struct node *next;
                struct node *prev;
            };

        public :
            class const_iterator;
            class iterator
            {
                public : //iterator TYPEDEF
                    typedef typename iterator_traits<T *>::iterator_category iterator_category; //a changer probablement
                    typedef typename iterator_traits<T *>::value_type value_type;
                    typedef typename iterator_traits<T *>::difference_type difference_type;
                    typedef typename iterator_traits<T *>::pointer pointer;
                    typedef typename iterator_traits<T *>::reference reference;
                private :
                    node    *array_pointer;
                public :
                    //iterator CONSTRUCTOR
                    explicit iterator(){ array_pointer = NULL; } //peut etre pas NULL
                    explicit iterator(node *array_pointer) : array_pointer(array_pointer){}
                    iterator(const iterator &x){ array_pointer = x.array_pointer; }
                    //iterator DESTRUCTOR
                    ~iterator(){}
                    //iterator OPERATOR
                    iterator &operator=(const iterator &x){ array_pointer = x.array_pointer; return (*this); }

                    reference   operator*() const { return (array_pointer->value); }
                    pointer     operator->() const { return (&array_pointer->value); } //a verifer
                    
                    //it cmp
                    bool operator==(const iterator &x) const { return (array_pointer == x.array_pointer ? 1 : 0); }
                    bool operator!=(const iterator &x) const { return (array_pointer != x.array_pointer ? 1 : 0); }
                    bool operator==(const const_iterator &x) const { return (array_pointer == reinterpret_cast<const node *>(&*x) ? 1 : 0); }
                    bool operator!=(const const_iterator &x) const { return (array_pointer != reinterpret_cast<const node *>(&*x) ? 1 : 0); }

                    iterator &operator++(){ array_pointer = array_pointer->next; return (*this); }
                    iterator &operator--(){ array_pointer = array_pointer->prev; return (*this); }

                    iterator operator++(int n)
                    {
                        iterator    copy(*this);

                        (void)n;
                        array_pointer = array_pointer->next;
                        return (copy);
                    }
                    iterator operator--(int n)
                    {
                        iterator    copy(*this);
                        
                        (void)n; 
                        array_pointer = array_pointer->prev;
                        return (copy);
                    }
            };
            class const_iterator
            {
                public : //iterator TYPEDEF
                    typedef typename iterator_traits<const T *>::iterator_category iterator_category; //a changer probablement
                    typedef typename iterator_traits<const T *>::value_type value_type;
                    typedef typename iterator_traits<const T *>::difference_type difference_type;
                    typedef typename iterator_traits<const T *>::pointer pointer;
                    typedef typename iterator_traits<const T *>::reference reference;
                private :
                    node    *array_pointer;
                public :
                    //const_iterator CONSTRUCTOR
                    explicit const_iterator(){ array_pointer = NULL; } //peut etre pas NULL
                    explicit const_iterator(node *array_pointer) : array_pointer(array_pointer){}
                    const_iterator(const iterator &x){ array_pointer = reinterpret_cast<node *>(&*x); }
                    const_iterator(const const_iterator &x){ array_pointer = x.array_pointer; }
                    //const_iterator DESTRUCTOR
                    ~const_iterator(){}
                    //const_iterator OPERATOR
                    const_iterator &operator=(const const_iterator &x){ array_pointer = x.array_pointer; return (*this); }
                    const_iterator &operator=(const iterator &x){ array_pointer = reinterpret_cast<node *>(&*x); return (*this); }

                    reference   operator*() const { return (array_pointer->value); }
                    pointer     operator->() const { return (&array_pointer->value); } //a verifer
                    
                    //it cmp
                    bool operator==(const const_iterator &x) const { return (array_pointer == x.array_pointer ? 1 : 0); }
                    bool operator!=(const const_iterator &x) const { return (array_pointer != x.array_pointer ? 1 : 0); }

                    const_iterator &operator++(){ array_pointer = array_pointer->next; return (*this); }
                    const_iterator &operator--(){ array_pointer = array_pointer->prev; return (*this); }

                    const_iterator operator++(int n)
                    {
                        const_iterator    copy(*this);

                        (void)n;
                        array_pointer = array_pointer->next;
                        return (copy);
                    }
                    const_iterator operator--(int n)
                    {
                        const_iterator    copy(*this);
                        
                        (void)n; 
                        array_pointer = array_pointer->prev;
                        return (copy);
                    }
            };

        public : //TYPEDEF
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            //typedef typename ft::list<value_type, allocator_type>::iterator iterator;
            //typedef typename ft::list<const value_type, allocator_type>::iterator const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef typename iterator::difference_type difference_type;
            typedef size_t size_type;
        
        public: //PRIVATE VALUE
            allocator_type          value_alloc;
            std::allocator<node>    node_alloc;
            node                    *dummy_node;
            size_type               node_size;

        private :

        public: //FUNCTION
            //CONSTRUCTOR DESTRUCTOR
            explicit list(const allocator_type alloc = allocator_type()) : value_alloc(alloc)
            {
                dummy_node = node_alloc.allocate(1);
                value_alloc.construct(&dummy_node->value, value_type());
                dummy_node->next = dummy_node;
                dummy_node->prev = dummy_node;

                node_size = 0;
            }
            explicit list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
            : value_alloc(alloc)
            {
                dummy_node = node_alloc.allocate(1);
                value_alloc.construct(&dummy_node->value, value_type());
                dummy_node->next = dummy_node;
                dummy_node->prev = dummy_node;
                node_size = 0;

                assign(n, val);
            }
            template <class InputIterator>/*, class = typename InputIterator::value_type*/
            list(InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last,
            const allocator_type &alloc = allocator_type()) : value_alloc(alloc)
            {
                dummy_node = node_alloc.allocate(1);
                value_alloc.construct(&dummy_node->value, value_type());
                dummy_node->next = dummy_node;
                dummy_node->prev = dummy_node;
                node_size = 0;

                assign(first, last);
            }
            list(const list &x) : value_alloc(x.value_alloc)
            {
                dummy_node = node_alloc.allocate(1);
                value_alloc.construct(&dummy_node->value, value_type());
                dummy_node->next = dummy_node;
                dummy_node->prev = dummy_node;
                node_size = 0;

                assign(x.begin(), x.end());
            }
            list    &operator=(const list &x)
            {
                assign(x.begin(), x.end());
                this->value_alloc = x.value_alloc;
                this->node_alloc = x.node_alloc;
                return (*this);
            }
            ~list()
            {
                clear();
                node_alloc.deallocate(dummy_node, 1);
            }
            // LIST ITERATORS
            iterator    begin()
            {
                return (iterator(dummy_node->next));
            }

            const_iterator    begin() const
            {
                return (const_iterator(dummy_node->next));
            }

            iterator    end()
            {
                return (iterator(dummy_node));
            }

            const_iterator    end() const
            {
                return (const_iterator(dummy_node));
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
            //CAPACITY
            size_type   size() const
            {
                return (node_size);
            }

            bool        empty() const
            {
                return (node_size ? 0 : 1);
            }

            size_type   max_size() const
            {
                return (node_alloc.max_size());
            }

            reference   front()
            {
                return (dummy_node->next->value);
            }
            const_reference   front() const
            {
                return (dummy_node->next->value);
            }

            reference   back()
            {
                return(dummy_node->prev->value);
            }
            const_reference   back() const
            {
                return(dummy_node->prev->value);
            }

            //MODIFIER LIST
            template <class InputIterator>
            void        assign(InputIterator first,typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
            {
                size_type   i = 0;
                node        *change_node = dummy_node;

                for(i = 0; first != last && i < node_size; i++)
                {
                    change_node = change_node->next;
                    value_alloc.construct(&change_node->value, *first++);
                }
                while (i < node_size)
                    pop_back();
                while (first != last)
                {
                    push_back(*first);
                    ++first;
                }
            }
            void        assign(size_type n, const value_type &val)
            {
                size_type i;
                node        *change_node = dummy_node;

                for(i = 0; i < n && i < node_size; i++)
                {
                    change_node = change_node->next;
                    change_node->value = val; //alloc dont needed
                }
                while (i < node_size)
                    pop_back();
                while (i < n)
                {
                    push_back(val);
                    i++;
                }
            }

            void        push_back(const value_type &val)
            {
                node     *new_node;


                new_node = node_alloc.allocate(1);

                value_alloc.construct(&new_node->value, val);
                new_node->next = dummy_node;
                new_node->prev = dummy_node->prev;

                dummy_node->prev->next = new_node;
                dummy_node->prev = new_node;
                
                ++node_size;
            }
            void        pop_back()
            {
                node    *node_to_join;

                node_to_join = dummy_node->prev->prev;
                node_alloc.deallocate(dummy_node->prev, 1);
                node_to_join->next = dummy_node;
                dummy_node->prev = node_to_join;
                --node_size;
            }

            void        push_front(const value_type &val)
            {
                node     *new_node;

                new_node = node_alloc.allocate(1);
                value_alloc.construct(&new_node->value, val);
                new_node->prev = dummy_node;
                new_node->next = dummy_node->next;

                dummy_node->next->prev = new_node;
                dummy_node->next = new_node;
                ++node_size;
                
            }
            void        pop_front()
            {
                node    *node_to_join;

                node_to_join = dummy_node->next->next;
                node_alloc.deallocate(dummy_node->next, 1);
                node_to_join->prev = dummy_node;
                dummy_node->next = node_to_join;
                --node_size;
            }

            iterator    insert(iterator position, const value_type &val)
            {
                node        *new_node;
                node        *node_after_new = reinterpret_cast<node *>(&*position);

                new_node = node_alloc.allocate(1);
                value_alloc.construct(&new_node->value, val);
                new_node->next = node_after_new;
                new_node->prev = node_after_new->prev;

                node_after_new->prev->next = new_node;
                node_after_new->prev = new_node;
                ++node_size;

                return (--position);
            }
            void    insert(iterator position, size_type n, const value_type &val)
            {
                while (n > 0)
                {
                    --n;
                    insert(position, val);
                }
            }
            template <class InputIterator>
            void    insert(iterator position, InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
            {
                while (first != last)
                {
                   insert(position, *first++);
                }
            }

            iterator    erase(iterator position)
            {
                node        *erase_elem = reinterpret_cast<node *>(&*position);

                ++position;
                erase_elem->prev->next = erase_elem->next;
                erase_elem->next->prev = erase_elem->prev;
                node_alloc.deallocate(erase_elem, 1);
                --node_size;

                return (position);
            }
            iterator    erase(iterator first, iterator last)
            {
                node        *elem_to_connect_1 = reinterpret_cast<node *>(&*(first));
                node        *elem_to_connect_2 = reinterpret_cast<node *>(&*last);

                elem_to_connect_1 = elem_to_connect_1->prev;
                while (first != last)
                {
                    node_alloc.deallocate(reinterpret_cast<node *>(&*first++), 1);
                    --node_size;
                }
                elem_to_connect_1->next = elem_to_connect_2;
                elem_to_connect_2->prev = elem_to_connect_1;

                return(last);
            }
            void        swap(list &x)
            {
                node    *tmp_node = x.dummy_node;
                size_type tmp_size = x.node_size;

                x.node_size = this->node_size;
                x.dummy_node = this->dummy_node;

                this->node_size = tmp_size;
                this->dummy_node = tmp_node;
            }

            void        resize(size_type n, value_type val = value_type())
            {
                while(n > node_size)
                    push_back(val);
                while (n < node_size)
                    pop_back();
            }

            void        clear()
            { 
                while (node_size > 0)
                {
                    pop_back();
                }
                dummy_node->next = dummy_node;
                dummy_node->prev = dummy_node;
            }

            void splice(iterator position, list &x)
            {
                node        *beg_x = reinterpret_cast<node *>(&*(x.begin()));
                node        *beg_this = reinterpret_cast<node *>(&*(position));
                node        *end_x = reinterpret_cast<node *>(&*x.end());

                beg_this->prev->next = beg_x;
                beg_x->prev = beg_this->prev;

                beg_this->prev = end_x->prev;
                end_x->prev->next = beg_this;

                end_x->next = end_x;
                end_x->prev = end_x;

                this->node_size += x.node_size;
                x.node_size = 0;
            }
            void splice(iterator position, list &x, iterator i)
            {
                node        *beg_x = reinterpret_cast<node *>(&*(i));
                node        *beg_this = reinterpret_cast<node *>(&*(position));

                beg_x->next->prev = beg_x->prev;
                beg_x->prev->next = beg_x->next;

                beg_x->next = beg_this;
                beg_x->prev = beg_this->prev;

                beg_this->prev->next = beg_x;
                beg_this->prev = beg_x;

                ++this->node_size;
                --x.node_size;
            }
            void splice(iterator position, list &x, iterator first, iterator last)
            {
                while (first != last)
                    splice(position, x, first++);
            }

            void remove(const value_type &val)
            {
                iterator    it(begin());
                iterator    last(end());

                while (it != last)
                {
                    if (*it == val)
                        erase(it);
                    ++it;
                }
            }

            template <class Predicate>
            void remove_if (Predicate pred)
            {
                iterator    it(begin());
                iterator    last(end());

                while (it != last)
                {
                    if (pred(*it))
                        erase(it);
                    ++it;
                }
            }

            void unique()
            {
                iterator    it(begin());
                iterator    itp1(++begin());
                iterator    last(end());

                while (itp1 != last)
                {
                    if (*it == *itp1)
                    {
                        erase(itp1);
                        itp1++ = it;
                    }
                    else
                    {
                        ++it;
                        ++itp1;
                    }
                }
            }
            template <class BinaryPredicate>
            void unique(BinaryPredicate binary_pred)
            {
                iterator    it(begin());
                iterator    itp1(++begin());
                iterator    last(end());

                while (itp1 != last)
                {
                    if (binary_pred(*itp1, *it))
                    {
                        erase(itp1);
                        itp1++ = it;
                    }
                    else
                    {
                        ++it;
                        ++itp1;
                    }
                }
            }

            void merge (list& x)
            {
                iterator    it(this->begin());
                iterator    beg_x(x.begin());
                iterator    last(this->end());

                while (it != last)
                {
                    if (x.size() && *beg_x < *it)
                    {
                        this->splice(it, x, beg_x);
                        beg_x = x.begin();
                    }
                    else
                        ++it;
                }
                if (x.size())
                    this->splice(it, x, beg_x, x.end());
            }
            template <class Compare>
            void merge (list& x, Compare comp)//je comprend pas
            {
                iterator    it(begin());
                iterator    beg_x(x.begin());
                iterator    last(end());

                while (it != last)
                {
                    if (x.size() && comp(*beg_x, *it))
                    {
                        this->splice(it, x, beg_x);
                        beg_x = x.begin();
                    }
                    else
                        ++it;
                }
                if (x.size())
                    this->splice(it, x, beg_x, x.end());
            }

            void sort()
            {
                iterator    it(begin());
                iterator    itp1(++begin());
                iterator    last(end());

                while (itp1 != last)
                {
                    if (*itp1 < *it)
                    {
                        splice(it, *this, itp1);
                        itp1 = begin();
                        it = itp1;
                    }
                    else
                        ++it;
                    ++itp1;
                }
            }

            template <class Compare>
            void sort (Compare comp)
            {
                iterator    it(begin());
                iterator    itp1(++begin());
                iterator    last(end());

                while (itp1 != last)
                {
                    if (comp(*itp1, *it))
                    {
                        splice(it, *this, itp1);
                        itp1 = begin();
                        it = itp1;
                    }
                    else
                        ++it;
                    ++itp1;
                }
            }

            void reverse()
            {
                iterator it(end());
                iterator last(end());
                node *nd;
                node *tmp;

                do
                {
                    nd = reinterpret_cast<node *>(&*it);
                    tmp = nd->prev;
                    nd->prev = nd->next;
                    nd->next = tmp;
                    ++it;
                }
                while (it != last);
            }

            //RELATIONAL OPERATOR
            bool operator==(const list& rhs) const
            {
                const_iterator it_this(begin());
                const_iterator last(end());
                const_iterator it_rhs(rhs.begin());

                if (this->node_size != rhs.node_size)
                    return (0);
                while(it_this != last)
                {
                    if (*it_this++ != *it_rhs++)
                        return (0);
                }
                return (1);
            }
            bool operator!=(const list& rhs) const
            {
                const_iterator it_this(this->begin());
                const_iterator last(end());
                const_iterator it_rhs(rhs.begin());

                if (this->node_size != rhs.node_size)
                    return (1);
                while(it_this != last)
                {
                    if (*it_this++ != *it_rhs++)
                        return (1);
                }
                return (0);
            }
            bool operator<(const list& rhs) const
            {
                const_iterator it_this(this->begin());
                const_iterator last(end());
                const_iterator it_rhs(rhs.begin());
                const_iterator last_rhs(rhs.end());

                while(it_this != last && it_rhs != last_rhs)
                {
                    if (*it_this < *it_rhs)
                        return (1);
                    else if (*it_rhs++ < *it_this++)
                        return (0);
                }
                return (this->size() < rhs.size());
            }
            bool operator>(const list& rhs) const
            {
                const_iterator it_this(this->begin());
                const_iterator last(end());
                const_iterator it_rhs(rhs.begin());
                const_iterator last_rhs(rhs.end());

                while(it_this != last && it_rhs != last_rhs)
                {
                    if (*it_this > *it_rhs)
                        return (1);
                    else if (*it_rhs++ > *it_this++)
                        return (0);
                }
                return (this->size() > rhs.size());
            }
            bool operator>=(const list& rhs) const
            {
                const_iterator it_this(this->begin());
                const_iterator last(end());
                const_iterator it_rhs(rhs.begin());
                const_iterator last_rhs(rhs.end());

                while(it_this != last && it_rhs != last_rhs)
                {
                    if (*it_this > *it_rhs)
                        return (1);
                    else if (*it_rhs++ > *it_this++)
                        return (0);
                }
                return (this->size() >= rhs.size());
            }
            bool operator<=(const list& rhs) const
            {
                const_iterator it_this(this->begin());
                const_iterator last(end());
                const_iterator it_rhs(rhs.begin());
                const_iterator last_rhs(rhs.end());

                while(it_this != last && it_rhs != last_rhs)
                {
                    if (*it_this < *it_rhs)
                        return (1);
                    else if (*it_rhs++ < *it_this++)
                        return (0);
                }
                return (this->size() <= rhs.size());
            }
    };
    
    template <class T, class Alloc>
    void    swap(ft::list<T, Alloc> &x, ft::list<T, Alloc> &y)
    {
        x.swap(y);
    }
};

#endif