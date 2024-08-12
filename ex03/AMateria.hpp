/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:08:36 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/12 16:19:27 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>

// forward declaration
class ICharacter;

/**
 * @brief The AMateria class
 * 
 * The AMateria class is an abstract class that represents a materia.
 * Abstract classes cannot be instantiated directly, but they can be used as base classes.
 */
class AMateria {
	public:
		AMateria( std::string const &type );
		virtual ~AMateria( void );
		AMateria( const AMateria& copy);
		AMateria &operator=( const AMateria& assign);
		
		// member functions
		std::string const &getType( void ) const; // returns the materia type
		
		virtual AMateria* clone( void ) const = 0;
		virtual void use( ICharacter& target );

	protected:
		std::string type;
};

#endif  // AMATERIA_HPP_
