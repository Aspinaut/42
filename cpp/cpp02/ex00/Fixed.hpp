/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:51:52 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/26 09:25:08 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public:

		Fixed();
		Fixed( const Fixed &f );
		~Fixed();

		Fixed &operator=( const Fixed &f );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		
	private:

		int	_fixed;
		static const int _mantissa = 8;
};

#endif