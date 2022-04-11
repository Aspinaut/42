/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:13:58 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/05 16:14:29 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(AMateria const &ref)
{
	this->_type = ref._type;
	return *this;
}

std::string const &AMateria::getType() const { return this->_type; }

void AMateria::setType(std::string type) { this->_type = type; }

// AMateria* AMateria::clone() const
// {
// }

void AMateria::use(ICharacter& target)
{
	if (this->getType() == "Ice")
	{
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	}
	else if (this->getType() == "Cure")
	{
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	}
}