/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:02:00 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 12:23:21 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called." << std::endl;
	this->setType("Cat");
	this->_brain = new Brain();
}

Cat::Cat(Cat const &ref) : Animal()
{
	std::cout << "Cat copy constructor called." << std::endl;
	this->setType(ref.getType());
	this->_brain = ref._brain;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete this->_brain;
}

void	Cat::setBrain(Brain *Brain)
{
	this->_brain = Brain;
}

Brain *Cat::getBrain() const
{
	return this->_brain;
}

Cat	&Cat::operator=(Cat const &ref)
{
	std::cout << "Cat copy assignment called." << std::endl;
	this->setType(ref.getType());
	this->_brain = ref._brain;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meeeeeoooooow ?" << std::endl;
}