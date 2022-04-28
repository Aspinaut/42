#include "Iter.hpp"

template < typename T >
void	increment( T &elem)
{
	std::cout << "inc 1\n";
	elem++;
}

// template < typename T >
// T	increment( T elem)
// {
// 	std::cout << "inc 2\n";
// 	try
// 	{
// 		elem++;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
	
// 	return elem;
// }

int main()
{
	int 		intArray[5] = {1, 2, 3, 4, 5};
	float 		floatArray[5] = {1.5, 2.5, 3.5, 4.5, 5.5};
	double 		doubleArray[5] = {1.5, 2.5, 3.5, 4.5, 5.5};
	// bool 		boolArray[5] = {true, true, true, true, true};
	char		charArray[5] = {'h', 'e', 'l', 'l', 'o'};
	// std::string strArray[3] = {"Let's ", "iterate ", "this !"};

	iter(intArray, 5, increment);
	for (int i=0; i < 5; i++)
		std::cout << intArray[i];
	std::cout << std::endl;

	iter(floatArray, 5, increment);
	for (int i=0; i < 5; i++)
		std::cout << floatArray[i];
	std::cout << std::endl;

	iter(doubleArray, 5, increment);
	for (int i=0; i < 5; i++)
		std::cout << doubleArray[i];
	std::cout << std::endl;

	// iter(boolArray, 5, increment);
	// for (int i=0; i < 5; i++)
	// 	std::cout << boolArray[i];
	// std::cout << std::endl;

	iter(charArray, 5, increment);
	for (int i=0; i < 5; i++)
		std::cout << charArray[i];
	std::cout << std::endl;

	// iter(strArray, 3, increment);
	// for (int i=0; i < 3; i++)
	// 	std::cout << strArray[i] << std::endl;
	// std::cout << std::endl;

	return 0;
}
