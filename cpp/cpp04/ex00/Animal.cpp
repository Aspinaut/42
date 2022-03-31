/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:02:00 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 12:30:53 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Undefined")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(Animal const &ref) : type(ref.getType())
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

void	Animal::setType(std::string type) { this->type = type; }

std::string	Animal::getType() { return this->type; }