#include "Span.hpp"

Span::Span(unsigned int n) : _len(n) {}

Span::Span(Span const &ref) : _len(ref._len), _nbs(ref._nbs) {}

Span::~Span() {}

Span	&Span::operator=(Span const &ref)
{
	if (this != &ref)
	{
		_nbs = ref._nbs;
		_len = ref._len;
	}
	return *this;
}

void	Span::fillArray()
{
	int r;
	srand(time(NULL));
	for (unsigned int i=0; i < _len; i++)
	{
		try
		{
			r = rand();
			addNumber(r);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

void	Span::addNumber(int nb)
{
	if (_pos >= _len)
	{
		throw ArrayIsFull();
		return ;
	}
	if (std::find(_nbs.begin(), _nbs.end(), nb) != _nbs.end())
	{
		throw NumberAlreadyUsed();
		return ;
	}
	else
	{
		_nbs.push_back(nb);
		_pos++;
	}
}

int     Span::shortestSpan()
{
    if (_pos > 1)
    {
 	   int minSpan = *std::max_element(_nbs.begin(), _nbs.end());
		for (unsigned int i = 1; i < _len; ++i)
		{
			int tmp = std::abs(_nbs[i - 1] - _nbs[i]);
			if (tmp < minSpan)
				minSpan = tmp;
		}
		return minSpan;
    }
    throw TooFewNumbers();
}

int     Span::longestSpan()
{
    if (_pos > 1)
    {
        int min = *std::min_element(_nbs.begin(), _nbs.end());
        int max = *std::max_element(_nbs.begin(), _nbs.end());
        return max - min;
    }
    throw TooFewNumbers();
}
