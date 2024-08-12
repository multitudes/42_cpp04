/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:27:39 by lbrusa            #+#    #+#             */
/*   Updated: 2024/04/04 18:33:17 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "razorclam_tests.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include "../Cat.hpp"

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

	debug("=== Creating a simple Cat\n");
	Cat dora;
	debug("%s", output.str().c_str());
	
	// check if the output is as expected
	std::string expectedOutput = "Animal constructor called\n"
	"Cat constructor called\n"
	"Brain default constructor called\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : \nAnimal constructor called\nCat constructor called\nBrain default constructor called");

	//clear
	output.str("");

	// this is the same as creating dora previously. it will use the default constructor
	Cat dora2 = Cat();
	debug("%s", output.str().c_str());
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : \nAnimal constructor called\nCat constructor called");

	output.str("");

	Cat dora3 = Cat();
	debug("%s", output.str().c_str());
	debug("---------");
	// check if the output is as expected
	expectedOutput = "Animal constructor called\n"
	"Cat constructor called\n"
	"Brain default constructor called\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : \nAnimal constructor called\nCat constructor called");

	expectedOutput = "Cat";
	debug("animal type %s", dora3.getType().c_str());
	my_assert(strcmp(dora3.getType().c_str(), expectedOutput.c_str()) == 0, "should be : cat");

	output.str("");
	/*
	This line restores the original buffer of std::cout, 
	undoing the redirection to output.
	*/
	// std::cout.rdbuf(oldCoutBuffer);
	return NULL;
}

// the Animals are destructed in reverse order of their creation - 
// I get the stream from the output of the previous test and can see 
// the order of the destructors
const char *test_destructors(){

	debug("=== Testing the destructors\n");
	debug("%s", output.str().c_str());	

	std::string expectedOutput = "Cat destructor called\n"
	"Brain destructor called\n"
	"Animal destructor called\n"
	"Animal type was Cat\n"
	"Cat destructor called\n"
	"Brain destructor called\n"
	"Animal destructor called\n"
	"Animal type was Cat\n"
	"Cat destructor called\n"
	"Brain destructor called\n"
	"Animal destructor called\n"
	"Animal type was Cat\n";
	
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be :...");	
	output.str("");

	return NULL;
}


// I will create a cat with a pointer and on the stack and check if the sounds are correct
const char *test_sounds() {
	debug("=== Testing the sounds\n");

	Cat dora = Cat();
	output.str("");

	dora.makeSound();
	debug("%s", output.str().c_str());
	std::string expectedOutput = "Meow meow\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : Meow meow\n");

	output.str("");

	// need a pointer to get the polymorphic behavior
	AAnimal* doraPTR = new Cat();
	output.str("");
	debug("Animal cat doraPTR says: %s", output.str().c_str());
	doraPTR->makeSound();  // Calls Cat::makeSound()
	expectedOutput = "Meow meow\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : Meow meow\n");

	output.str("");	

	delete doraPTR;  // Don't forget to delete dora when you're done with it
	debug("Animal cat doraPTR being destroyed: %s", output.str().c_str());
	expectedOutput = "Cat destructor called\n"
					"Brain destructor called\n"
					"Animal destructor called\n"
					"Animal type was Cat\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : Cat destructor called\nAnimal destructor called\nAnimal type was Cat\n");
	
	output.str("");

	return NULL;
}

const char *test_brains()
{
	debug("=== Testing the brains\n");
	Cat dora = Cat();
	output.str("");	
	dora.setIdea(0, "I am a cat");
	debug("idea: %s", dora.getIdea(0).c_str());
	std::string expectedOutput = "I am a cat";
	my_assert(strcmp(dora.getIdea(0).c_str(), expectedOutput.c_str()) == 0, "should be : I am a cat");
	
	output.str("");

	Cat fluffy = dora;
	my_assert(strcmp(fluffy.getIdea(0).c_str(), expectedOutput.c_str()) == 0, "should be : I am a cat");
	
	
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
	run_test(test_sounds);
	run_test(test_brains);
	
	std::cout.rdbuf(oldCoutBuffer);
	return NULL;
}


// works as a main
RUN_TESTS(all_tests);


/*
More about the sequense of constructors and destructors:
When you write Animal dora4 = Cat();, the following sequence of calls occurs:

The Cat constructor is called, which in turn calls the Animal constructor with the argument "Cat". This is because Cat is derived from Animal and the Cat constructor initializes the Animal part of the Cat object.

The Animal constructor is called with the argument "Cat". This constructor prints "Animal constructor called" to the standard output.

The copy constructor of Animal is called. This is because the Cat object is being used to initialize an Animal object. The copy constructor is responsible for creating a new Animal object based on the Cat object. In this case, the copy constructor prints "Animal copy constructor called" to the standard output.

The assignment operator of Animal is called. This is because the Animal object dora4 is being assigned the value of the Animal object created in the previous step. The assignment operator is responsible for copying the values from one Animal object to another. In this case, the assignment operator prints "Animal assignment operator called" to the standard output.

The Cat destructor is called. This is because the temporary Cat object created in the first step is destroyed. The destructor prints "Cat destructor called" to the standard output.

The Animal destructor is called. This is because the Animal object dora4 goes out of scope and is destroyed. The destructor prints "Animal destructor called" to the standard output.

So, the order of the calls is:

Cat constructor
Animal constructor
Animal copy constructor
Animal assignment operator
Cat destructor
Animal destructor

*/