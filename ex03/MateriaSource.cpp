/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:00:36 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/12 16:32:30 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

/**
 * @brief Construct a new MateriaSource:: MateriaSource object
 * 
 * Default constructor
 * At first the MateriaSource is empty, so the _materiaCount is set to 0
 * MaterialSource can store up to 4 Materia, so the array _materia is initialized
 */
MateriaSource::MateriaSource() {
	std::cout << "MateriaSource constructor called" << std::endl;
	this->_materiaCount = 0;
	for (int i = 0; i < 4; i++) {
		this->_materia[i] = 0;
	}
}

/**
 * @brief Destructor
 * 
 * Destructor
 * Loop through the MateriaSource array and delete the Materia
 */
MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < this->_materiaCount; i++) {
		delete this->_materia[i];
	}
}

/**
 * @brief Copy constructor
 * 
 * @param copy 
 * Copy constructor
 */
MateriaSource::MateriaSource(const MateriaSource& copy) : _materiaCount(copy._materiaCount) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < _materiaCount; i++) {
		if (copy._materia[i] != 0) {
			this->_materia[i] = copy._materia[i]->clone();
		} else {
			this->_materia[i] = 0;
		}
	}
}

/**
 * @brief Assignment operator
 * 
 * @param assign 
 * @return MateriaSource&
 * Assignment operator - a bit more compleicated because it is a deep copy
 * so I need to delete the old Materia if any and create the new ones
 */
MateriaSource& MateriaSource::operator=(const MateriaSource& assign) {
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &assign) {
		for (int i = 0; i < this->_materiaCount; i++) {
			delete this->_materia[i];
		}
		this->_materiaCount = assign._materiaCount;
		for (int i = 0; i < 4; i++) {
			if (assign._materia[i] != 0) {
				this->_materia[i] = assign._materia[i]->clone();
			} else {
				this->_materia[i] = 0;
			}
		}
	}
	return *this;
}

/**
 * @brief Learn a new Materia
 * 
 * @param AMateria* materia
 * Learn a new Materia and store it in the MateriaSource but only if there is
 * space - otherwise do nothing
 */
void MateriaSource::learnMateria(AMateria* materia) {
	if (materia != 0 && this->_materiaCount < 4) {
		this->_materia[this->_materiaCount] = materia;
		this->_materiaCount++;
	}	
}

/**
 * @brief Create a new Materia
 * 
 * Returns a pointer to a new Materia, a copy of one Materia previously learned
 * by the MateriaSource of the type passed as parameter. Returns 0 if the Materia
 * is unknown. Therefore I am looping through the MateriaSource array and checking
 * if the type of the Materia is the same as the type passed as parameter and then return
 * a clone of the Materia. Otherwise I return 0.
 */
AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < this->_materiaCount; i++) {
		if (this->_materia[i]->getType() == type) {
			return this->_materia[i]->clone();
		}
	}
	return 0;
}
