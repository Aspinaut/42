#include "Data.hpp"

int main()
{
	Data		*something_compromising;
	uintptr_t	hidden_data;

	something_compromising->secret = "This tip was provided from Mc Kinsey with love, for just a few millions bucks";
	hidden_data = serialize(something_compromising);
	std::cout << something_compromising->secret << std::endl;
	something_compromising = deserialize(hidden_data);
	std::cout << something_compromising->secret << std::endl;

	delete something_compromising;

	return 0;
}