#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const string &t) : type(t){}

ATarget::~ATarget() {}

void ATarget::getHitBySpell(ASpell const &ref) const
{
	cout << this->getType() << " has been " << ref.getEffects() << "!" << endl;
}

string const ATarget::getType() const { return type; }
