#include "razorclam_tests.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include "../WrongAnimal.hpp"

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

	debug("=== Creating a simple WrongAnimal\n");
	WrongAnimal bob;
	debug("%s", output.str().c_str());
	
	// check if the output is as expected
	std::string expectedOutput = "WrongAnimal default constructor called\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : WrongAnimal default constructor called");

	//clear
	output.str("");

	// this is the same as creating bob previously. it will use the default constructor
	WrongAnimal bob2 = WrongAnimal();
	debug("%s", output.str().c_str());
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : WrongAnimal default constructor called");

	output.str("");

	WrongAnimal bob3 = WrongAnimal("unknown");
	debug("%s", output.str().c_str());

	// check if the output is as expected
	expectedOutput = "WrongAnimal constructor called\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : WrongAnimal constructor called");
	
	expectedOutput = "unknown";
	my_assert(strcmp(bob3.getType().c_str(), expectedOutput.c_str()) == 0, "should be : unknown");
	debug("WrongAnimal type %s", bob3.getType().c_str());
	output.str("");

	return NULL;
}

// the WrongAnimals are destructed in reverse order of their creation
const char *test_destructors(){

	debug("=== Testing the destructors\n");
	debug("%s", output.str().c_str());	

	std::string expectedOutput = "WrongAnimal destructor called\nWrongAnimal type was unknown\nWrongAnimal destructor called\nWrongAnimal type was -\nWrongAnimal destructor called\nWrongAnimal type was -\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : WrongAnimal constructor called");	
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

