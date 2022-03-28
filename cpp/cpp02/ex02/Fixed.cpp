/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:09:05 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/28 10:22:52 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) {}

Fixed::Fixed( const int rawInt ) : _fixed(rawInt << _width) {}

Fixed::Fixed( const float rawFloat ) : _fixed((int)roundf(rawFloat * (1 << _width))) {}

Fixed::Fixed( const Fixed &f ) { *this = f; }

Fixed::~Fixed() {}

Fixed &Fixed::operator=( const Fixed &f )
{
	this->_fixed = f.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const { return this->_fixed; }

void Fixed::setRawBits( int const raw ) { this->_fixed = raw; }

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

bool Fixed::operator<( const Fixed &f ) const { return f._fixed > this->_fixed; }

bool Fixed::operator>( const Fixed &f ) const { return f._fixed < this->_fixed; }

bool Fixed::operator>=( const Fixed &f ) const { return f._fixed <= this->_fixed; }

bool Fixed::operator<=( const Fixed &f ) const { return f._fixed >= this->_fixed; }

bool Fixed::operator==( const Fixed &f ) const { return f._fixed == this->_fixed; }

bool Fixed::operator!=( const Fixed &f ) const { return f._fixed != this->_fixed; }

int	Fixed::operator+( const Fixed &f ) const { return this->toInt() + f.toInt(); }

int	Fixed::operator-( const Fixed &f ) const { return this->toInt() - f.toInt(); }

int	Fixed::operator*( const Fixed &f ) const { return this->toInt() * f.toInt(); }

int	Fixed::operator/( const Fixed &f ) const { return this->toInt() / f.toInt(); }

Fixed &Fixed::operator++()
{
	this->_fixed++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed f = *this;
	this->_fixed++;
	return f;
}

Fixed &Fixed::operator--()
{
	this->_fixed--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed f = *this;
	this->_fixed--;
	return f;
}

const Fixed &Fixed::min( const Fixed &f1, const Fixed &f2 ) { return (f1 < f2) ? f1 : f2; };

const Fixed &Fixed::max( const Fixed &f1, const Fixed &f2 ) { return (f1 > f2) ? f1 : f2; };

const Fixed &Fixed::min( Fixed &f1, Fixed &f2 ) { return (f1 < f2) ? f1 : f2; };

const Fixed &Fixed::max( Fixed &f1, Fixed &f2 ) { return (f1 > f2) ? f1 : f2; };
