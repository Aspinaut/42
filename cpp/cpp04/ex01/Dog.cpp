/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:02:00 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 12:23:21 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called." << std::endl;
	this->setType("Dog");
	this->_brain = new Brain();
}

Dog::Dog(Dog const &ref) : Animal()
{
	std::cout << "Dog copy constructor called." << std::endl;
	this->setType(ref.getType());
	this->setBrain(ref._brain);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete this->_brain;
}

void	Dog::setBrain(Brain *brain)
{
	delete this->_brain;
	this->_brain = new Brain(*brain);
}

Brain *Dog::getBrain() const
{
	return this->_brain;
}

Dog	&Dog::operator=(Dog const &ref)
{
	std::cout << "Dog copy assignment called." << std::endl;
	this->setType(ref.getType());
	this->setBrain(ref._brain);
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Wouf !" << std::endl;
}