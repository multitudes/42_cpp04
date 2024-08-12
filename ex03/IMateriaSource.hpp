/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:30:23 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/12 16:31:55 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"
#include <string>

/**
 * @brief The IMateriaSource class / interface
 * 
 * The IMateriaSource class is a interface. learnMateria and createMateria are 
 * pure virtual functions. The first copies and store the materia in memory so
 * it can be cloned later. It can store 4 materia.  
 * The second returns a new materia, a copy of the mateeria learnes in the MateriaSource
 * from the type passed as parameter. Returns 0 if the type is not found.
 * 
 */
class IMateriaSource {
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif  // IMATERIASOURCE_HPP_