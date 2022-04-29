#pragma once
#include <iostream>
#include <limits.h>
#include <cstdlib>
#define TOTAL 10000

class Span
{
	private:
		int	_len;
		int	_pos;
		int *_nbs;

	public:
		Span(int n);
		Span(Span const &ref);
		~Span();

		// Span &operator=(Span const &ref);

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
