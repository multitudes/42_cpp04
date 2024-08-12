/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:31:05 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/12 16:31:26 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

/**
 * @brief Construct a new Cure::Cure object
 */
Cure::Cure() : AMateria("cure") {
	std::cout << "Cure default constructor" << std::endl;
}

/**
 * @brief Construct a new Cure::Cure object
 * 
 * @param src 
 * Copy constructor
 */
Cure::Cure(const Cure &src) : AMateria(src) {
	std::cout << "Cure copy constructor" << std::endl;
	*this = src;
}

/**
 * @brief Destroy the Cure::Cure object
 */
Cure::~Cure() {
	std::cout << "Cure destructor" << std::endl;
}

/**
 * @brief Assignment operator
 * 
 * @param assign 
 * @return Cure&
 * Cure assignment operator - used in the derived class
 * copying the type doesnt make sense because it is the same for all instances
 */
Cure& Cure::operator=(const Cure &assign) {
	if (this != &assign) {
		std::cout << "Cure assignment operator" << std::endl;
	}
	return *this;
}

/**
 * @brief Clone the Cure
 * 
 * @return AMateria*
 * Cure clone - preferred method to copy a Materia
 */
AMateria *Cure::clone() const {
	std::cout << "Cure clone" << std::endl;
	return new Cure(*this);
}

/**
 * @brief Use the Cure
 * 
 * @param target
 * The target to use the materia on. will display: 
 * • Cure: "* heals <name>'s wounds *"
 */
void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}