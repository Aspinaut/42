/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:59:08 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/15 07:49:58 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "------------------ GIVEN MAIN ------------------" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	
	std::cout << std::endl;
	std::cout << "--------- TESTING COPY CONSTRUCTOR AND OPERATOR = -------" << std::endl;
	std::cout << std::endl;

	Dog dog;
	Dog dog2(dog);

	dog2.makeSound();
	dog2.setType("Cat");
	std::cout << dog2.getType() << std::endl;
	dog2 = dog;
	std::cout << dog2.getType() << std::endl;
	
	std::cout << std::endl;
	std::cout << "------------------ REPLACE ANIMAL AND CAT -------------------" << std::endl;
	std::cout << std::endl;

	const WrongAnimal* metaB = new WrongAnimal();
	const WrongAnimal* iB = new WrongCat();
	std::cout << iB->getType() << " " << std::endl;
	iB->makeSound(); //will output the cat sound!
	metaB->makeSound();

	delete metaB;
	delete iB;

	return 0;
}