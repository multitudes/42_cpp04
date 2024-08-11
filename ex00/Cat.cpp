/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:30:21 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 11:46:37 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/**
 * @brief Construct a new Cat:: Cat object
 * 
 * Default constructor
 * The type is set to "Cat". we use only the default constructor of the parent class
 * Animal in this example
 */
Cat::Cat( void ) : Animal("Cat") {
	std::cout << "Cat constructor called" << std::endl;
}

/**
 * @brief Destroy the Cat:: Cat object
 * 
 * Destructor
 */
Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
}

/**
 * @brief Copy Constructor
 */
Cat::Cat( const Cat& copy): Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this=copy;
}

/**
 * @brief Assignment operator
 * 
 * @param assign 
 * @return Cat& 
 */
Cat &Cat::operator=( const Cat& assign) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &assign) {
		this->type = assign.type;
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