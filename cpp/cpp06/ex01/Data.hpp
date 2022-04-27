#pragma once
#include <iostream>

struct Data
{
	int value;
};

uintptr_t	serialize(Data	*ptr);

Data		*deserialize(uintptr_t raw);