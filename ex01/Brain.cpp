/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:02:45 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 13:02:15 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

/**
 * @brief Construct a new Brain:: Brain object
 */
Brain::Brain( void ) {
	std::cout << "Brain default constructor called" << std::endl;
	for (int i  = 0; i < 100; i++) {
		this->ideas[i] = "";
	}
}

/**
 * @brief Destroy the Brain:: Brain object
 */
Brain::~Brain( void ) {
	std::cout << "Brain destructor called" << std::endl;
}

/**
 * @brief Construct a new Brain:: Brain object
 * 
 * @param copy 
 * Copy constructor - Here I need to copy each element of the array
 * to avoid shallow copy . the array in the Brain is a pointer to a string
 * array and if I do a shallow copy I will have two pointers pointing to the same
 */
Brain::Brain( const Brain& copy ) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
        this->ideas[i] = copy.ideas[i];
    }
}

/**
 * @brief Assignment operator 
 * 
 * @param assign
 * @return Brain&
 * Here I need to copy each element of the array to avoid again a shallow copy
 */
Brain &Brain::operator=( const Brain& assign ) {
	std::cout << "Brain assignment operator called " << std::endl;
	if (this != &assign) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = assign.ideas[i];
		}
	}
	return *this;
}

/**
 * @brief Set the Idea object
 * 
 * @param index 
 * @param idea 
 */
void Brain::setIdea( int index, std::string idea) {
	this->ideas[index] = idea;
}

/**
 * @brief Get the Idea object
 * 
 * @param index 
 * @return std::string const 
 */
std::string const Brain::getIdea( int index ) const {
	return this->ideas[index];
}