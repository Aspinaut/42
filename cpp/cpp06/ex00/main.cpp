#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please insert 1 argument..." << std::endl;
		return 1;
	}

	ScalarConverter	converter(static_cast<std::string>(argv[1]));

	{
		int i = static_cast<int>(converter);
		int j = static_cast<int>(converter);
		std::cout << "i + j = " << (i + j) << std::endl;
	}

	{
		double i = static_cast<double>(converter);
		double j = static_cast<double>(converter);
		std::cout << "i + j = " << (i + j) << std::endl;
	}

	{
		char i = static_cast<char>(converter);
		char j = static_cast<char>(converter);
		std::cout << "i + j = " << (i + j) << std::endl;
	}

	{
		float i = static_cast<float>(converter);
		float j = static_cast<float>(converter);
		std::cout << "i + j = " << (i + j) << std::endl;
	}

	return 0;
}