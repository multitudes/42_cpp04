/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:16:46 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 14:14:05 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal {
	public:
		AAnimal( void );
		AAnimal( std::string type );
		virtual ~AAnimal( void );
		AAnimal( const AAnimal& copy);
		AAnimal &operator=( const AAnimal& assign);

		// member functions
		std::string const getType( void ) const;
		virtual void makeSound( void ) const = 0;  // Pure virtual function
		
	protected:
		std::string type;
};

#endif  // AANIMAL_HPP_
