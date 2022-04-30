#include "Span.hpp"

int	main()
{
	std::cout << "   ------   \n";
	std::cout << "   GIVEN MAIN   \n";
	std::cout << "   ------   \n";
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "   ------   \n";
	std::cout << "   BASIC TESTS   \n";
	std::cout << "   ------   \n";
	
	{
		Span span(3);

		try
		{
			std::cout << span.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		span.addNumber(42);
		
		try
		{
			std::cout << span.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		span.addNumber(5);

		try
		{
			span.addNumber(5);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		span.addNumber(0);

		try
		{
			span.addNumber(1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
	
	std::cout << "   ------   \n";
	std::cout << "   TESTS WITH 10 000 NB   \n";
	std::cout << "   ------   \n";

	{
		Span span(TOTAL);

		span.fillArray();
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}

	return 0; 
}
