/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:58:40 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/12 16:33:03 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

/**
 * @brief The MateriaSource class
 * 
 * The MateriaSource class is a class that stores materia. It can store up to 4
 * materia. It can learn a materia and create a new one from the type passed as
 * parameter.
 * 
 */
class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource( const MateriaSource& copy);
		MateriaSource& operator=( const MateriaSource& assign );

		// member functions as described in the interface
		void learnMateria(AMateria *materia);
		AMateria* createMateria(std::string const& type);
	
	private:
		AMateria* 	_materia[4];
		int 		_materiaCount;
};

#endif  // MATERIASOURCE_HPP_
