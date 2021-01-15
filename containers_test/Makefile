#sed 's/b/a/g' srcs/test/test.cpp

#VECTOR TEST without extension.cpp
VECTOR_DIR = vector/
VECTOR_EXEC = $(addprefix $(VECTOR_DIR), \
				char_construct int_construct string_construct double_construct pointer_construct \
				myclass_construct \
				char_iterator) #int_iterator double_iterator string_iterator myclass_iterator)
VECTOR_SRCS = $(addsuffix .cpp, $(VECTOR_EXEC))

FT_DIR = test_ft/
STD_DIR = test_std/
FT_SRCS = $(addprefix $(FT_DIR), $(VECTOR_SRCS))
STD_SRCS = $(addprefix $(STD_DIR), $(VECTOR_SRCS))

SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR), $(FT_SRCS) $(STD_SRCS))

OBJS = $(SRCS:.cpp=.o)

EXEC_DIR = bin/
FT_EXEC_DIR = test_ft/
STD_EXEC_DIR = test_std/

FT_EXEC = $(addprefix $(FT_EXEC_DIR), $(VECTOR_EXEC))
STD_EXEC = $(addprefix $(STD_EXEC_DIR), $(VECTOR_EXEC))
EXEC  = $(addprefix $(EXEC_DIR), $(FT_EXEC) $(STD_EXEC))

#POUR LA COMPILATION IMPLICITE DES .CPP
CXX = clang++
INCLUDE = -I ../include -I srcs/class/
CPPFLAGS = -Wall -Wextra -Werror $(INCLUDE)

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CXX) $(CPPFLAGS) $(INCLUDE) -o $@ \
	$(subst $(EXEC_DIR),$(SRCS_DIR),$@).cpp

clean :
	rm -f $(EXEC)

fclean : clean

re : fclean all
