#include "easyfind.hpp"

int main()
{
	// LIST
	{
		std::list<int> lst;

		lst.push_back(1);
		lst.push_back(42);
		
		std::cout << "Trying with list of int\n"; 
		try
		{
			easyfind(lst, 42);
			easyfind(lst, 43);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "   ----   \n"; 
	}

	// VECTOR
	{
		std::vector<int> vect;

		vect.push_back(1);
		vect.push_back(42);
		
		std::cout << "Trying with vector of int\n"; 
		try
		{
			easyfind(vect, 42);
			easyfind(vect, 43);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "   ----   \n"; 
	}

	// ARRAY
	{
		std::array<int, 2> arr = {1, 42};

		std::cout << "Trying with array of int\n"; 
		try
		{
			easyfind(arr, 42);
			easyfind(arr, 43);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "   ----   \n"; 
	}

	// LIST OF CHAR
	{
		std::list<char> lst;

		lst.push_back('a');
		lst.push_back('b');

		std::cout << "Trying with list of chars\n"; 
		try
		{
			easyfind(lst, 'a');
			easyfind(lst, 43);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "   ----   \n"; 
	}

    return 0;
}
