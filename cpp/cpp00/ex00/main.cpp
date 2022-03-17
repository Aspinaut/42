#include "Megaphone.hpp"

int	main(int argc, char *argv[])
{
	Megaphone mp;

	if (argc == 2)
	{
		mp.turnOn(argv[1]);
	}
	
	return 0;
}