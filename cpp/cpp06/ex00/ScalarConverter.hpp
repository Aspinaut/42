#pragma once
#include <iostream>
#include <string>
#include <limits.h>
#include <stdlib.h>
#include <sstream>

class ScalarConverter
{
	private:
		const std::string	_str;

	public:
		ScalarConverter();
		ScalarConverter(std::string str);
		ScalarConverter(ScalarConverter const &ref);
		~ScalarConverter();

		ScalarConverter	&operator=(ScalarConverter const &ref);

		std::string	getStr() const;

		operator	int();
		operator	char();
		operator	float();
		operator	double();
};