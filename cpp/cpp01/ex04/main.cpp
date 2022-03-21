/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:58:20 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/21 16:39:02 by vmasse           ###   ########.fr       */
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
		pos++;
		pos = s1->find(s2, pos);
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return 1;
	std::ifstream infile(argv[1]);
	char *rawOutfile = strdup(argv[1]);
	strcat(rawOutfile, ".replace");
	std::ofstream outfile(rawOutfile);
	std::string s2 = argv[2];
	std::string s3 = argv[3];
	std::string input;
	
	getline(infile, input, '\0');
	strReplace(&input, s2, s3);
	outfile << input;
	infile.close();
	outfile.close();
	return 0;
}