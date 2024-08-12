/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:30:21 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 14:07:08 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/**
 * @brief Construct a new Cat:: Cat object
 * 
 * In this exercise the cat has a brain. The brain is a class that has 100 ideas.
 * The cat owns the brain and it is responsible for its life cycle.
 */
Cat::Cat( void ) : AAnimal("Cat") {
	std::cout << "Cat constructor called" << std::endl;
	brain = new Brain();
}

/**
 * @brief Destroy the Cat:: Cat object
 * 
 * Destructor - make sure to clean up the memory allocated for the brain
 */
Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
	brain = NULL;
}

/**
 * @brief Copy Constructor
 * 
 * @param copy 
 * Copy constructor - in the initializer list we call the copy constructor 
 * of the brain object so we do a deep copy of the brain if the brain class
 * has a proper copy constructor
 */
Cat::Cat( const Cat& copy) : AAnimal(copy), brain(new Brain(*copy.brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

/**
 * @brief Assignment operator
 * 
 * @param assign
 */
Cat &Cat::operator=( const Cat& assign) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &assign) {
		this->type = assign.type;
		delete this->brain;	// delete the old brain
		this->brain = new Brain(*assign.brain);  //  deep copy the new brain
	}
	return *this;
}

/**
 * @brief Make sound
 * 
 * Meow meow
 */
void Cat::makeSound( void ) const {
	std::cout << "Meow meow" << std::endl;
}

/**
 * @brief Set the Idea object
 * 
 * @param index 
 * @param idea 
 */
void Cat::setIdea( int index, std::string idea ) {
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
std::string const Cat::getIdea( int index ) const {
	if (index < 0 || index > 99)
		return ("");
	return this->brain->getIdea(index);
}