#sed 's/b/a/g' srcs/test/test.cpp

#VECTOR TEST without extension.cpp
#VECTOR_DIR = vector/
#VECTOR_EXEC = $(addprefix $(VECTOR_DIR), \
				insert)\
				#reserve resize at push_pop assign erase swap_clear
				#char_construct int_construct string_construct double_construct pointer_construct \
				char_iterator struct_iterator string_iterator double_iterator \
				char_construct2 int_construct2 float_construct2 struct_construct2 string_construct2)

#resize or reserve verif with x1 place of x2
#VECTOR_SRCS = $(addsuffix .cpp, $(VECTOR_EXEC))

LIST_DIR = list/
LIST_EXEC = $(addprefix $(LIST_DIR), \
			erase) # default_constructor constructor2 push_pop_front push_pop_back iterator constructor3 assign resize clear swap

#resize or reserve verif with x1 place of x2
LIST_SRCS = $(addsuffix .cpp, $(LIST_EXEC))

FT_DIR = test_ft/
STD_DIR = test_std/
FT_SRCS = $(addprefix $(FT_DIR), $(VECTOR_SRCS) $(LIST_SRCS))
STD_SRCS = $(addprefix $(STD_DIR), $(VECTOR_SRCS) $(LIST_SRCS))

SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR), $(FT_SRCS) $(STD_SRCS))

OBJS = $(SRCS:.cpp=.o)

EXEC_DIR = bin/
FT_EXEC_DIR = test_ft/
STD_EXEC_DIR = test_std/

FT_EXEC = $(addprefix $(FT_EXEC_DIR), $(VECTOR_EXEC) $(LIST_EXEC))
STD_EXEC = $(addprefix $(STD_EXEC_DIR), $(VECTOR_EXEC) $(LIST_EXEC))
EXEC  = $(addprefix $(EXEC_DIR), $(FT_EXEC) $(STD_EXEC))

#POUR LA COMPILATION IMPLICITE DES .CPP
CXX = clang++
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
