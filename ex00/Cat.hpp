/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:30:25 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 11:46:15 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

/**
 * @brief Cat class
 */
class Cat : public Animal {
	public:
		Cat( void );
		~Cat( void );
		Cat( const Cat& copy);
		Cat &operator=( const Cat& assign);
		// override
		void makeSound( void ) const;
};

#endif  // CAT_HPP_
