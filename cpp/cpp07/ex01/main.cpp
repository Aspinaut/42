#include "Iter.hpp"

// template < typename T >
// void	increment( T &elem)
// {
// 	std::cout << "inc 1\n";
// 	elem++;
// }

// // template < typename T >
// // T	increment( T elem)
// // {
// // 	std::cout << "inc 2\n";
// // 	try
// // 	{
// // 		elem++;
// // 	}
// // 	catch(const std::exception& e)
// // 	{
// // 		std::cerr << e.what() << '\n';
// // 	}
	
// // 	return elem;
// // }

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

// class Awesome
// {
// public:
// Awesome( void ) : _n( 42 ) { return; }
// int get( void ) const { return this->_n; }
// private:
// int _n;
// };
// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
// template< typename T >
// void print( T const & x ) { std::cout << x << std::endl; return; }
// int main() {
// int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
// Awesome tab2[5];
// iter( tab, 5, print );
// iter( tab2, 5, print );
// return 0;
// }