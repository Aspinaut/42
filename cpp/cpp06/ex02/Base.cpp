#include "Base.hpp"

Base::~Base() {	std::cout << "Base deconstructor" << std::endl;	}

Base*	generate()
{
	Base *newBase;
	srand(time(NULL));
	int	val = rand() % 10;
		
	if (val < 4)
	{
		newBase = new A();
		std::cout << "A has been generated" << std::endl;
	}
	else if (val < 7)
	{
		newBase = new B();
		std::cout << "B has been generated" << std::endl;
	}
	else
	{
		newBase = new C();
		std::cout << "C has been generated" << std::endl;
	
	}
	return newBase;
}

void	identify(Base* p)
{
	A*	a = dynamic_cast<A*>(p);
	B*	b = dynamic_cast<B*>(p);
	C*	c = dynamic_cast<C*>(p);

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
	std::cout << "--- Impossible to identify this base ---" << std::endl;
}

void	identify(Base& p)
{
	Base cast;

	try
	{
		cast = dynamic_cast<A&>(p);
		std::cout << "A\n";	return ;
	}
	catch(std::exception &bc)
	{

	}
	try
	{
		cast = dynamic_cast<B&>(p);
		std::cout << "B\n";	return ;
	}
	catch(std::exception &bc)
	{

	}
	try
	{
		cast = dynamic_cast<C&>(p);
		std::cout << "C\n";	return ;
	}
	catch(std::exception &bc)
	{
		
	}
	std::cout << "--- Impossible to identify this base ---" << std::endl;
}