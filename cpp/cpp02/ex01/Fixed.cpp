/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:09:05 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/28 08:57:00 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int rawInt ) : _fixed(rawInt << _width)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float rawFloat ) : _fixed((int)roundf(rawFloat * (1 << _width)))
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
	return this->getRawBits() >> this->_width;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->getRawBits()  / (float)(1 << this->_width));
}

std::ostream	&operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return out;
}