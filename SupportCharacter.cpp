/* * PROJECT REQUIREMENT: THE THIRD CLASS DESCRIPTION
 * This file contains the design specifications for the SupportCharacter class.
 * As per the instructions, this class remains unimplemented in this module 
 * to be completed by future developers.
 *
 * CLASS NAME: SupportCharacter
 * BASE CLASS: Character
 *
 * DESIGN SPECIFICATIONS:
 * 1. Inheritance: Must inherit publicly from the 'Character' class.
 * * 2. Attributes: 
 * - Should include a private member 'buffPower' (double) to represent 
 * the strength of support skills.
 * - Should include a private member 'healingAbility' (bool) to indicate 
 * if the character can restore health.
 *
 * 3. Constructor:
 * - Must take parameters for name, level, baseStats, buffPower, and healingAbility.
 * - Must call the base Character constructor with (name, level, baseStats).
 *
 * 4. Prototype Pattern (clone):
 * - Must implement the virtual Character* clone() method.
 * - Implementation: return new SupportCharacter(*this);
 *
 * 5. Polymorphic Method (computeContribution):
 * - REQUIREMENT: This specific implementation MUST forbid calling the method 
 * by throwing a 'NotImplementedException'[cite: 19].
 * - Rationale: Support characters in this specific version of the engine 
 * provide utility that is not yet quantifiable by the standard 
 * contribution formula used by DPS and SubDPS roles.
 */

 #include "Character.h"

SupportCharacter::SupportCharacter(std::string n, int l, double stats, double bp)
    : Character(n, l, stats), buffPower(bp) {}

Character* SupportCharacter::clone() const {
    return new SupportCharacter(*this);
}

/**
 * Implementation requirement: This specific subclass must throw 
 * NotImplementedException to demonstrate hierarchy constraints.
 */
double SupportCharacter::computeContribution() const {
    throw NotImplementedException();
}