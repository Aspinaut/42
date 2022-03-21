/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:32:40 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/21 10:36:12 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type) : _type(type) 
{
}


Weapon::~Weapon() {}

// std::string const &Weapon::getType() const
// {
// 	std::string const &typeRef = _type;
// 	return typeRef;
// 	// return this->_type;
// }

std::string const &Weapon::getType() const
{
	return this->_type;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}