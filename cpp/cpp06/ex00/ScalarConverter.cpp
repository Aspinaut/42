#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _str("Default") {}

ScalarConverter::ScalarConverter(std::string str) : _str(str) {}

ScalarConverter::ScalarConverter(ScalarConverter const &ref) : _str(ref.getStr()) {}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &ref)
{
	_str = ref.getStr();
	return *this;
}

ScalarConverter::~ScalarConverter() {}

std::string	ScalarConverter::getStr()	const {	return _str; }

ScalarConverter::operator char()
{
	char ret = 0;
	int	value = 0;

	std::cout << "char: ";
	try
	{
		ret = stoi(this->getStr());
	}
	catch(const std::exception& e)
	{
		std::cout << " impossible" << std::endl;
		return 0;
	}
	if (value > CHAR_MAX || value < CHAR_MIN)
	{
		std::cout << " impossible" << std::endl;
		return 0;
	}
	ret = static_cast<char>(value);
	if (std::isprint(ret))
		std::cout << ret << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	return ret;	
}

ScalarConverter::operator int()
{
	int	ret = 0;

	std::cout << "int: ";
	try
	{
		ret = stoi(this->getStr());
		std::cout << ret << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << " impossible" << std::endl;
	}
	
	return ret;
}

ScalarConverter::operator float()
{
	float	ret = 0.0;

	std::cout << "float: ";
	try
	{
		ret = stof(this->getStr());
		std::cout << ret << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << " impossible" << std::endl;
		// return nan ?
	}
	
	return ret;
}

ScalarConverter::operator double()
{
	double	ret = 0.0;

	std::cout << "double: ";
	try
	{
		ret = stod(this->getStr());
		std::cout << ret << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << " impossible" << std::endl;
	}
	
	return ret;
}
