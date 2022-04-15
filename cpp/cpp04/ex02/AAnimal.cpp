/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:02:00 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/01 10:40:24 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Undefined")
{
	std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(AAnimal const &ref) : _type(ref.getType())
{
	std::cout << "AAnimal copy constructor called." << std::endl;
}

AAnimal::~AAnimal() { std::cout << "AAnimal destructor called." << std::endl; }

AAnimal	&AAnimal::operator=(AAnimal const &ref)
{
	std::cout << "AAnimal copy assignment called." << std::endl;
	this->setType(ref.getType());
	return *this;
}

void	AAnimal::setType(std::string type) { this->_type = type; }

std::string	AAnimal::getType() const { return this->_type; }

void	AAnimal::makeSound() const
{
	std::cout << "* undefined noise *" << std::endl;
}
