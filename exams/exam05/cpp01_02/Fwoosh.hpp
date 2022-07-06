#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
using namespace std;

class Fwoosh : public ASpell
{
	public:
		Fwoosh();
		Fwoosh(const string &name, const string &effects);
		~Fwoosh();
	
		virtual ASpell *clone();
};
