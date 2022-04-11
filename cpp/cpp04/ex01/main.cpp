/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:59:08 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/05 11:08:38 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "------------------ TESTS ------------------" << std::endl;

	const Dog* dog = new Dog();
	const Cat* cat = new Cat();

	std::cout << "Idea : " << dog->getBrain()->getIdea(100) << std::endl;
	std::cout << "Idea : " << dog->getBrain()->getIdea(0) << std::endl;
	dog->getBrain()->setIdea("I suggest you to buy a brain");
	std::cout << "Idea : " << dog->getBrain()->getIdea(0) << std::endl;

	delete dog;
	delete cat;
	
	std::cout << "------------------ ANIMAL LIST ------------------" << std::endl;

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
	// delete [] *animalist; // core dmped

	// !! DEEP / SHALLOW COPY? 

	return 0;
}