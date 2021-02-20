sed -e 's/ft::vector/std::vector/g' -e 's/include "vector.hpp"/include <vector>/g' -e 's/ft::swap/std::swap/g' \
-e 's/ft::list/std::list/g' -e 's/include "list.hpp"/include <list>/g' \
srcs/test_ft/$1  > srcs/test_std/$1