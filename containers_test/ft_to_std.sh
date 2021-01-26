sed -e 's/ft::vector/std::vector/g' -e 's/include "vector.hpp"/include <vector>/g' -e 's/ft::swap/std::swap/g' \
srcs/test_ft/$1  > srcs/test_std/$1