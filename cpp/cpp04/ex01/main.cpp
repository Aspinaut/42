/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:59:08 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/15 14:56:42 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "------------------ TESTS ------------------" << std::endl;
	std::cout << std::endl;

	const Dog* dog = new Dog();
	const Cat* cat = new Cat();

	std::cout << "Idea : " << dog->getBrain()->getIdea(100) << std::endl;
	std::cout << "Idea : " << dog->getBrain()->getIdea(0) << std::endl;
	dog->getBrain()->setIdea("I suggest you to get a brain");
	std::cout << "Idea : " << dog->getBrain()->getIdea(0) << std::endl;

	delete dog;
	delete cat;
	
	std::cout << std::endl;
	std::cout << "------------------ BRAIN TEST ------------------" << std::endl;
	std::cout << std::endl;

	Dog *doggo = new Dog();
	Brain *brain = new Brain();
	Brain *brain2 = brain;

	brain->fillIdeas();
	std::cout << brain->getIdea(0) << std::endl;
	doggo->setBrain(brain);
	std::cout << doggo->getBrain()->getIdea(0) << std::endl;
	doggo->setBrain(brain2);
	std::cout << doggo->getBrain()->getIdea(0) << std::endl;
	
	delete doggo;
	delete brain;

	std::cout << std::endl;
	std::cout << "------------------ ANIMAL LIST ------------------" << std::endl;
	std::cout << std::endl;

	const Animal *animalist[20];
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

	return 0;
}