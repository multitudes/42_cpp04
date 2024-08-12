/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:30:34 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 13:37:04 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

/**
 * @brief Dog class
 */
class Dog : public Animal {
	public:
		Dog( void );
		~Dog( void );
		Dog( const Dog& copy);
		Dog &operator=( const Dog& assign);

		void makeSound( void ) const;
		void setIdea( int index, std::string idea );
		std::string const getIdea( int index ) const;
		
	private:
		std::string type;
		Brain *brain;
};

#endif  // DOG_HPP_
