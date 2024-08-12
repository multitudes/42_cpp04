/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:31:00 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/12 16:19:11 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"
#include <string>

// forward declaration
class AMateria;

/**
 * @brief The ICharacter class / interface
 * 
 * The class ICharacter is an interface and does not need a constructor. Interfaces in C++ are classes with only pure virtual functions, and they are not meant to be instantiated directly.

 */
class ICharacter {
	public:
		// virtual destructor
		virtual ~ICharacter( void ) {}
		
		// pure virtual functions
		virtual std::string const &getName( void ) const = 0;
		virtual void equip( AMateria* m ) = 0;
		virtual void unequip( int idx ) = 0;
		virtual void use( int idx, ICharacter& target ) = 0;
};

#endif  // ICHARACTER_HPP_
