/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:29:35 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/12 14:07:30 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

/**
 * @brief The Node struct
 * 
 * The struct Node is a linked list node that holds an AMateria pointer 
 * and a pointer to the next node.
 * I can store only 4 Materias in the inventory, so I need to store the
 * rest of the Materias on the floor to delete them when the character is
 * destroyed.
 */
struct DiscardedMateria {
	AMateria* materia;
	DiscardedMateria* next;

	// constructor
	DiscardedMateria( AMateria* m ) : materia(m), next(NULL) {};
};


/**
 * 		Character class
 * 
 * The Character class possess an inventory of 4 Materias and a name. 
 * Copies are deep! During copy the Materias are first deleted and then cloned.
 */
class Character : public ICharacter {
	public:
		Character( std::string name );
		Character( const Character& copy );
		Character &operator=( const Character& assign );
		~Character( void );

		// member functions from the interface ICharacter
		std::string const &getName( void ) const;
		void equip( AMateria* m );
		void unequip( int idx );
		void use( int idx, ICharacter& target );

		private:
			std::string name;
			AMateria* inventory[4];
			// create a linked list to AMateria objects left on floor to delete
			// them when the character is destroyed
			DiscardedMateria* materiaOnFloor;
};

#endif  // CHARACTER_HPP_
