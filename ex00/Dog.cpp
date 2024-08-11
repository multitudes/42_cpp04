/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:31:25 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 11:46:49 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

/**
 * @brief Construct a new Dog:: Dog object
 * 
 * Default constructor
 * The type is set to "Dog"
 */
Dog::Dog( void ) : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
}	

/**
 * @brief Destroy the Dog:: Dog object
 * 
 * Destructor
 */
Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
}

/**
 * @brief Copy Constructor
 */
Dog::Dog( const Dog& copy) : Animal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this=copy;
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


	