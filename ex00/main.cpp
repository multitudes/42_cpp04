/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:16:26 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 11:46:59 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main( void )
{
	Animal cat = Cat();

	// const Animal* annimal = new Animal(); 
	// const Animal* haraki = new Dog();
	// const Animal* dora = new Cat();
	// std::cout << haraki->getType() << " " << std::endl; std::cout << dora->getType() << " " << std::endl; dora->makeSound(); //will output the cat sound! j->makeSound();
    // annimal->makeSound();
	
	// std::cout << "========= wrong animals.. "	<< std::endl;

	// const WrongAnimal* anniii = new WrongAnimal();
	// const WrongAnimal* dori = new WrongCat();

	// std::cout << dori->getType() << "  " << std::endl;
	// dori->makeSound();
	// anniii->makeSound();
	
	// delete annimal;
	// delete haraki;
	// delete dora;
	// delete anniii;
	// delete dori;
	return 0;
}