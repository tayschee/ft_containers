// iterator_traits example
#include <iostream>     // std::cout
#include <iterator>     // ft::iterator_traits
#include <typeinfo>     // typeid
#include "iterator.hpp"

int main() {
  typedef ft::iterator_traits<int *> traits;
  if (typeid(traits::iterator_category) == typeid(ft::random_access_iterator_tag))
    std::cout << "int* is a random-access iterator";
  return 0;
}