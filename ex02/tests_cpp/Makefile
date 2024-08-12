CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++

# the file to tests (SUT = System Under Test)
SUT_SRCS = $(addprefix ../, AAnimal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp)
# will be compiled into object files
SUT_OBJS = $(SUT_SRCS:.cpp=.o)

# explicit rule to create the o files as might be necessary on some systems
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# my test files - each one has a main and will 
# be compiled into an executable
TEST_SRCS= AAnimal_tests.cpp Cat_tests.cpp Dog_tests.cpp \
WrongAnimal_tests.cpp WrongCat_tests.cpp Brain_tests.cpp
# this substitution create files without the extension
# they will become the executables
TESTS=$(patsubst %.cpp,%,$(TEST_SRCS))

# the target build
all: tests valgrind
	
tests: $(TESTS) runtests

$(TESTS): $(SUT_OBJS) $(TEST_SRCS) 
	$(CXX) $(CXXFLAGS) $(SUT_OBJS) $@.cpp -o $@

runtests:
	sh ./runtests.sh

clean:
	rm -f *.o
	rm -f tests.log

fclean: clean
	rm -rf $(TESTS)

re: fclean tests

.PHONY: all tests re fclean clean runtests

ifeq ($(shell uname -s), Linux)
valgrind:
	@echo
	@echo "==================\nLaunching valgrind..."
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE) tests
else
valgrind:
	@echo "No valgrind on this system"
endif