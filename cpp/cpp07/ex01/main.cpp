#include "Iter.hpp"

template < typename T >
void	print( T const &elem)
{
	std::cout << elem << std::endl;
}

int main()
{
	int 		intArray[5] = {1, 2, 3, 4, 5};
	float 		floatArray[5] = {1.5, 2.5, 3.5, 4.5, 5.5};
	double 		doubleArray[5] = {1.5, 2.5, 3.5, 4.5, 5.5};
	bool 		boolArray[5] = {false, true, false, true, false};
	char		charArray[5] = {'h', 'e', 'l', 'l', 'o'};
	std::string strArray[3] = {"Let's ", "iterate ", "this !"};

	iter(intArray, 5, print);
	iter(floatArray, 5, print);
	iter(doubleArray, 5, print);
	iter(boolArray, 5, print);
	iter(charArray, 5, print);
	iter(strArray, 3, print);

	return 0;
}
