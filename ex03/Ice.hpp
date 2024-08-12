/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:31:13 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/12 16:31:36 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

/**
 * @brief The Ice class
 */
class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &src);
		~Ice();
		Ice &operator=(const Ice &assign);

		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif  // ICE_HPP_
