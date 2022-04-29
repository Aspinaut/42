#include "easyfind.hpp"

int main()
{
	// LIST
	{
		std::list<int> map1;

		map1.push_back(1);
		map1.push_back(42);
		
		std::cout << "Trying with list of int\n"; 
		try
		{
			easyfind(map1, 42);
			easyfind(map1, 43);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "   ----   \n"; 
	}

	// VECTOR
	{
		std::list<int> lst;

		lst.push_back(1);
		lst.push_back(42);
		
		std::cout << "Trying with vector of int\n"; 
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

    return 0;
}
