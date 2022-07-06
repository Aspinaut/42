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
	
        virtual ATarget *clone() = 0;

		const string getType() const;

		void getHitBySpell(ASpell const &ref) const;

	protected:
		const string type;

};
