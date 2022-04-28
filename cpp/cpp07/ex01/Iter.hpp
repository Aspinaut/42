#pragma once
#include <iostream>

template< typename T >
void	iter( T arr[], int size, void fct( T const &elem))
{
	std::cout << "iter 1\n";
	for (int i=0; i < size; i++)
	{
		fct(arr[i]);
	}
};

// template< typename T >
// void	iter( T arr[], int size, T fct( T elem))
// {
// 	std::cout << "iter 2\n";
// 	for (int i=0; i < size; i++)
// 	{
// 		arr[i] = fct(arr[i]);
// 	}
// };
