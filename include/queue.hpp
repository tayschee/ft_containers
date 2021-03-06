#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <memory> //std::allocator<T>
# include <stdexcept> //exception
# include "iterator.hpp"
# include <iostream> 
# include "list.hpp"

namespace   ft
{   
    template <typename T, class Containers = ft::list<T> >
    class   queue
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
            explicit queue(const container_type &ctnr) : container(cntr)
            {

            }
            ~queue() {}
            size_type   size() const
            {
                return (container.size());
            }

            bool        empty() const
            {
                return (container.empty());
            }

            value_type &back()
            {
                return(container.back());
            }
            const value_type &back() const
            {
                return(container.back());
            }

            value_type &front()
            {
                return(container.front());
            }
            const value_type &front() const
            {
                return(container.front());
            }

            void    push(const value_type &val)
            {
                container.push_back(val);
            }

            void    pop()
            {
                container.pop_front();
            }

            //RELATIONAL OPERATOR
            bool operator==(const queue& rhs) const
            {
                return (this->container == rhs.container);
            }
            bool operator!=(const queue& rhs) const
            {
                return (this->container != rhs.container);
            }
            bool operator<(const queue& rhs) const
            {
                return (this->container < rhs.container);
            }
            bool operator>(const queue& rhs) const
            {
                return (this->container > rhs.container);
            }
            bool operator>=(const queue& rhs) const
            {
               return (this->container >= rhs.container);
            }
            bool operator<=(const queue& rhs) const
            {
                return (this->container <= rhs.container);
            }
    };
};

#endif