#pragma once
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#define TOTAL 10000

class Span
{
	private:
		unsigned int		_len;
		unsigned int		_pos;
		std::vector<int> 	_nbs;

	public:
		Span(unsigned int n);
		Span(Span const &ref);
		~Span();

		Span &operator=(Span const &ref);

		void	addNumber(int nb);
		int		shortestSpan();
		int		longestSpan();
		void	fillArray();

		class NumberAlreadyUsed : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error : number is already used");
				}	
		};

		class ArrayIsFull : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error : array is full");
				}	
		};

		class TooFewNumbers : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error : array doesn't contain enough numbers");
				}	
		};
};
