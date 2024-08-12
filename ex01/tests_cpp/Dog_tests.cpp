/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:27:39 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 12:56:28 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "razorclam_tests.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include "../Dog.hpp"

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

	debug("=== Creating a simple Dog\n");
	Dog dora;
	debug("%s", output.str().c_str());
	
	// check if the output is as expected
	std::string expectedOutput = "Animal constructor called\n"
								"Dog constructor called\n"
								"Brain default constructor called\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : \nAnimal constructor called\nDog constructor called\nBrain default constructor called\n");

	//clear
	output.str("");

	// this is the same as creating dora previously. it will use the default constructor
	Dog dora2 = Dog();
	debug("%s", output.str().c_str());
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : \nAnimal constructor called\nDog constructor called");

	output.str("");

	Dog dora3 = Dog();
	debug("%s", output.str().c_str());
	debug("---------");
	// check if the output is as expected
	expectedOutput = "Animal constructor called\n"
					"Dog constructor called\n"
					"Brain default constructor called\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : \nAnimal constructor called\nDog constructor called\nBrain default constructor called\n");

	expectedOutput = "Dog";
	debug("animal type %s", dora3.getType().c_str());
	my_assert(strcmp(dora3.getType().c_str(), expectedOutput.c_str()) == 0, "should be : Dog");

	output.str("");

	Animal dora4 = Dog();

	debug("Animal dora4 = Dog(); -->> %s", output.str().c_str());
	expectedOutput = "Animal constructor called\n"
	"Dog constructor called\n"
	"Brain default constructor called\n"
	"Animal copy constructor called\n"
	"Dog destructor called\n"
	"Brain destructor called\n"
	"Animal destructor called\n"
	"Animal type was Dog\n";
		debug("---------");
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : ...");

	debug("---------");

	output.str("");
	
	expectedOutput = "Dog";
	debug("animal type %s", dora4.getType().c_str());
	my_assert(strcmp(dora4.getType().c_str(), expectedOutput.c_str()) == 0, "should be : Dog");

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

	std::string expectedOutput = "Animal destructor called\n"
								"Animal type was Dog\n"
								"Dog destructor called\n"
								"Brain destructor called\n"
								"Animal destructor called\n"
								"Animal type was Dog\n"
								"Dog destructor called\n"
								"Brain destructor called\n"
								"Animal destructor called\n"
								"Animal type was Dog\n"
								"Dog destructor called\n"
								"Brain destructor called\n"
								"Animal destructor called\n"
								"Animal type was Dog\n";
	
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be :");	
	output.str("");

	return NULL;
}


// I will create a Dog with a pointer and on the stack and check if the sounds are correct
const char *test_sounds() {
	debug("=== Testing the sounds\n");

	Dog dora = Dog();
	output.str("");

	dora.makeSound();
	debug("%s", output.str().c_str());
	std::string expectedOutput = "Woof woof\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : Meow meow\n");

	output.str("");

	Animal dora2 = Dog();
	output.str("");
	// here the polimorphism will not work because it is not a pointer... so it will call animal::makeSound
	dora2.makeSound();
	debug("Animal Dog dora says: %s", output.str().c_str());
	// polymorphism doesnt work here!
	expectedOutput = "---\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : ---\n");

	output.str("");

	// need a pointer to get the polymorphic behavior
	Animal* doraPTR = new Dog();
	output.str("");
	debug("Animal Dog doraPTR says: %s", output.str().c_str());
	doraPTR->makeSound();  // Calls Dog::makeSound()
	expectedOutput = "Woof woof\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : Meow meow\n");

	output.str("");	

	delete doraPTR;  // Don't forget to delete dora when you're done with it
	debug("Animal Dog doraPTR being destroyed: %s", output.str().c_str());
	expectedOutput = "Dog destructor called\n"
					"Brain destructor called\n"
					"Animal destructor called\n"
					"Animal type was Dog\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : Dog destructor called\nAnimal destructor called\nAnimal type was Dog\n");
	
	output.str("");

	return NULL;
}

const char *test_ideas()
{
	debug("=== Testing the ideas\n");

	Dog fido = Dog();
	output.str("");	

	fido.setIdea(0, "I am a dog");
	debug("idea: %s", fido.getIdea(0).c_str());
	std::string expectedOutput = "I am a dog";
	my_assert(strcmp(fido.getIdea(0).c_str(), expectedOutput.c_str()) == 0, "should be : I am a dog");

	output.str("");

	Dog fluffy = fido;
	my_assert(strcmp(fluffy.getIdea(0).c_str(), expectedOutput.c_str()) == 0, "should be : I am a dog");
	
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
	run_test(test_ideas);

	std::cout.rdbuf(oldCoutBuffer);
	return NULL;
}


// works as a main
RUN_TESTS(all_tests);


/*
More about the sequense of constructors and destructors:
When you write Animal dora4 = Dog();, the following sequence of calls occurs:

The Dog constructor is called, which in turn calls the Animal constructor with the argument "Dog". This is because Dog is derived from Animal and the Dog constructor initializes the Animal part of the Dog object.

The Animal constructor is called with the argument "Dog". This constructor prints "Animal constructor called" to the standard output.

The copy constructor of Animal is called. This is because the Dog object is being used to initialize an Animal object. The copy constructor is responsible for creating a new Animal object based on the Dog object. In this case, the copy constructor prints "Animal copy constructor called" to the standard output.

The assignment operator of Animal is called. This is because the Animal object dora4 is being assigned the value of the Animal object created in the previous step. The assignment operator is responsible for copying the values from one Animal object to another. In this case, the assignment operator prints "Animal assignment operator called" to the standard output.

The Dog destructor is called. This is because the temporary Dog object created in the first step is destroyed. The destructor prints "Dog destructor called" to the standard output.

The Animal destructor is called. This is because the Animal object dora4 goes out of scope and is destroyed. The destructor prints "Animal destructor called" to the standard output.

So, the order of the calls is:

Dog constructor
Animal constructor
Animal copy constructor
Animal assignment operator
Dog destructor
Animal destructor

*/