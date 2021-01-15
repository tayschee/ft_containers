sed -e 's/ft::vector/std::vector/g' -e 's/include "vector.hpp"/include <vector>/g' \
srcs/test_ft/$1  > srcs/test_std/$1