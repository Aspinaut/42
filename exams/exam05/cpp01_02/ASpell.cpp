#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(const string &n, const string &e) : name(n), effects(e) {}

ASpell::~ASpell() {}

const ASpell *ASpell::clone(ASpell const &ref)
{
	return ref; // create new object ?
}

void ASpell::launch(ATarget const &ref) const
{
	ref.getHitBySpell(*this);
}

string const ASpell::getEffects() const { return effects; }
string const ASpell::getName() const { return name; }
