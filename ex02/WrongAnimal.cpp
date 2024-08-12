/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:10:49 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/12 10:25:11 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

/**
 * @brief Construct a new WrongAnimal::WrongAnimal object
 */
WrongAnimal::WrongAnimal( void ) : type("-")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

/**
 * @brief Construct a new WrongAnimal::WrongAnimal object
 * 
 * @param type 
 * Constructor with type
 */
WrongAnimal::WrongAnimal( std::string type ) : type(type) {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

/**
 * @brief Destroy the WrongAnimal::WrongAnimal object
 * 
 * Destructor
 */
WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called" << std::endl;
	std::cout << "WrongAnimal type was " << this->type << std::endl;
}

/**
 * @brief Construct a new WrongAnimal::WrongAnimal object
 * 
 * @param copy 
 * Copy constructor
 */
WrongAnimal::WrongAnimal( const WrongAnimal& copy ) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

/**
 * @brief Assignment operator
 */
WrongAnimal &WrongAnimal::operator=( const WrongAnimal& assign ) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &assign) {
		this->type = assign.type;
	}
	return *this;
}

/**
 * @brief Get the Type object
 * 
 * @return std::string 
 */
std::string const WrongAnimal::getType( void ) const {
	return this->type;
}

/**
 * @brief Make sound
 */
void WrongAnimal::makeSound( void ) const {
	std::cout << "WrongAnimal sound" << std::endl;
}
