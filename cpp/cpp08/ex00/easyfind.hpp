#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <array>

class ElementNotFound : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ( " : Not Found" );
		}
};

template < typename T >
bool	easyfind(const T &a, const int &b)
{
	if (std::find(a.begin(), a.end(), b) != a.end())
	{
		std::cout << "Found " << b << std::endl;
		return true;
	}
	else
	{
		std::cout << b;
		throw ElementNotFound();
	}
	return false;
}
