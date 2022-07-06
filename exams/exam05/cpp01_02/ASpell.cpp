#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const string &n, const string &e) : name(n), effects(e) {}

ASpell::~ASpell() {}

void ASpell::launch(ATarget const &ref) const
{
	ref.getHitBySpell(*this);
}

string const ASpell::getEffects() const { return effects; }
string const ASpell::getName() const { return name; }
