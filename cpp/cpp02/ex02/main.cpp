/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:58:20 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/26 11:45:34 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed z(1);
	Fixed y(2);

	std::cout << "Is z < y ? " << (z < y) << std::endl;
	std::cout << "Is z > y ? " << (z > y) << std::endl;
	std::cout << "Is z >= y ? " << (z >= y) << std::endl;
	std::cout << "Is z <= y ? " << (z <= y) << std::endl;
	std::cout << "Is z != y ? " << (z != y) << std::endl;
	std::cout << "Is z == y ? " << (z == y) << std::endl;
	
	std::cout << "z + y = " << (z + y) << std::endl;
	std::cout << "z - y = " << (z - y) << std::endl;
	std::cout << "z * y = " << (z * y) << std::endl;
	std::cout << "z / y = " << (z / y) << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "++z = " << ++z << std::endl;
	std::cout << "z++ = " << z++ << std::endl;
	std::cout << "z = " << z << std::endl;
	// std::cout << "z++ = " << z++ << std::endl;
	// std::cout << "--z = " << --z << std::endl;
	// std::cout << "z-- = " << z-- << std::endl;
	
	
	return 0;
}

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	// std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }