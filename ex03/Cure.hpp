/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:31:31 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/12 16:31:06 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

/**
 * @brief The Cure class
 * 
 * The Cure class is a derived class from AMateria. It represents a materia of type Cure.
 * it reimplements the use method. It has to have an implementation for the clone method.
 */
class Cure : public AMateria {
	public: 
		Cure();
		Cure(const Cure &src);
		~Cure();
		Cure &operator=(const Cure &assign);

		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif  // CURE_HPP_
