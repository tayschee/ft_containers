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
                ft::pair<const Key, T>       pair;
                bool                         upper_flag;
                bool                         lower_flag;
                btree                       *upper;
                btree                       *lower;
                bool                        red_black; //useless
            };

        public :
            class const_iterator;
            class iterator
            {
                public : //iterator TYPEDEF
                    typedef typename ft::iterator_traits<ft::pair<const Key, T> *>::iterator_category iterator_category; //a changer probablement
                    typedef typename ft::iterator_traits<ft::pair<const Key, T> *>::value_type value_type;
                    typedef typename ft::iterator_traits<ft::pair<const Key, T> *>::difference_type difference_type;
                    typedef typename ft::iterator_traits<ft::pair<const Key, T> *>::pointer pointer;
                    typedef typename ft::iterator_traits<ft::pair<const Key, T> *>::reference reference;
                private :
                    btree    *array_pointer;
                public :
                    //iterator CONSTRUCTOR
                    explicit iterator() : array_pointer(NULL) {} //peut etre pas NULL
                    explicit iterator(btree *array_pointer) : array_pointer(array_pointer) {}
                    iterator(const iterator &x): array_pointer(x.array_pointer){}
                    //iterator DESTRUCTOR
                    ~iterator(){}
                    //iterator OPERATOR
                    iterator &operator=(const iterator &x){ array_pointer = x.array_pointer; return (*this); }

                    reference   operator*() const { return (array_pointer->pair); }
                    pointer     operator->() const { return (&array_pointer->pair); } //a verifer
                    
                    //it cmp
                    bool operator==(const iterator &x) const { return (array_pointer == x.array_pointer ? 1 : 0); }
                    bool operator!=(const iterator &x) const { return (array_pointer != x.array_pointer ? 1 : 0); }
                    bool operator==(const const_iterator &x) const { return (array_pointer == reinterpret_cast<const btree *>(&*x) ? 1 : 0); }
                    bool operator!=(const const_iterator &x) const { return (array_pointer != reinterpret_cast<const btree *>(&*x) ? 1 : 0); }

                    iterator &operator++()
                    {
                        bool flag;

                        flag = array_pointer->upper_flag;
                        array_pointer = array_pointer->upper;

                        while (flag == 1 && array_pointer->lower_flag)
                        {
                            array_pointer = array_pointer->lower;
                        }

                        return (*this);
                    }
                    iterator &operator--()
                    {
                        bool flag;

                        flag = array_pointer->lower_flag;
                        array_pointer = array_pointer->lower;

                        while (flag == 1 && array_pointer->upper_flag)
                        {
                            array_pointer = array_pointer->upper;
                        }
                        return (*this);
                    }

                    iterator operator++(int n)
                    {
                        iterator    copy(*this);

                        (void)n;
                        this->operator++();
                        return (copy);
                    }
                    iterator operator--(int n)
                    {
                        iterator    copy(*this);
                        
                        (void)n; 
                        this->operator--();
                        return (copy);
                    }
            };
            class const_iterator
            {
                public : //iterator TYPEDEF
                    typedef typename ft::iterator_traits<const ft::pair<const Key, T> *>::iterator_category iterator_category; //a changer probablement
                    typedef typename ft::iterator_traits<const ft::pair<const Key, T> *>::value_type value_type;
                    typedef typename ft::iterator_traits<const ft::pair<const Key, T> *>::difference_type difference_type;
                    typedef typename ft::iterator_traits<const ft::pair<const Key, T> *>::pointer pointer;
                    typedef typename ft::iterator_traits<const ft::pair<const Key, T> *>::reference reference;
                private :
                    btree    *array_pointer;
                public :
                    //const_iterator CONSTRUCTOR
                    explicit const_iterator(){ array_pointer = NULL; } //peut etre pas NULL
                    explicit const_iterator(btree *array_pointer) : array_pointer(array_pointer){}
                    const_iterator(const iterator &x){ array_pointer = reinterpret_cast<btree *>(&*x); }
                    const_iterator(const const_iterator &x){ array_pointer = x.array_pointer; }
                    //const_iterator DESTRUCTOR
                    ~const_iterator(){}
                    //const_iterator OPERATOR
                    const_iterator &operator=(const const_iterator &x){ array_pointer = x.array_pointer; return (*this); }
                    const_iterator &operator=(const iterator &x){ array_pointer = reinterpret_cast<btree *>(&*x); return (*this); }

                    reference   operator*() const { return (array_pointer->pair); }
                    pointer     operator->() const { return (&array_pointer->pair); } //a verifer
                    
                    //it cmp
                    bool operator==(const const_iterator &x) const { return (array_pointer == x.array_pointer ? 1 : 0); }
                    bool operator!=(const const_iterator &x) const { return (array_pointer != x.array_pointer ? 1 : 0); }

                    const_iterator &operator++()
                    {
                        bool flag;

                        flag = array_pointer->upper_flag;
                        array_pointer = array_pointer->upper;

                        while (flag == 1 && array_pointer->lower_flag)
                        {
                            array_pointer = array_pointer->lower;
                        }

                        return (*this);
                    }
                    const_iterator &operator--()
                    {
                        bool flag;

                        flag = array_pointer->lower_flag;
                        array_pointer = array_pointer->lower;

                        while (flag == 1 && array_pointer->upper_flag)
                        {
                            array_pointer = array_pointer->upper;
                        }
                        return (*this);
                    }

                    const_iterator operator++(int n)
                    {
                        const_iterator    copy(*this);

                        (void)n;
                        this->operator++();
                        return (copy);
                    }
                    const_iterator operator--(int n)
                    {
                        const_iterator    copy(*this);
                        
                        (void)n; 
                        this->operator--();
                        return (copy);
                    }
            };
        public : //TYPEDEF
            typedef Key key_type;
            typedef T mapped_type;
            typedef ft::pair<const key_type, mapped_type> value_type;
            typedef Compare key_compare;
            //typedef value_comp value_compare
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            //typedef typename ft::map<value_type, allocator_type>::iterator iterator;
            //typedef typename ft::map<const value_type, allocator_type>::iterator const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef typename iterator::difference_type difference_type;
            typedef size_t size_type;

        public : //VALUE_COMPARE
            class value_compare //probably some change to do
            {
                protected : //variable
                    Compare cmp;
                
                protected : //func
                    value_compare (Compare c) : cmp(c) {}

                public:
                    value_compare () : cmp(Compare()) {}
                    value_compare (const value_compare &c) : cmp(c.cmp) {}
                    value_compare &operator=(const value_compare &c) { cmp = c.cmp; return (*this); }
                    typedef bool result_type;\
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;
                    bool operator() (const value_type &x, const value_type &y)
                    {
                        return (cmp(x.first, y.first));
                    }
            };
        
        public: //PRIVATE VALUE
            allocator_type          alloc;
            std::allocator<btree>   tree_alloc;
            key_compare             cmp;
            btree                   *tree;
            btree                   *header;
            size_type               map_size;

        private :

            /*renvoie un pointeur vers le plus petit element de l'arbre*/
            btree       *find_lower() const 
            {
                return (header->upper); //contre intuitif mais ca permet de faire une boucle
            }
            btree       *find_lower(btree *tmp) const 
            {
                while(tmp->lower_flag)
                    tmp = tmp->lower;
                return (tmp); //contre intuitif mais ca permet de faire une boucle
            }

            /*renvoie un pointeur vers le plus grand element de l'arbre*/
            btree       *find_upper() const
            {
                return (header->lower); //contre intuitif mais ca permet de faire une boucle
            }
            btree       *find_upper(btree *tmp) const 
            {
                while(tmp->upper_flag)
                    tmp = tmp->upper;
                return (tmp); //contre intuitif mais ca permet de faire une boucle
            }

             /*renvoie un pointeur vers l'element qui va acceuillir dans son upper ou lower un nouvel element*/
            ft::pair<iterator, bool>    find_place(const key_type &k) const
            {
                btree   *tmp = tree;

                if (!tree)
                    return (ft::pair<iterator, bool>(iterator(header), true));
                while (1)
                {
                    if (cmp(tmp->pair.first, k) && tmp->upper_flag == 0) // plus grand et rien apres
                        return (ft::pair<iterator, bool>(iterator(tmp), true));
                    else if (cmp(k, tmp->pair.first) && tmp->lower_flag == 0) // plus petit et rien apres
                        return (ft::pair<iterator, bool>(iterator(tmp), true));
                    else if (cmp(tmp->pair.first, k) && tmp->upper_flag == 1) // plus grand 
                        tmp = tmp->upper;
                    else if (cmp(k, tmp->pair.first) && tmp->lower_flag == 1) //plus petit
                        tmp = tmp->lower;
                    else
                        return(ft::pair<iterator, bool>(iterator(tmp), false)); // if (elem are equal)
                }
            }
            ft::pair<iterator, bool>    find_place(iterator start, const key_type &k) const
            {
                btree   *tmp;

                if (!tree)
                    return (ft::pair<iterator, bool>(iterator(header), true));
                if (start == this->end())
                    tmp = tree;
                else
                    tmp = reinterpret_cast<btree *>(&*start);
                while (1)
                {
                    if (cmp(tmp->pair.first, k) && tmp->upper_flag == 0) // plus grand et rien apres
                        return (ft::pair<iterator, bool>(iterator(tmp), true));
                    else if (cmp(k, tmp->pair.first) && tmp->lower_flag == 0) // plus petit et rien apres
                        return (ft::pair<iterator, bool>(iterator(tmp), true));
                    else if (cmp(tmp->pair.first, k) && tmp->upper_flag == 1) // plus grand + inc si tmp == header
                    {
                        tmp = tmp->upper;
                        tmp = tmp == header ? tmp->upper : tmp;
                    }
                    else if (cmp(k, tmp->pair.first) && tmp->lower_flag == 1) //plus petit + inc si tmp == header
                    {
                        tmp = tmp->lower;
                        tmp = tmp == header ? tmp->lower : tmp;
                    }
                    else
                        return(ft::pair<iterator, bool>(iterator(tmp), false)); // if (elem are equal)
                }
            }

            /*tree function call by insert to create a new_element*/
            void first_add(btree *new_elem)
            {
                header->upper = new_elem; 
                header->lower = new_elem;

                new_elem->upper = this->header;
                new_elem->lower = this->header;

                new_elem->upper_flag = 0;
                new_elem->lower_flag = 0;
 
                tree = new_elem;
            }
            void add_upper(btree *position, btree *new_elem)
            {
                if (position == find_upper())
                    header->lower = new_elem;
                
                new_elem->upper = position->upper;
                new_elem->lower = position;

                new_elem->upper_flag = 0;
                new_elem->lower_flag = 0;

                position->upper_flag = 1;
                position->upper = new_elem;
            }
            void add_lower(btree *position, btree *new_elem)
            {
                 if (position == find_lower())
                    header->upper = new_elem;

                position->lower_flag = 1;
                new_elem->lower = position->lower;
                new_elem->upper = position;

                new_elem->upper_flag = 0;
                new_elem->lower_flag = 0;

                position->lower = new_elem;
            };

            /*function to add element inside tree*/
            /*iterator add_elem(const value_type &val) //peut etre necessaire d'en faire une version const
            {
                btree *new_elem;
                btree *position;

                try
                {
                    position = find_place(val.first);
                    new_elem = tree_alloc.allocate(1);
                    alloc.construct(&new_elem->pair, val);
                    if (position == NULL)
                        first_add(new_elem);
                    else if (cmp(position->pair.first, val.first))
                        add_upper(position, new_elem);
                    else
                        add_lower(position, new_elem);
                    ++map_size;
                    return(iterator(new_elem));
                }
                catch(const ft::exception& e){ return(end()); }
            }*/

            void    erase_unique()
            {
                tree_alloc.deallocate(tree, 1);
                tree = NULL;

                header->upper = header;
                header->lower = header;
            }
            void    erasea(btree *tree, btree *pred)
            {
                tree_alloc.deallocate(tree, 1);
                tree = NULL;

                header->upper = header;
                header->lower = header;
            }
               
            /*cree le header*/
            void    add_header()
            {
                header = tree_alloc.allocate(1);
                alloc.construct(&header->pair, value_type());
                header->upper = header;
                header->lower = header;

                header->upper_flag = 0;
                header->lower_flag = 0;
            }

            /*Pour copier map tout en respectant l'architecture de l'arbre*/
            void cpy_tree(btree *cpy, iterator hint)
            {
                iterator    it;
                btree *tmp;

                it = insert(hint, cpy->pair);
                if (cpy->lower_flag)
                    cpy_tree(cpy->lower, it);
                if (cpy->upper_flag)
                    cpy_tree(cpy->upper, it);
            }

        public: //PUBLIC FUNCTION
            //CONSTRUCTOR DESTRUCTOR
            explicit map(const key_compare& comp = key_compare(), const allocator_type alloc = allocator_type())
            : alloc(alloc), cmp(comp)
            {
                tree_alloc = std::allocator<btree>();
                tree = NULL;
                add_header();

                map_size = 0;
            }
            template <typename InputIterator>
            map(InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last,
            const key_compare& comp = key_compare(), const allocator_type &alloc = allocator_type()) : alloc(alloc), cmp(comp)
            {
                tree_alloc = std::allocator<btree>();
                tree = NULL;
                map_size = 0;
                add_header();

                insert(first, last);
            }
            map(const map &x) : alloc(x.alloc), cmp(x.cmp) //trier avec cmp ???
            {
                tree_alloc = std::allocator<btree>();
                add_header();

                map_size = 0;
                tree = NULL;
                if (x.tree != NULL)
                    cpy_tree(x.tree, begin());
            }
            map    &operator=(const map &x)
            {
                clear();

                map_size = 0;
                tree = NULL;
                if (x.tree != NULL)
                    cpy_tree(x.tree, begin());

                return(*this);
            }
            ~map()
            {
                clear();
                tree_alloc.deallocate(header, 1);
            }
            //ITERATORS
            iterator    begin()
            {
                return (iterator(find_lower()));
            }

            const_iterator    begin() const
            {
                return (const_iterator(find_lower()));
            }

            iterator    end()
            {
                return (iterator(header));
            }

            const_iterator    end() const
            {
                return (const_iterator(header));
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
                return (map_size);
            }

            bool        empty() const
            {
                return (!map_size);
            }

            size_type   max_size() const
            {
                return (tree_alloc.max_size());
            }
            //ELEMENT ACCESS
            mapped_type     &operator[](const key_type & k)
            {
                iterator it;

                /*it = find(k);
                if (it == end())
                {*/
                it = insert(value_type(k, mapped_type())).first; //a verifier
                //}
                return (it->second);

            }
            //MODIFIER map
            ft::pair<iterator, bool>    insert(const value_type &val)
            {
                btree *new_elem;
                ft::pair<iterator, bool> position;

                position = find_place(val.first);
                if (position.second == false)
                    return (position);
                new_elem = tree_alloc.allocate(1);
                alloc.construct(&new_elem->pair, val);
                if (position.first == end())
                    first_add(new_elem);
                else if (cmp(position.first->first, val.first))
                    add_upper(reinterpret_cast<btree *>(&*(position.first)), new_elem);
                else
                    add_lower(reinterpret_cast<btree *>(&*(position.first)), new_elem);
                ++map_size;
                position.first = iterator(new_elem);
                return(position);
            }
            iterator    insert(iterator start, const value_type &val)
            {
                btree *new_elem;
                ft::pair<iterator, bool> position;

                position = find_place(start, val.first);
                if (position.second == false)
                    return (position.first);
                new_elem = tree_alloc.allocate(1);
                alloc.construct(&new_elem->pair, val);
                if (position.first == end())
                    first_add(new_elem);
                else if (cmp(position.first->first, val.first))
                    add_upper(reinterpret_cast<btree *>(&*(position.first)), new_elem);
                else
                    add_lower(reinterpret_cast<btree *>(&*(position.first)), new_elem);
                ++map_size;
                position.first = iterator(new_elem);
                return(position.first);    
            }
            template <class InputIterator>
            void    insert(InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
            {
                while(first != last)
                    insert(*first++);
            }
            void        erase(iterator position)
            {
                iterator p1(position);
                btree   *after = reinterpret_cast<btree *>(&*++position);
                btree   *actual = reinterpret_cast<btree *>(&*--position);
                btree   *before = reinterpret_cast<btree *>(&*--position);

                if (actual->lower_flag && actual->upper_flag)
                {

                }
                if (actual->lower_flag ^ actual->upper_flag) //seems ok si il n'y a qu'un flag
                {
                    //before = reinterpret_cast<btree *>(++p1);
                    //after = reinterpret_cast<btree *>(--position);
                    before->lower
                    while(before->lower_flag)
                    before->lower = after; //before while position != 0
                    after->upper = actual->upper;

                    tree_alloc.deallocate(actual, 1);
                }
                else if (!actual->lower_flag && !actual->upper_flag)
                {
                    before->upper = after;
                    after->lower = before;

                    tree_alloc.deallocate(actual, 1);
                    
                }


            }
            size_type   erase(const key_type &k)
            {
                btree *tmp = tree;
                btree *tmp2 = NULL;

                while (tmp)
                {
                    if (cmp(tmp->pair.first, k))
                    {
                        if (!tmp->upper_flag)
                            return(0);
                        tmp2 = tree;
                        tmp = tmp->upper;
                    }
                    else if (cmp(k, tmp->pair.first))
                    {
                        if(!tmp->lower_flag)
                            return(0);
                        tmp2 = tree;
                        tmp = tmp->lower;  
                    }
                    else
                    {
                        delete_elem(tmp, tmp2);
                    }
                }
                return(0);
            }
            void    erase(iterator first, iterator last)
            {
                while (first != last)
                    erase(first++);
            }
            void        swap(map &x)
            {
                btree   *tmp_tree = x.tree;
                btree   *tmp_header = x.header;
                size_t  tmp_size = x.map_size;

                x.tree = this->tree;
                x.header = this->header;
                x.map_size = this->map_size;

                this->tree = tmp_tree;
                this->header = tmp_header;
                this->map_size = tmp_size;
            }

            void        clear()
            {
                iterator    it(begin());

                while (map_size > 0)
                {
                    alloc.destroy(&*it);
                    tree_alloc.deallocate(reinterpret_cast<btree *>(&*it++), 1);
                    --map_size;
                }
                header->upper = header;
                header->lower = header;
                tree = NULL;
            }
            //OBSERVERS
            key_compare     key_comp() const
            {
                return (cmp);
            }
            value_compare     value_comp() const //dont know
            {
                return (value_compare());
            }
            //OPERATION
            iterator    find(const key_type &k)
            {
                btree   *tmp = tree;

                while (tmp)
                {
                    if (cmp(tmp->pair.first, k))
                    {
                        if (!tmp->upper_flag)
                            return(end());
                        tmp = tmp->upper;
                    }
                    else if (cmp(k, tmp->pair.first))
                    {
                        if(!tmp->lower_flag)
                            return(end());
                        tmp = tmp->lower;  
                    }
                    else
                        return(iterator(tmp));
                }
                return(end());
            }
            const_iterator    find(const key_type &k) const
            {
                btree   *tmp = tree;

                while (tmp)
                {
                    if (cmp(tmp->pair.first, k))
                    {
                        if (!tmp->upper_flag)
                            return(end());
                        tmp = tmp->upper;
                    }
                    else if (cmp(k, tmp->pair.first))
                    {
                        if(!tmp->lower_flag)
                            return(end());
                        tmp = tmp->lower;  
                    }
                    else
                        return(iterator(tmp));
                }
                return(end());
            }
            size_type   count(const key_type &k) const
            {
                return (find(k) != end());
            }

            iterator    lower_bound(const key_type &k)
            {
                iterator    it(begin());
                iterator    last(end());

                while(it != last)
                {
                    if (!cmp(it->first, k))
                        return(it);
                    ++it;
                }
                return(last);
            }
            const_iterator    lower_bound(const key_type &k) const
            {
                const_iterator    it(begin());
                const_iterator    last(end());

                while(it != last)
                {
                    if (!cmp(it->first, k))
                        return(it);
                    ++it;
                }
                return(last);
            }

            iterator    upper_bound(const key_type &k)
            {
                iterator    it(begin());
                iterator    last(end());

                while(it != last)
                {
                    if (cmp(k, it->first))
                        return(it);
                    ++it;
                }
                return(end());
            }
            const_iterator    upper_bound(const key_type &k) const
            {
                const_iterator    it(begin());
                const_iterator    last(end());

                while(it != last)
                {
                    if (cmp(k, it->first))
                        return(it);
                    ++it;
                }
                return(end());
            }

            ft::pair<iterator, iterator>    equal_range(const key_type &k)
            {
                return (ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
            }
            ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
            {
                return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
            }

    };
};

#endif