/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:09:05 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/26 11:47:06 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) {}

Fixed::Fixed( const int rawInt ) : _fixed(rawInt << _mantissa) {}

Fixed::Fixed( const float rawFloat ) : _fixed((int)roundf(rawFloat * (1 << _mantissa))) {}

Fixed::Fixed( const Fixed &f )
{
	*this = f;
}

Fixed::~Fixed() {}

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

bool Fixed::operator<( const Fixed &f )
{
	return f._fixed > this->_fixed ? true : false;
}

bool Fixed::operator>( const Fixed &f )
{
	return f._fixed < this->_fixed ? true : false;
}

bool Fixed::operator>=( const Fixed &f )
{
	return f._fixed <= this->_fixed ? true : false;
}

bool Fixed::operator<=( const Fixed &f )
{
	return f._fixed >= this->_fixed ? true : false;
}

bool Fixed::operator==( const Fixed &f )
{
	return f._fixed == this->_fixed ? true : false;
}

bool Fixed::operator!=( const Fixed &f )
{
	return f._fixed != this->_fixed ? true : false;
}

int	Fixed::operator+( const Fixed &f )
{
	return this->toInt() + f.toInt();
}

int	Fixed::operator-( const Fixed &f )
{
	return this->toInt() - f.toInt();
}

int	Fixed::operator*( const Fixed &f )
{
	return this->toInt() * f.toInt();
}

int	Fixed::operator/( const Fixed &f )
{
	return this->toInt() / f.toInt();
}

Fixed &Fixed::operator++()
{
	// this->setRawBits(this->getRawBits() + 256);
	++(this->_fixed);
	return *this;
}

Fixed &Fixed::operator++(int)
{
	this->setRawBits(this->getRawBits() + 256);
	// this->_fixed++;
	return *this;
}

Fixed &Fixed::operator--()
{
	// this->setRawBits(this->getRawBits() + 256);
	--(this->_fixed);
	return *this;
}

Fixed &Fixed::operator--(int)
{
	// Fixed old(*this);
	// this->setRawBits(this->getRawBits() + 256);
	this->_fixed--;
	return *this;
}
