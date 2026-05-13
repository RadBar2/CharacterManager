#include "Character.h"

/**
 * SubDPSCharacter Implementation
 * This class balances damage with utility/buffing capabilities.
 */

// Constructor: Uses member initializer list
SubDPSCharacter::SubDPSCharacter(std::string n, int l, double stats, double er, double util)
    : Character(n, l, stats), energyRecharge(er), utilityMultiplier(util) {}

/**
 * Prototype Pattern: Polymorphic copying.
 */
Character* SubDPSCharacter::clone() const {
    return new SubDPSCharacter(*this);
}

/**
 * Polymorphism: Second implementation of the virtual method.
 * Calculates contribution based on a balance of stats and energy recharge.
 */
double SubDPSCharacter::computeContribution() const {
    // Balance formula: (stats * utility) + (energyRecharge bonus)
    return (baseStats * utilityMultiplier) + (energyRecharge * 0.5);
}