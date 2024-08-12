/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:16:26 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 14:14:41 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main( void )
{
	// const AAnimal* annimal = new AAnimal(); // cannot instantiate an abstract class
	const AAnimal* haraki = new Dog();
	const AAnimal* dora = new Cat();
	std::cout << haraki->getType() << " " << std::endl; std::cout << dora->getType() << " " << std::endl; dora->makeSound(); //will output the cat sound! j->makeSound();
	std::cout << "========= virtual animal.. "	<< std::endl;
	// annimal->makeSound();
	// delete annimal;
	delete haraki;
	delete dora;
	
	return 0;
}