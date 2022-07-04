#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	public:
		Fwoosh(const string &name, const string &effects);
		~Fwoosh();
	
        virtual const Fwoosh &operator=(Fwoosh const &other) = 0;

		const string getName() const;
		const string getEffects() const;

		void launch(ATarget const &ref) const;

	protected:
		const string name;
		const string effects;

};
