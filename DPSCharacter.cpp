#include "Character.h"
#include <iostream>

DPSCharacter::DPSCharacter(std::string n, int l, double stats, double cr, double cd)
    : Character(n, l, stats), critRate(cr), critDamage(cd) {}

// Polymorphic copying using the Prototype Pattern
Character* DPSCharacter::clone() const {
    return new DPSCharacter(name, level, baseStats, critRate, critDamage);
}

// DPS contribution is calculated based on base stats and critical hit potential
double DPSCharacter::computeContribution() const {
    return baseStats * (1.0 + (critRate * critDamage));
}

// Unique method for DPS characters
void DPSCharacter::unleashUltimate() const {
    std::cout << name << " performs an Ultimate Burst for massive damage!" << std::endl;
}