#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(const string &t) : type(t){}

ATarget::~ATarget() {}

const ATarget *ATarget::clone(ATarget const &ref)
{
	return *ref;
}

void ATarget::getHitBySpell(ASpell const &ref) const
{
	cout << this->getType() << " has been " << ref.getEffects() << "!" << endl;
}

string const ATarget::getType() const { return type; }
