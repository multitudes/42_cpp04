#include "razorclam_tests.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include "../Animal.hpp"

/* std::stringstream object named output. 
This object can be used to construct strings using the << operator, 
just like std::cout. */
std::stringstream output;

/*
This line redirects std::cout to output. 
This means that anything written to std::cout will now be written 
to output instead. The original buffer of std::cout is saved 
in oldCoutBuffer so it can be restored later.
*/
std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

// This is the entry point for the test suite
const char *test_constructors(){

	debug("=== Creating a simple Animal\n");
	Animal bob;
	debug("%s", output.str().c_str());
	
	// check if the output is as expected
	std::string expectedOutput = "Animal default constructor called\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : Animal default constructor called");

	//clear string stream
	output.str("");

	// this is the same as creating bob previously. it will use the default constructor
	Animal bob2 = Animal();
	debug("%s", output.str().c_str());
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : Animal default constructor called");

	//clear string stream
	output.str("");

	Animal bob3 = Animal("unknown");
	debug("%s", output.str().c_str());

	// check if the output is as expected
	expectedOutput = "Animal constructor called\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : Animal constructor called");
	
	expectedOutput = "unknown";
	my_assert(strcmp(bob3.getType().c_str(), expectedOutput.c_str()) == 0, "should be : unknown");
	debug("animal type %s", bob3.getType().c_str());
	output.str("");

	return NULL;
}

// the Animals are destructed in reverse order of their creation
const char *test_destructors(){

	debug("=== Testing the destructors\n");
	debug("%s", output.str().c_str());	

	std::string expectedOutput = "Animal destructor called\nAnimal type was unknown\nAnimal destructor called\nAnimal type was -\nAnimal destructor called\nAnimal type was -\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : Animal constructor called");	
	
	//clear string stream
	output.str("");

	return NULL;
}

const char *all_tests()
{
	// necessary to start the test suite
	suite_start();
	
	// run the tests
	run_test(test_constructors);
	run_test(test_destructors);

	/*
	This line restores the original buffer of std::cout, 
	undoing the redirection to output.
	*/
	std::cout.rdbuf(oldCoutBuffer);
	
	return NULL;
}

// works as a main
RUN_TESTS(all_tests);

