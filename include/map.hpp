#ifndef MAP_HPP
# define MAP_HPP

# include <memory> //std::allocator<T>
# include <stdexcept> //exception
# include <utility> //pair
# include "iterator.hpp"
# include <iostream> 
# include <functional> //less

namespace   ft
{   
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
    class   map
    {
        private :
            struct btree
            {
                ft::pair<const Key, T> *pair;
                Compare                 *cmp;
                btree                     *greater;
                btree                     *lower;
                btree                     *prev;
            };
        /*public :
            class const_iterator;
            class iterator
            {
                public : //iterator TYPEDEF
                    typedef typename ft::iterator_traits<T *>::iterator_category iterator_category; //a changer probablement
                    typedef typename ft::iterator_traits<T *>::value_type value_type;
                    typedef typename ft::iterator_traits<T *>::difference_type difference_type;
                    typedef typename ft::iterator_traits<T *>::pointer pointer;
                    typedef typename ft::iterator_traits<T *>::reference reference;
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
                    typedef typename ft::iterator_traits<const T *>::iterator_category iterator_category; //a changer probablement
                    typedef typename ft::iterator_traits<const T *>::value_type value_type;
                    typedef typename ft::iterator_traits<const T *>::difference_type difference_type;
                    typedef typename ft::iterator_traits<const T *>::pointer pointer;
                    typedef typename ft::iterator_traits<const T *>::reference reference;
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
            };*/

        public : //TYPEDEF
            typedef Key key_type;
            typedef T mapped_type;
            typedef ft::pair<const key_type, mapped_type> value_type;
            typedef Compare key_compare;
            //typedef value_comp value_compare //pas encore bien compris
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            //typedef typename ft::map<value_type, allocator_type>::iterator iterator;
            //typedef typename ft::map<const value_type, allocator_type>::iterator const_iterator;
            //typedef ft::reverse_iterator<iterator> reverse_iterator;
            //typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            //typedef typename iterator::difference_type difference_type;
            typedef size_t size_type;
        
        public: //PRIVATE VALUE
            allocator_type          alloc;
            std::allocator<btree>   tree_alloc;
            key_compare             cmp;
            btree                   *tree;
            size_type               map_size;

        private :
            btree    *create_elem(const value_type &val)
            {
                btree                   *new_elem;
                new_elem = tree_alloc.allocate(1);
                alloc.construct(&new_elem->pair, val);
                cmp = key_compare();
                btree                     *greater;
                btree                     *lower;
                btree                     *prev;

            }

        public: //FUNCTION
            //CONSTRUCTOR DESTRUCTOR
            explicit map(const key_compare& comp = key_compare(), const allocator_type alloc = allocator_type())
            : alloc(alloc), cmp(comp)
            {
                //tree_alloc = std::allocator<bst>();
                map_size = 0;
            }
            /*map(InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last,
            const allocator_type &alloc = allocator_type()) : value_alloc(alloc)
            {
                dummy_node = node_alloc.allocate(1);
                value_alloc.construct(&dummy_node->value, value_type());
                dummy_node->next = dummy_node;
                dummy_node->prev = dummy_node;
                node_size = 0;

                assign(first, last);
            }
            map(const map &x) : value_alloc(x.value_alloc)
            {
                dummy_node = node_alloc.allocate(1);
                value_alloc.construct(&dummy_node->value, value_type());
                dummy_node->next = dummy_node;
                dummy_node->prev = dummy_node;
                node_size = 0;

                assign(x.begin(), x.end());
            }
            map    &operator=(const map &x)
            {
                assign(x.begin(), x.end());
                this->value_alloc = x.value_alloc;
                this->node_alloc = x.node_alloc;
                return (*this);
            }*/
            ~map()
            {
                /*clear();
                node_alloc.deallocate(dummy_node, 1);*/
            }
            // map ITERATORS
            /*iterator    begin()
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
            }*/
            //CAPACITY
            size_type   size() const
            {
                return (map_size);
            }

            bool        empty() const
            {
                return (map_size);
            }

            size_type   max_size() const
            {
                return (tree_alloc.max_size());
            }

            /*//MODIFIER map
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
            void        swap(map &x)
            {
                node    *tmp_node = x.dummy_node;
                size_type tmp_size = x.node_size;

                x.node_size = this->node_size;
                x.dummy_node = this->dummy_node;

                this->node_size = tmp_size;
                this->dummy_node = tmp_node;
            }

            void        clear()
            { 
                while (node_size > 0)
                {
                    pop_back();
                }
                dummy_node->next = dummy_node;
                dummy_node->prev = dummy_node;
            }*/
    };
};

#endif