#include "Character.h"

SubDPSCharacter::SubDPSCharacter(std::string n, int l, double stats, double er, double util)
    : Character(n, l, stats), energyRecharge(er), utilityMultiplier(util) {}

// Polymorphic copying using the Prototype Pattern
Character* SubDPSCharacter::clone() const {
    return new SubDPSCharacter(name, level, baseStats, energyRecharge, utilityMultiplier);
}

// SubDPS contribution is based on base stats multiplied by a utility multiplier
double SubDPSCharacter::computeContribution() const {
    return baseStats * utilityMultiplier;
}