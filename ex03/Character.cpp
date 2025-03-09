/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:29:32 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/12 16:29:54 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

/**
 * @brief constructor
 * 
 * @param name
 * Loop through the inventory and set them to NULL
 * Also the DiscardedMateria is set to NULL
 */
Character::Character( std::string name ) : name(name) {
	// initialize a character with an empty inventory
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
	std::cout << "Character constructor called" << std::endl;
	// no discarded materia yet
	materiaOnFloor = NULL;
}

/**
 * @brief Destructor
 * 
 * Loop through the inventory and delete the Materia
 * Loop through the discardedMateria and delete the Materia
 */
Character::~Character( void ) {
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL) {
			delete this->inventory[i];
		}
	}
	DiscardedMateria* current = this->materiaOnFloor;
    while (current != NULL) {
        DiscardedMateria* next = current->next;
        delete current->materia;
        delete current;
        current = next;
    }
}

/**
 * @brief Copy constructor
 * 
 * @param copy 
 * 
 */
Character::Character( const Character& copy) : name(copy.name) {
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (copy.inventory[i] != NULL) {
			this->inventory[i] = copy.inventory[i]->clone();
		} else {
			this->inventory[i] = NULL;
		}
	}
	this->materiaOnFloor = NULL;
}

/**
 * @brief Assignment operator
 * 
 * @param assign 
 * @return Character& 
 */
Character &Character::operator=( const Character& assign ) {
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &assign) {
		this->name = assign.name;
		for (int i = 0; i < 4; i++) {
			if (this->inventory[i] != NULL) {
				delete this->inventory[i];
			}
			if (assign.inventory[i] != NULL) {
				this->inventory[i] = assign.inventory[i]->clone();
			} else {	
				this->inventory[i] = NULL;
			}
		}
	}
	this->materiaOnFloor = NULL;
	return *this;
}

/**
 * @brief Get the Name object
 */
std::string const & Character::getName( void ) const {
	return this->name;
}

/**
 * @brief Use the Materia
 * 
 * @param target 
 */
void Character::use( int idx, ICharacter& target ) {
	if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL) {
		this->inventory[idx]->use(target);
		delete this->inventory[idx];
		this->inventory[idx] = NULL;
	}
}

/**
 * @brief Equip the Materia
 * 
 * @param m 
 */
void Character::equip( AMateria* m ) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			break;
		}
		if (i == 3) {
			std::cout << "Inventory is full - we'll leave it on the ground." << std::endl;
			DiscardedMateria* newMateria = new DiscardedMateria(m);
			if (materiaOnFloor == NULL) {
				materiaOnFloor = newMateria;
			} else {
				newMateria->next = materiaOnFloor;
				materiaOnFloor = newMateria;
			}
		}
	}
}

/**
 * @brief Unequip the Materia
 * 
 * @param idx
 * If they try to unequip an empty slot, do nothing 
 */
void Character::unequip( int idx )
{
	if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL) {
		// Save the pointer to be deleted in the DiscardedMateria to be cleaned up later
		DiscardedMateria* newMateria = new DiscardedMateria(this->inventory[idx]);
		newMateria->next = materiaOnFloor;
		materiaOnFloor = newMateria;
		this->inventory[idx] = NULL;
	}
}

