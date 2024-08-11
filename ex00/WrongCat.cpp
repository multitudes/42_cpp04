/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:11:06 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 12:10:23 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat( std::string type ) : WrongAnimal( type ) {
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& copy ) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=( const WrongCat& assign ) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &assign) {
		this->type = assign.type;
	}
	return *this;
}

/*
In C++, if you want a method in a base class to be overridable by 
methods in derived classes, you need to declare it as virtual in 
the base class. This tells the compiler to perform dynamic 
dispatch when the method is called on an object of the base class 
type, meaning it will look at the actual type of the object at 
runtime to determine which method to call.
*/
void WrongCat::makeSound( void ) const {
	std::cout << "Meow meow" << std::endl;
}