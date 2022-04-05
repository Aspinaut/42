/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:02:00 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/01 10:40:24 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Undefined")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(Animal const &ref) : _type(ref.getType())
{
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal() { std::cout << "Animal destructor called." << std::endl; }

Animal	&Animal::operator=(Animal const &ref)
{
	std::cout << "Animal copy assignment called." << std::endl;
	this->setType(ref.getType());
	return *this;
}

void	Animal::setType(std::string type) { this->_type = type; }

std::string	Animal::getType() const { return this->_type; }

void	Animal::makeSound() const
{
	std::cout << "* undefined noise *" << std::endl;
}
