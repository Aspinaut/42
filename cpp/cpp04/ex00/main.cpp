/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:59:08 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 14:48:50 by vmasse           ###   ########.fr       */
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
	
	std::cout << "------------------ REPLACE ANIMAL AND CAT -------------------" << std::endl;
	
	const WrongAnimal* metaB = new WrongAnimal();
	const WrongAnimal* iB = new WrongCat();
	std::cout << iB->getType() << " " << std::endl;
	iB->makeSound(); //will output the cat sound!
	metaB->makeSound();

	delete metaB;
	delete iB;

	return 0;
}