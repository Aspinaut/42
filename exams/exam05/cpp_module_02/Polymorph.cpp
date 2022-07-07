#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {}

Polymorph::Polymorph(const string &n, const string &e) : ASpell(n, e) {}

Polymorph::~Polymorph() {}

ASpell *Polymorph::clone() const { return new Polymorph(); }
