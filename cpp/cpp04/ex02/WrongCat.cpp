/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:02:00 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 12:23:21 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called." << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(WrongCat const &ref) : WrongAnimal()
{
	std::cout << "WrongCat copy constructor called." << std::endl;
	this->setType(ref.getType());
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called." << std::endl; }

WrongCat	&WrongCat::operator=(WrongCat const &ref)
{
	std::cout << "WrongCat copy assignment called." << std::endl;
	this->setType(ref.getType());
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meeeeeoooooow ?" << std::endl;
}