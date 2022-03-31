/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:02:00 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 13:42:14 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Undefined")
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &ref) : type(ref.getType())
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called." << std::endl; }

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &ref)
{
	std::cout << "WrongAnimal copy assignment called." << std::endl;
	this->setType(ref.getType());
	return *this;
}

void	WrongAnimal::setType(std::string type) { this->type = type; }

std::string	WrongAnimal::getType() const { return this->type; }

void	WrongAnimal::makeSound() const
{
	std::cout << "* undefined noise *" << std::endl;
}
