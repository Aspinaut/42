/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:51:52 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/26 08:26:29 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public:

		Fixed();
		Fixed( Fixed &f );
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		Fixed &operator=( Fixed &f );
		
	private:

		int	_fixed;
		static const int _rawBits = 8;
};

#endif