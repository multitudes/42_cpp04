/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:10:58 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 12:09:52 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

/**
 * @brief WrongAnimal class
 * 
 * The virtual function makeSound() is not virtual in this class
 * This should be an example of how not to do it, because the derived class
 * WrongCat will not be able to override the function makeSound()
 */
class WrongAnimal {
	public: 
		WrongAnimal( void );
		WrongAnimal( std::string type );
		virtual ~WrongAnimal( void );
		WrongAnimal( const WrongAnimal& copy );
		WrongAnimal &operator=( const WrongAnimal& assign );

		// member functions
		std::string const getType( void ) const;
		void makeSound( void ) const;
		
		protected:
			std::string type;
};

#endif  // WRONGANIMAL_HPP_
