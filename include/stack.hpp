#ifndef STACK_HPP
# define STACK_HPP

# include <memory> //std::allocator<T>
# include <stdexcept> //exception
# include "iterator.hpp"
# include <iostream> 
# include "list.hpp"

namespace   ft
{   
    template <typename T, class Containers = ft::list<T> >
    class   stack
    {
        public : //TYPEDEF
            typedef T value_type;
            typedef container_type Container;
            typedef size_t size_type;
        
        public: //PRIVATE VALUE
            allocator_type          value_alloc;
            std::allocator<node>    node_alloc;
            node                    *dummy_node;
            size_type               node_size;

        private :
            container_type  container;
        public: //FUNCTION
            //CONSTRUCTOR DESTRUCTOR
            explicit stack(const container_type &ctnr) : container(cntr)
            {

            }
            ~stack() {}
            size_type   size() const
            {
                return (container.size());
            }

            bool        empty() const
            {
                return (container.empty());
            }

            value_type &top()
            {
                return(container.back());
            }
            const value_type &top() const
            {
                return(container.back());
            }

            void    push(const value_type &val)
            {
                container.push_back(val);
            }

            void    pop()
            {
                container.pop_back();
            }

            //RELATIONAL OPERATOR
            bool operator==(const stack& rhs) const
            {
                return (this->container == rhs.container);
            }
            bool operator!=(const stack& rhs) const
            {
                return (this->container != rhs.container);
            }
            bool operator<(const stack& rhs) const
            {
                return (this->container < rhs.container);
            }
            bool operator>(const stack& rhs) const
            {
                return (this->container > rhs.container);
            }
            bool operator>=(const stack& rhs) const
            {
               return (this->container >= rhs.container);
            }
            bool operator<=(const stack& rhs) const
            {
                return (this->container <= rhs.container);
            }
    };
};

#endif