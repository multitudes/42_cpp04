/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:08:10 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/12 15:52:30 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

/**
 * @brief Constructor
 */
AMateria::AMateria( std::string const & type ) : type(type) {
	std::cout << "AMateria constructor called" << std::endl;
}

/**
 * @brief Destructor
 */
AMateria::~AMateria( void ) {
	std::cout << "AMateria destructor called" << std::endl;
}

/**
 * @brief copy constructor
 * 
 * For AMateria, the copy constructor is not used
 */
AMateria::AMateria( const AMateria& copy ) : type(copy.type) {
	std::cout << "AMateria copy constructor called" << std::endl;
}

/**
 * @brief Assignment operator
 */
AMateria &AMateria::operator=( const AMateria& assign ) {
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &assign) {
		this->type = assign.type;
	}
	return *this;
}

/**
 * @brief getType
 * 
 * @return std::string const&
 */
std::string const & AMateria::getType( void ) const {
	return this->type;
}

/**
 * @brief use
 * 
 * @param target 
 */
void AMateria::use( ICharacter& target ) {
	std::cout << "AMateria use called" << std::endl;
	(void)target;
}