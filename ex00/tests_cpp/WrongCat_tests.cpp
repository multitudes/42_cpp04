/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:27:39 by lbrusa            #+#    #+#             */
/*   Updated: 2024/04/03 14:10:03 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "razorclam_tests.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include "../WrongCat.hpp"

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

	debug("=== Creating a simple WrongCat\n");
	WrongCat dora;
	debug("%s", output.str().c_str());
	
	// check if the output is as expected
	std::string expectedOutput = "WrongAnimal constructor called\nWrongCat default constructor called\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : \nWrongAnimal constructor called\nWrongCat default constructor called");

	//clear
	output.str("");

	// this is the same as creating bob previously. it will use the default constructor
	WrongCat dora2 = WrongCat();
	debug("%s", output.str().c_str());
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : \nWrongAnimal constructor called\nWrongCat constructor called");

	output.str("");

	WrongCat dora3 = WrongCat();
	debug("%s", output.str().c_str());
	debug("---------");
	// check if the output is as expected
	expectedOutput = "WrongAnimal constructor called\nWrongCat default constructor called\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : \nWrongAnimal constructor called\nWrongCat default constructor called");

	expectedOutput = "WrongCat";
	debug("WrongAnimal type %s", dora3.getType().c_str());
	my_assert(strcmp(dora3.getType().c_str(), expectedOutput.c_str()) == 0, "should be : WrongCat");

	output.str("");

	WrongAnimal dora4 = WrongCat();

	debug("WrongAnimal dora4 = WrongCat(); -->> %s", output.str().c_str());
	expectedOutput = "WrongAnimal constructor called\n"
	"WrongCat default constructor called\n"
	"WrongAnimal copy constructor called\n"
	"WrongAnimal assignment operator called\n"
	"WrongCat destructor called\n"
	"WrongAnimal destructor called\n"
	"WrongAnimal type was WrongCat\n";
		debug("---------");
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : \nWrongAnimal constructor called\nWrongCat constructor called");

	debug("---------");

	output.str("");
	
	expectedOutput = "WrongCat";
	debug("WrongAnimal type %s", dora4.getType().c_str());
	my_assert(strcmp(dora4.getType().c_str(), expectedOutput.c_str()) == 0, "should be : WrongCat");

	/*
	This line restores the original buffer of std::cout, 
	undoing the redirection to output.
	*/
	// std::cout.rdbuf(oldCoutBuffer);
	return NULL;
}

// the WrongAnimals are destructed in reverse order of their creation - 
// I get the stream from the output of the previous test and can see 
// the order of the destructors
const char *test_destructors(){

	debug("=== Testing the destructors\n");
	debug("%s", output.str().c_str());	

	std::string expectedOutput = "WrongAnimal destructor called\n"
								"WrongAnimal type was WrongCat\n"
								"WrongCat destructor called\n"
								"WrongAnimal destructor called\n"
								"WrongAnimal type was WrongCat\n"
								"WrongCat destructor called\n"
								"WrongAnimal destructor called\n"
								"WrongAnimal type was WrongCat\n"
								"WrongCat destructor called\n"
								"WrongAnimal destructor called\n"
								"WrongAnimal type was WrongCat\n";
	
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be :");	
	output.str("");

	return NULL;
}


// I will create a WrongCat with a pointer and on the stack and check if the sounds are correct
const char *test_sounds() {
	debug("=== Testing the sounds\n");

	WrongCat dora = WrongCat();
	output.str("");

	dora.makeSound();
	debug("%s", output.str().c_str());
	std::string expectedOutput = "Meow meow\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : Meow meow\n");

	output.str("");

	WrongAnimal dora2 = WrongCat();
	output.str("");
	// here the polimorphism will not work because it is not a pointer... so it will call WrongAnimal::makeSound
	dora2.makeSound();
	debug("WrongAnimal WrongCat dora says: %s", output.str().c_str());
	// polymorphism doesnt work here!
	expectedOutput = "WrongAnimal sound\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : WrongAnimal sound\n");

	output.str("");

	// need a pointer to get the polymorphic behavior
	WrongAnimal* doraPTR = new WrongCat();
	output.str("");
	doraPTR->makeSound();  // Calls WrongCat::makeSound()
	debug("WrongAnimal WrongCat doraPTR says: %s", output.str().c_str());
	expectedOutput = "WrongAnimal sound\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : WrongAnimal sound\n\n");

	output.str("");	

	delete doraPTR;  // Don't forget to delete dora when you're done with it
	debug("WrongAnimal WrongCat doraPTR being destroyed: %s", output.str().c_str());
	expectedOutput = "WrongCat destructor called\n"
					"WrongAnimal destructor called\n"
					"WrongAnimal type was WrongCat\n";
	my_assert(strcmp(output.str().c_str(), expectedOutput.c_str()) == 0, "should be : WrongCat destructor called\nWrongAnimal destructor called\nWrongAnimal type was WrongCat\n");
	
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
	run_test(test_sounds);

	std::cout.rdbuf(oldCoutBuffer);
	return NULL;
}


// works as a main
RUN_TESTS(all_tests);


/*
More about the sequense of constructors and destructors:
When you write WrongAnimal dora4 = WrongCat();, the following sequence of calls occurs:

The WrongCat constructor is called, which in turn calls the WrongAnimal constructor with the argument "WrongCat". This is because WrongCat is derived from WrongAnimal and the WrongCat constructor initializes the WrongAnimal part of the WrongCat object.

The WrongAnimal constructor is called with the argument "WrongCat". This constructor prints "WrongAnimal constructor called" to the standard output.

The copy constructor of WrongAnimal is called. This is because the WrongCat object is being used to initialize an WrongAnimal object. The copy constructor is responsible for creating a new WrongAnimal object based on the WrongCat object. In this case, the copy constructor prints "WrongAnimal copy constructor called" to the standard output.

The assignment operator of WrongAnimal is called. This is because the WrongAnimal object dora4 is being assigned the value of the WrongAnimal object created in the previous step. The assignment operator is responsible for copying the values from one WrongAnimal object to another. In this case, the assignment operator prints "WrongAnimal assignment operator called" to the standard output.

The WrongCat destructor is called. This is because the temporary WrongCat object created in the first step is destroyed. The destructor prints "WrongCat destructor called" to the standard output.

The WrongAnimal destructor is called. This is because the WrongAnimal object dora4 goes out of scope and is destroyed. The destructor prints "WrongAnimal destructor called" to the standard output.

So, the order of the calls is:

WrongCat constructor
WrongAnimal constructor
WrongAnimal copy constructor
WrongAnimal assignment operator
WrongCat destructor
WrongAnimal destructor

*/