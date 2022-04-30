#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;

		std::cout << "   ----   \n";
		std::cout << "GIVEN MAIN\n";
		std::cout << "   ----   \n";
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << "   ----   \n";
	}

	{
		std::list<int> mstack;

		std::cout << "LIST COMPARISON\n";
		std::cout << "   ----   \n";
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
		std::cout << "   ----   \n";	
	}

	{
		MutantStack<std::string> mstack;

		std::cout << "COMPLEX TYPE TEST\n";
		std::cout << "   ----   \n";
		mstack.push("You see...");
		mstack.push("... I can be iterated as well !");
		{
			MutantStack<std::string>::iterator it = mstack.begin();
			MutantStack<std::string>::iterator ite = mstack.end();
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
			std::cout << "   ----   \n";
		}

		std::cout << "COPY CONSTRUCTOR & ASSIGNMENT\n";
		std::cout << "   ----   \n";

		MutantStack<std::string> s(mstack);
		s.push("I am born from a copy constructor :)");
		{
			MutantStack<std::string>::iterator it = s.begin();
			MutantStack<std::string>::iterator ite = s.end();
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
			std::cout << "   ----   \n";
		}

		MutantStack<std::string> mstack_cpy = mstack;
		s.pop();
		s.push("I am born from assignment :)");
		{
			MutantStack<std::string>::iterator it = s.begin();
			MutantStack<std::string>::iterator ite = s.end();
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
		}
		std::cout << "   ----   \n";
	}

	return 0;
}