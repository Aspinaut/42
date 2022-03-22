/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:58:20 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/22 12:10:05 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen 		karen;

	if (argc != 2)
	{
		std::cout << "Please insert one level of complain..." << std::endl;
		return 1;
	}

	std::string level = argv[1];
	karen.complain(level);

	return 0;
}
