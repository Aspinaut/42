/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:58:20 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/21 18:14:01 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main()
{
	Karen karen;
	// std::string level;

	// std::cout << "Type an option : " << std::endl;
	// while (getline(std::cin, level))
	// {
	// 	karen.complain(level);
	// }
	karen.complain("DEBUG");
	karen.complain("INFO");
	karen.complain("WARNING");
	karen.complain("ERROR");
	return 0;
}