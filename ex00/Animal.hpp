/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:16:46 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 12:10:37 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

/**
 * @brief Animal class
 */
class Animal {
	public:
		Animal( void );
		Animal( std::string type );
		virtual ~Animal( void );
		Animal( const Animal& copy);
		Animal& operator=( const Animal& assign);

		// member functions
		std::string const getType( void ) const;
		virtual void makeSound( void ) const;
		
	protected:
		std::string type;
};

#endif  // ANIMAL_HPP_
