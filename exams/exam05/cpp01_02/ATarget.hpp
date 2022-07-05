#pragma once
#include <iostream>
#include <string>
using namespace std;

class ASpell;

class ATarget
{
	public:
		ATarget(const string &type);
		virtual ~ATarget();
	
        virtual const ATarget *clone(ATarget const &ref) = 0;

		const string getType() const;

		void getHitBySpell(ASpell const &ref) const;

	protected:
		const string type;

};
