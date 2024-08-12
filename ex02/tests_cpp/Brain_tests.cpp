/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:27:39 by lbrusa            #+#    #+#             */
/*   Updated: 2024/04/03 17:03:19 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "razorclam_tests.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include "../Brain.hpp"

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

	debug("=== Creating a simple Brain\n");
	Brain brain;
	debug("%s", output.str().c_str());
	
	// check if the output is as expected
	std::string expectedOutput = "Brain default constructor called\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : \nBrain default constructor called");

	//clear
	output.str("");

	// this is the same as creating brain previously. it will use the default constructor
	Brain brain2 = Brain();
	debug("%s", output.str().c_str());
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : \nBrain default constructor called");
	output.str("");
	brain.setIdea(0, "idea1");
	brain.setIdea(1, "idea2");
	brain.setIdea(2, "idea3");
	std::string idea1 = brain.getIdea(0);
	std::string idea2 = brain.getIdea(1);
	std::string idea3 = brain.getIdea(2);
	debug("idea 0: %s\n", brain.getIdea(0).c_str());
	debug("idea 1: %s\n", brain.getIdea(1).c_str());
	debug("idea 2: %s\n", brain.getIdea(2).c_str());

	// check if the output is as expected
	expectedOutput = "idea1";
	my_assert(strcmp(idea1.c_str(), expectedOutput.c_str()) == 0, "should be : idea1");
	expectedOutput = "idea2";
	my_assert(strcmp(idea2.c_str(), expectedOutput.c_str()) == 0, "should be : idea2");
	expectedOutput = "idea3";
	my_assert(strcmp(idea3.c_str(), expectedOutput.c_str()) == 0, "should be : idea3");
	

	return NULL;
}

// the Animals are destructed in reverse order of their creation - 
// I get the stream from the output of the previous test and can see 
// the order of the destructors
const char *test_destructors(){

	debug("=== Testing the destructors\n");
	debug("destructors called %s", output.str().c_str());	

	std::string expectedOutput = "Brain destructor called\n"
	"Brain destructor called\n";
	
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be :");	
	output.str("");

	return NULL;
}

const char *test_copy_constructor(){

	debug("=== Testing the copy constructor\n");
	Brain brain;
	brain.setIdea(0, "idea1");
	brain.setIdea(1, "idea2");
	brain.setIdea(2, "idea3");
	Brain brain2 = brain;
	std::string idea1 = brain2.getIdea(0);
	std::string idea2 = brain2.getIdea(1);
	std::string idea3 = brain2.getIdea(2);
	debug("idea 0: %s\n", brain2.getIdea(0).c_str());
	debug("idea 1: %s\n", brain2.getIdea(1).c_str());
	debug("idea 2: %s\n", brain2.getIdea(2).c_str());

	// check if the output is as expected
	std::string expectedOutput = "idea1";
	my_assert(strcmp(idea1.c_str(), expectedOutput.c_str()) == 0, "should be : idea1");
	expectedOutput = "idea2";
	my_assert(strcmp(idea2.c_str(), expectedOutput.c_str()) == 0, "should be : idea2");
	expectedOutput = "idea3";
	my_assert(strcmp(idea3.c_str(), expectedOutput.c_str()) == 0, "should be : idea3");

	output.str("");
	
	return NULL;
}
// order matters!
const char *all_tests()
{
	// necessary to start the test suite
	suite_start();
	
	// run the tests - the order matters
	run_test(test_constructors);
	run_test(test_destructors);
	run_test(test_copy_constructor);

	std::cout.rdbuf(oldCoutBuffer);
	return NULL;
}


// works as a main
RUN_TESTS(all_tests);

