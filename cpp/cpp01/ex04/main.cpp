/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:58:20 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/24 12:52:39 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string.h>

void	strReplace(std::string *s1, std::string s2, std::string s3)
{
	std::size_t pos = s1->find(s2, 0);

	while (pos < s1->length())
	{
		s1->erase(pos, s2.length());
		s1->insert(pos, s3);
		pos += s3.length() + 1;
		pos = s1->find(s2, pos);
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Please insert 3 arguments" << std::endl;
		return 1;
	}
	std::ifstream infile(argv[1]);
	if (!infile.is_open())
	{
		std::cout << "Failed to open the infile" << std::endl;
		return (1);
	}
	std::string s1 = argv[1];
	std::string s2 = argv[2];
	std::string s3 = argv[3];
	std::ofstream outfile((s1 + ".replace").c_str());
	if (!outfile.is_open())
	{
		std::cout << "Failed to create the outfile" << std::endl;
		return (1);
	}
	std::string input;

	getline(infile, input, '\0');
	strReplace(&input, s2, s3);
	outfile << input;
	infile.close();
	outfile.close();
	return 0;
}
