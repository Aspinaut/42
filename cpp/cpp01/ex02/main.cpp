/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:19:34 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/19 17:25:24 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string *sPtr = &s;
	std::string &sRef = s;

	std::cout << "Address of string : " << &s << std::endl;
	std::cout << "Address of string pointer : " << sPtr << std::endl;
	std::cout << "Address of string reference : " << &sRef << std::endl;

	std::cout << "Value of string : " << s << std::endl;
	std::cout << "Value of string pointer : " << *sPtr << std::endl;
	std::cout << "Value of string reference : " << sRef << std::endl;

	return 0;
}