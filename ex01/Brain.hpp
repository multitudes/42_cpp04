/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:03:05 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 12:42:10 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

/**
 * @brief Brain class
 * 
 */
class Brain {
	public:
		Brain( void );
		~Brain( void );
		Brain( const Brain& copy );
		Brain &operator=( const Brain& assign );

		// member functions
		std::string const getIdea( int index ) const;
		void setIdea( int index, std::string idea );
		
	private:
		std::string ideas[100];
};

#endif  // BRAIN_HPP_
