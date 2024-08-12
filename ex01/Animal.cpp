/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:16:52 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 13:26:10 by lbrusa           ###   ########.fr       */
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
 */
Animal &Animal::operator=( const Animal& assign) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &assign) {
		this->type = assign.type;
	}
	return *this;
}

/**
 * @brief Get the Type object
 * 
 * @return std::string const 
 */
std::string const Animal::getType( void ) const {
	return this->type;
}

/**
 * @brief Make sound
 */
void Animal::makeSound( void ) const {
	std::cout << "---" << std::endl;
}