#sed 's/b/a/g' srcs/test/test.cpp

#VECTOR TEST without extension.cpp

#leaks to do and don't test max_size on resize and probably other
#VECTOR_DIR = vector/
#VECTOR_EXEC = $(addprefix $(VECTOR_DIR), \
				iterator)\
				#constructor reserve resize assign push_pop swap clear insert erase operator iterator

#VECTOR_SRCS = $(addsuffix .cpp, $(VECTOR_EXEC))


#LIST_DIR = list/
#LIST_EXEC = $(addprefix $(LIST_DIR), \
			default_constructor constructor2 push_pop_front \
			push_pop_back iterator constructor3 assign resize clear swap erase insert \
			splice remove remove_if unique merge sort reverse operator)

#LIST_SRCS = $(addsuffix .cpp, $(LIST_EXEC))

MAP_DIR = map/
MAP_EXEC = $(addprefix $(MAP_DIR), \
			value_comp) # constructor find tab clear swap)

MAP_SRCS = $(addsuffix .cpp, $(MAP_EXEC))

FT_DIR = test_ft/
STD_DIR = test_std/
FT_SRCS = $(addprefix $(FT_DIR), $(MAP_SRCS)) #$(VECTOR_SRCS) $(LIST_SRCS))
STD_SRCS = $(addprefix $(STD_DIR), $(MAP_SRCS)) #$(VECTOR_SRCS) $(LIST_SRCS))

SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR), $(FT_SRCS) $(STD_SRCS))

OBJS = $(SRCS:.cpp=.o)

EXEC_DIR = bin/
FT_EXEC_DIR = test_ft/
STD_EXEC_DIR = test_std/

FT_EXEC = $(addprefix $(FT_EXEC_DIR), $(MAP_EXEC)) #$(VECTOR_EXEC) $(LIST_EXEC)
STD_EXEC = $(addprefix $(STD_EXEC_DIR), $(MAP_EXEC)) #$(VECTOR_EXEC) $(LIST_EXEC)
EXEC  = $(addprefix $(EXEC_DIR), $(FT_EXEC) $(STD_EXEC))

#POUR LA COMPILATION IMPLICITE DES .CPP
CXX = clang++ -std=c++98
INCLUDE = -I ../include
CPPFLAGS = $(INCLUDE) #-Wall -Wextra -Werror

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CXX) $(CPPFLAGS) $(INCLUDE) -o $@ \
	$(subst $(EXEC_DIR),$(SRCS_DIR),$@).cpp

clean :
	rm -f $(EXEC)

fclean : clean

re : fclean all
