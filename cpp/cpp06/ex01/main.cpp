#include "Data.hpp"

int main()
{
	Data	*something_compromising = new Data;
	something_compromising->tip = "This tip was provided from Mc Kinsey with love, for just a few millions bucks.";

	uintptr_t	ptr = serialize(something_compromising);
	Data		*still_smth_compromising = deserialize(ptr);

	std::cout 	<< "Something compromising before serialization: " << std::endl
				<< "  address : " << something_compromising << std::endl << "  value : " << something_compromising->tip << std::endl
				<< "	----	" << std::endl
				<< "Still something compromising after deserialization: " << std::endl
				<< "  address : " << still_smth_compromising << std::endl << "  value : " << still_smth_compromising->tip << std::endl
				<< "	----	" << std::endl
				<< "Value of ptr : " << ptr << std::endl;

	delete something_compromising;

	return 0;
}