/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:10:38 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/14 10:17:02 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal {
	public:
		WrongCat( void );
		WrongCat( std::string type );
		~WrongCat( void );
		WrongCat( const WrongCat& copy );
		WrongCat &operator=( const WrongCat& assign );

		// member functions
		// wrongcat will use the sound of the parent class
		void makeSound( void ) const;
};

#endif  // WRONGCAT_HPP_
