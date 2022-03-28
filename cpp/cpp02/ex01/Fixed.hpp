/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:51:52 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/28 08:48:07 by vmasse           ###   ########.fr       */
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