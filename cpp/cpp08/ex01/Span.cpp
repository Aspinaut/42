#include "Span.hpp"

Span::Span(int n) : _len(n), _nbs( new int[n] ) {}

Span::Span(Span const &ref) : _len(ref._len), _nbs( new int[ref._len] ) {}

Span::~Span() { delete [] this->_nbs; }

// Span &Span::operator=(Span const &ref)
// {
// 	// if (this != ref)
// 	// {

// 	// }
// }

void Span::fillArray()
{
	srand(time(NULL));
	for (int i=0; i < this->_len; i++)
	{
		try
		{
			this->addNumber(rand());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

void Span::addNumber(int nb)
{
	if (this->_pos >= this->_len)
	{
		throw ArrayIsFull();
		return ;
	}
	for (int i=0; i < this->_pos; i++)
	{
		if (this->_nbs[i] == nb)
		{
			throw NumberAlreadyUsed();
			return ;
		}
	}
	this->_nbs[this->_pos++] = nb;
}

int	Span::shortestSpan()
{
	int minSpan = INT_MAX;
	int last;
	int currentSpan;

	if (this->_pos < 2)
	{
		throw TooFewNumbers();
		return 0;
	}
	for (int i=0; i < this->_pos; i++)
	{
		last = this->_nbs[i];
		for (int j=0; j < this->_pos; j++)
		{
			currentSpan = last - this->_nbs[j];
			if (currentSpan < 0)
				currentSpan *= -1;
			if (i != j && currentSpan < minSpan)
			{
				minSpan = currentSpan;
			}
		}
	}
	return minSpan;
}

int	Span::longestSpan()
{
	int maxSpan = INT_MIN;
	int last;
	int currentSpan;

	if (this->_pos < 2)
	{
		throw TooFewNumbers();
		return 0;
	}
	for (int i=0; i < this->_pos; i++)
	{
		last = this->_nbs[i];
		for (int j=0; j < this->_pos; j++)
		{
			currentSpan = last - this->_nbs[j];
			if (currentSpan < 0)
				currentSpan *= -1;
			if (i != j && currentSpan > maxSpan)
			{
				maxSpan = currentSpan;
			}
		}
	}
	return maxSpan;
}
