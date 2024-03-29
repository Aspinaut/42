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
}

Dog::Dog(Dog const &ref) : Animal()
{
	std::cout << "Dog copy constructor called." << std::endl;
	this->setType(ref.getType());
}

Dog::~Dog() { std::cout << "Dog destructor called." << std::endl; }

Dog	&Dog::operator=(Dog const &ref)
{
	std::cout << "Dog copy assignment called." << std::endl;
	this->setType(ref.getType());
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Wouf !" << std::endl;
}