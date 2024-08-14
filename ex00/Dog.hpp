/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:30:34 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/14 10:18:05 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

/**
 * @brief Dog class
 */
class Dog : public Animal {
	public:
		Dog( void );
		~Dog( void );
		Dog( const Dog& copy);
		Dog &operator=( const Dog& assign);
		
		// override
		void makeSound( void ) const;
};

#endif  // DOG_HPP_
