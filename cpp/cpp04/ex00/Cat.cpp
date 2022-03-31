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
}

Cat::Cat(Cat const &ref) : Animal()
{
	std::cout << "Cat copy constructor called." << std::endl;
	this->setType(ref.getType());
}

Cat::~Cat() { std::cout << "Cat destructor called." << std::endl; }

Cat	&Cat::operator=(Cat const &ref)
{
	std::cout << "Cat copy assignment called." << std::endl;
	this->setType(ref.getType());
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meeeeeoooooow ?" << std::endl;
}