EXEC = construct_vector construct_bool_vector iterator_test

MY = my_

MY_CONTAINERS = my_containers/construct_vector.cpp my_containers/construct_bool_vector.cpp my_containers/iterator_test.cpp
CONTAINERS = containers/construct_vector.cpp containers/construct_bool_vector.cpp containers/iterator_test.cpp

SRCSDIR = srcs/

SRCS = $(addprefix $(SRCSDIR), $(SRCSFILE))

CC = clang++
CFLAGS = -I ./include -Wall -Wextra -Werror -std=c++98

all : $(EXEC)

$(EXEC) :
	$(CC) $(CFLAGS) -o $(MY)$@ $(addprefix $(SRCSDIR)my_containers/, $(addsuffix .cpp, $@))
	mv $(MY)$@ my_binary/
	$(CC) $(CFLAGS) -o $@ $(addprefix $(SRCSDIR)containers/, $(addsuffix .cpp, $@))
	mv $@ binary/

clean :
	rm -f  $(addprefix binary/, $(EXEC))
	rm -f $(addprefix my_binary/$(MY), $(EXEC))

fclean : clean

re : fclean all

.PHONY : re fclean clean all
