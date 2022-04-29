#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <vector>

class ElementNotFound : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ( " : Not Found" );
		}
};

// template < typename T >
// bool	easyfind(const T &a, const int &b)
// {
// 	typename T::const_iterator	it;
// 	typename T::const_iterator	ite = a.end();

// 	for (it = a.begin(); it != ite; ++it)
// 	{
// 		if (*it == b)
// 		{
// 			std::cout << "found " << *it << std::endl;
// 			return true;
// 		}
// 	}
// 	std::cout << 43;
// 	throw ElementNotFound();
// 	return false;
// }


template < typename T >
bool	easyfind(const T &a, const int &b)
{
	if (std::find(a.begin(), a.end(), b) != a.end())
		std::cout << "found\n";
	else
	{
		std::cout << b;
		throw ElementNotFound();
	}
	return false;
}
