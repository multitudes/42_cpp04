/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:16:52 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 11:47:17 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

/**
 * @brief Construct a new Animal:: Animal object
 * 
 * Default constructor
 */
Animal::Animal( void ) : type("-")
{
	std::cout << "Animal default constructor called" << std::endl;
}

/**
 * @brief Construct a new Animal:: Animal object
 * 
 * @param type 
 * Constructor with type
 */
Animal::Animal( std::string type ) : type(type) {
	(void)type;  // to avoid warning (unused parameter
	std::cout << "Animal constructor called" << std::endl;
}

/**
 * @brief Destroy the Animal:: Animal object
 * 
 * Destructor
 */
Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
	std::cout << "Animal type was " << this->type << std::endl;
}

/**
 * @brief Construct a new Animal:: Animal object
 * 
 * @param copy 
 * Copy constructor
 */
Animal::Animal( const Animal& copy) : type(copy.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

/**
 * @brief Assignment operator
 * 
 * @param assign 
 * @return Animal& 
 */
Animal &Animal::operator=( const Animal& assign) {
	std::cout << "Animal assignment operator called" << std::endl;
	// Deep copy - Animal has only one property
	if (this != &assign) {
		this->type = assign.type;
	}
	return *this;
}

/**
 * @brief Get the Type object
 */
std::string const Animal::getType( void ) const {
	return this->type;
}

/**
 * @brief Make sound
 * 
 * It is a virtual function but for now implemented as empty
 */
void Animal::makeSound( void ) const {
	std::cout << "---" << std::endl;
}