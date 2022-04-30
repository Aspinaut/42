#pragma once
#include <iostream>
#include <stack>
#include <list>

template < typename T >
class MutantStack : public std::stack< T >
{
	public:
		typedef	typename std::stack< T >::container_type	container_type;
		typedef typename container_type::iterator			iterator;
		
		MutantStack() {}
		MutantStack(MutantStack const &ref) : std::stack< T >(ref) {}
		~MutantStack() {}

		MutantStack &operator=(MutantStack const &ref)
		{
			if (this != &ref )
			{
				std::stack< T >::operator=(ref);
			}
			return *this;
		}

		iterator	begin() {
			return this->c.begin();
		}
		iterator	end() {
			return this->c.end();
		}
};
