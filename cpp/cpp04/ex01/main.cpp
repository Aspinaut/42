/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:59:08 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/01 11:14:33 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "------------------ GIVEN MAIN ------------------" << std::endl;

	// pourquoi ça ne fonctionne pas ?? (pas d'accès aux fonctions de Dog et Cat)
	// const Animal* dog = new Dog();
	// const Animal* cat = new Cat();

	const Dog* dog = new Dog();
	const Cat* cat = new Cat();

	dog->getBrain()->fillIdeas();
	std::cout << "Idea : " << dog->getBrain()->getIdea(100) << std::endl;

	delete dog;
	delete cat;

	return 0;
}