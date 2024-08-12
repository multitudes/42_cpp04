/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:31:25 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 14:08:10 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

/**
 * @brief Construct a new Dog:: Dog object
 * 
 * Default constructor
 * The type is set to "Dog"
 */
Dog::Dog( void ) : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
	brain = new Brain();
}	

/**
 * @brief Destroy the Dog:: Dog object
 * 
 * Destructor
 */
Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
	brain = NULL;
}

/**
 * @brief Copy Constructor
 */
Dog::Dog( const Dog& copy) : Animal(copy), brain(new Brain(*copy.brain)){
	std::cout << "Dog copy constructor called" << std::endl;
}

/**
 * @brief Assignment operator
 * 
 * @param assign 
 * @return Dog& 
 */
Dog &Dog::operator=( const Dog& assign) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &assign) {
		this->type = assign.type;
		delete brain; // delete the old brain
		brain = new Brain(*assign.brain);  //  deep copy the new brain
	}
	return *this;
}

/**
 * @brief Make sound
 * 
 * Woof woof
 */
void Dog::makeSound( void ) const {
	std::cout << "Woof woof" << std::endl;
}

/**
 * @brief Set the Idea object
 * 
 * @param index 
 * @param idea 
 */
void Dog::setIdea( int index, std::string idea ) {
	if (index < 0 || index > 99)
		return ;
	this->brain->setIdea(index, idea);
}	

/**
 * @brief Get the Idea object
 * 
 * @param index 
 * @return std::string const 
 */
std::string const Dog::getIdea( int index ) const {
	if (index < 0 || index > 99)
		return ("");
	return this->brain->getIdea(index);
}