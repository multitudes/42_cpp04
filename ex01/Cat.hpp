/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:30:25 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/14 10:16:36 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

/**
 * @brief Cat class
 */
class Cat : public Animal {
	public:
		Cat( void );
		~Cat( void );
		Cat( const Cat& copy);
		Cat &operator=( const Cat& assign);

		void makeSound( void ) const;
		void setIdea( int index, std::string idea );
		std::string const getIdea( int index ) const;
		
	private:
		Brain *brain;
};



#endif  // CAT_HPP_
