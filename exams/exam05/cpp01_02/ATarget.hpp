#pragma once
#include <iostream>
#include <string>
using namespace std;

class ASpell;

class ATarget
{
	public:
		ATarget(const string &type);
		~ATarget();
	
        virtual const ATarget &operator=(ATarget const &other) = 0;

		const string getType() const;

		void getHitBySpell(ASpell const &ref) const;

	protected:
		const string type;

};
