/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:32:04 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/12 16:13:28 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

/**
 * @brief Default constructor
 */
Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor" << std::endl;
}

/**
 * @brief Copy constructor
 * 
 * @param src 
 */
Ice::Ice(const Ice &src) : AMateria(src) {
	std::cout << "Ice copy constructor" << std::endl;
}

/**
 * @brief Destructor
 */
Ice::~Ice() {
	std::cout << "Ice destructor" << std::endl;
}

/**
 * @brief Assignment operator
 * 
 * @param assign 
 * @return Ice& 
 */
Ice &Ice::operator=(const Ice &assign) {
	if (this != &assign) {
		std::cout << "Ice assignment operator" << std::endl;
	}
	return *this;
}

/**
 * @brief Clone function
 * 
 * @return AMateria* 
 * It is the responsibility of the caller to delete the returned pointer.
 * Cloning is the preferred way to copy a Materia.
 */
AMateria *Ice::clone() const {
	std::cout << "Ice clone" << std::endl;
	return new Ice(*this);
}

/**
 * @brief Use function
 * 
 * @param target
 * The target to use the materia on. will display: 
 * • Ice: "* shoots an ice bolt at <name> *"
 */
void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}