#include "Array.hpp"
#include <cstdlib>
#define MAX_VAL 750

int main()
{
	// GIVEN MAIN
    {
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}

	// CUSTOM 
	{
		Array<std::string> strArr(2);
		Array<char> charArr(2);
		Array<bool> boolArr(2);
		Array<float> floatArr(1);
		Array<double> doubleArr(1);
		Array<double> emptyArr;
		Array<Array< int > > intArrOfArr;

		strArr[0] = "ceci est une string";
		strArr[1] = "ceci est une autre string";
		boolArr[0] = true;
		boolArr[1] = false;
		floatArr[0] = 4.2;
		doubleArr[0] = 4.2;

		std::cout << strArr[0] << std::endl;
		std::cout << strArr[1] << std::endl;
		try
		{
			std::cout << strArr[2] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << boolArr[0] << std::endl;
		std::cout << boolArr[1] << std::endl;
		std::cout << floatArr[0] << std::endl;
		std::cout << doubleArr[0] << std::endl;
		std::cout << "Address of emptyArr : " << &emptyArr << std::endl;
		std::cout << "Address of intArrOfArr : " << &intArrOfArr << std::endl;
	}
    return 0;
}
