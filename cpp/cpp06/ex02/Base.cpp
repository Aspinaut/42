#include "Base.hpp"

Base::~Base() {}

Base*	generate()
{
	Base *newBase;
	srand(time(NULL));
	int randNb = rand() % 3 + 1;
		
	if (randNb == 1)
	{
		newBase = new A();
		std::cout << "A has been created" << std::endl;
	}
	else if (randNb == 2)
	{
		newBase = new B();
		std::cout << "B has been created" << std::endl;
	}
	else
	{
		newBase = new C();
		std::cout << "C has been created" << std::endl;
	
	}

	return newBase;
}

void	identify(Base* p)
{
	A	*a = dynamic_cast<A*>(p);
	B	*b = dynamic_cast<B*>(p);
	C	*c = dynamic_cast<C*>(p);

	if (a)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	if (b)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	if (c)
	{
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "Cannot identify this Base" << std::endl;
}

void	identify(Base& p)
{
	Base cast;

	try
	{
		cast = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception &e) {}

	try
	{
		cast = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception &e) {}

	try
	{
		cast = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception &e) {}

	std::cout << "Cannot identify this Base" << std::endl;
}
