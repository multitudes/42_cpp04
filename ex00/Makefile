CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS += -Wshadow -Wconversion -Wunreachable-code

# -O0: Disables optimization to make debugging easier..
CXXFLAGS += -g3 -O0

# Uncomment this line to turn off debug flags
# CXXFLAGS += -DNDEBUG
CXX = c++

NAME = animals 
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME) tests

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)
	make -C tests_cpp clean

fclean : clean
	rm -f $(NAME)
	make -C tests_cpp fclean

re : fclean all

tests:
	make -C tests_cpp

run: all
	@echo
	@PATH=".$${PATH:+:$${PATH}}" && $(NAME) $(ARGS)

valrun: all
	@echo
	@PATH=".$${PATH:+:$${PATH}}" && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes $(NAME) $(ARGS)


.PHONY : all clean fclean re tests run valrun
