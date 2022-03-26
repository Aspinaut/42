/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:09:05 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/26 09:51:36 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int rawInt ) : _fixed(rawInt << _mantissa)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float rawFloat ) : _fixed((int)roundf(rawFloat * (1 << _mantissa)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &f )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=( const Fixed &f )
{
	std::cout << "Copy assignment operator called" << std::endl;
	// nécessaire de check si f est la meme instance ?
	this->_fixed = f.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return this->_fixed;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
}

int Fixed::toInt( void ) const
{
	return (int)roundf((float)this->_fixed / (1 << this->_mantissa));
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_fixed  / (1 << this->_mantissa));
}

std::ostream	&operator<<(std::ostream &o, const Fixed &f)
{
	o << f.toFloat();
	return o;
}