/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:16:26 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/11 13:57:35 by lbrusa           ###   ########.fr       */
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

	const int arraySize = 10;
	Animal *animals[arraySize];

	for (int i = 0; i < arraySize;i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < arraySize; i++)
	{
		delete animals[i];
	}
	std::cout << "=========  "	<< std::endl;
	// test deep copies
	Cat *cat = new Cat();
	cat->setIdea(0, "I am a cat");
	Cat cat2 = *cat;
	delete cat;
	std::cout << cat2.getIdea(0) << std::endl;
	return 0;
}