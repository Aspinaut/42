#pragma once
#include <iostream>

template < typename T >
class Array
{
	private:
		unsigned int _len;
		T *_arr;

	public:
		Array() : _len(0), _arr(new T[0]) {};
		Array(unsigned int n) : _len(n), _arr(new T[n]) {};
		Array(Array < T > &ref) : _len(ref.size()), _arr(new T[ref.size()])
		{
			for (unsigned int i=0; i < ref.size(); i++)
			{
				this->_arr[i] = ref._arr[i];
			}
		};
		~Array() { delete [] this->_arr; };

		Array < T > &operator= (Array < T > &ref)
		{
			if (this != ref)
            {
                delete [] this->_arr;
                this->_len = ref.size;
                this->_arr = new T[ref.size()];
                for (unsigned int i=0; i < ref.size(); i++)
                    this->_arr[i] = ref[i];  
            }
            return *this; 
		};
		T&	operator[] (unsigned int i) const
        {
			if (i >= this->_len)
				throw InvalidIndex();
			return this->_arr[i];
		};

		unsigned int size() const { return this->_len; };

		class InvalidIndex : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ( "Invalid index" );
				}
		};
};
