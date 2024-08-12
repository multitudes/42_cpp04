/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:16:52 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/12 10:29:05 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

/**
 * @brief Construct a new AAnimal:: AAnimal object
 * 
 * Default constructor - used in the derived class
 */
AAnimal::AAnimal( void ) : type("-")
{
	std::cout << "Animal default constructor called" << std::endl;
}

/**
 * @brief Construct a new AAnimal:: AAnimal object
 * 
 * @param type 
 * Constructor with type  - used in the derived class
 */
AAnimal::AAnimal( std::string type ) : type(type) {
	std::cout << "Animal constructor called" << std::endl;
}

/**
 * @brief Destroy the AAnimal:: AAnimal object
 * 
 * Destructor - used in the derived class
 */
AAnimal::~AAnimal( void ) {
	std::cout << "Animal destructor called" << std::endl;
	std::cout << "Animal type was " << this->type << std::endl;
}

/**
 * @brief Construct a new AAnimal:: AAnimal object
 * 
 * @param copy 
 * Copy constructor - used in the derived class
 */
AAnimal::AAnimal( const AAnimal& copy) : type(copy.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

/**
 * @brief Assignment operator
 * 
 * @param assign 
 * @return AAnimal&
 * Used in the derived classes
 */
AAnimal &AAnimal::operator=( const AAnimal& assign) {
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
std::string const AAnimal::getType( void ) const {
	return this->type;
}

