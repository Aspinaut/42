/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:51:52 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/28 10:57:54 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	public:

		Fixed();
		Fixed( const int rawInt );
		Fixed( const float rawFloat );
		Fixed( const Fixed &f );
		~Fixed();
		
		Fixed &operator=( const Fixed &f );
		bool operator<( const Fixed &f ) const;
		bool operator>( const Fixed &f ) const;
		bool operator>=( const Fixed &f ) const;
		bool operator<=( const Fixed &f ) const;
		bool operator==( const Fixed &f ) const;
		bool operator!=( const Fixed &f ) const;

		Fixed operator+( const Fixed &f ) const;
		Fixed operator-( const Fixed &f ) const;
		Fixed operator*( const Fixed &f ) const;
		Fixed operator/( const Fixed &f ) const;
		
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static const Fixed &min( const Fixed &f1, const Fixed &f2 );
		static const Fixed &max( const Fixed &f1, const Fixed &f2 );
		static Fixed &min( Fixed &f1, Fixed &f2 );
		static Fixed &max( Fixed &f1, Fixed &f2 );
 
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		int toInt( void ) const;
		float toFloat( void ) const;

	private:

		int	_fixed;
		static const int _width = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &f);

#endif
