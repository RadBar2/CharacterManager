#include "Character.h"
#include <iostream>

// Constructor calls the base class constructor first
DPSCharacter::DPSCharacter(std::string n, int l, double stats, double cr, double cd)
    : Character(n, l, stats), critRate(cr), critDamage(cd) {}

// Prototype Pattern implementation
Character* DPSCharacter::clone() const {
    return new DPSCharacter(*this);
}

// Polymorphic contribution logic
double DPSCharacter::computeContribution() const {
    return baseStats * (1.0 + (critRate * critDamage));
}

// Specific method for dynamic_cast targets
void DPSCharacter::unleashUltimate() const {
    std::cout << name << " performs an Ultimate Burst for massive damage!" << std::endl;
}