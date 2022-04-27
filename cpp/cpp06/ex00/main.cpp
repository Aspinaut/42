#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please insert 1 argument..." << std::endl;
		return 1;
	}

	ScalarConverter	converter(static_cast<std::string>(argv[1]));

	char a = static_cast<char>(converter);
	int b = static_cast<int>(converter);
	float c = static_cast<float>(converter);
	double d = static_cast<double>(converter);

	(void)a;
	(void)b;
	(void)c;
	(void)d;

	return 0;
}