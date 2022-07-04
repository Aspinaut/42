#pragma once
#include <iostream>
#include <string>
using namespace std;

class ATarget;

class ASpell
{
	public:
		ASpell(const string &name, const string &effects);
		~ASpell();
	
        virtual const ASpell &operator=(ASpell const &other) = 0;

		const string getName() const;
		const string getEffects() const;

		void launch(ATarget const &ref) const;

	protected:
		const string name;
		const string effects;

};
