/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:59:08 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/15 15:10:13 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "------------------ TESTS ------------------" << std::endl;

	const Dog* dog = new Dog();
	const Cat* cat = new Cat();

	dog->getBrain()->fillIdeas();
	std::cout << "Idea : " << dog->getBrain()->getIdea(-1) << std::endl;
	std::cout << "Idea : " << dog->getBrain()->getIdea(99) << std::endl;
	
	delete dog;
	delete cat;
	
	std::cout << "------------------ ANIMAL LIST ------------------" << std::endl;

	const AAnimal *animalist[20];
	for (int i=0; i < 20; i++)
	{
		if (i % 2 == 0)
			animalist[i] = new Cat();
		else
			animalist[i] = new Dog();
	}
	
	for (int i=0; i < 20; i++)
	{
		delete animalist[i];
	}

	// std::cout << "------------------ NOT SUPPOSED TO COMPILE ------------------" << std::endl;
	// const AAnimal *dogo = new AAnimal();
	// (void)dogo;
	
	return 0;
}