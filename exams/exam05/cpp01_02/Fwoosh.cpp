#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::Fwoosh(const string &n, const string &e) : ASpell(n, e) {}

Fwoosh::~Fwoosh() {}

void Fwoosh::launch(ATarget const &ref) const
{
	ref.getHitBySpell(*this);
}

ASpell *Fwoosh::clone() { return new Fwoosh(); }

string const Fwoosh::getEffects() const { return effects; }
string const Fwoosh::getName() const { return name; }
