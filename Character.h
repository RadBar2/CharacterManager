#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <stdexcept>

// --- Custom Exceptions ---

/**
 * Custom exception for the Strategy pattern requirement.
 */
class StrategyNotSet : public std::runtime_error {
public:
    StrategyNotSet() : std::runtime_error("Error: Team strategy has not been set.") {}
};

/**
 * Custom exception for the hierarchy requirement.
 */
class NotImplementedException : public std::logic_error {
public:
    NotImplementedException() : std::logic_error("Functionality not available for this role.") {}
};

// --- Base Class ---

class Character {
protected:
    std::string name;
    int level;
    double baseStats;

public:
    /**
     * Constructor declaration. 
     * Implementation is in Character.cpp.
     */
    Character(std::string n, int l, double stats);
    
    /**
     * Virtual destructor.
     * Set to = default here to resolve the conflict seen in image_e9d79d.png.
     */
    virtual ~Character() = default;

    // Getters
    std::string getName() const { return name; }
    int getLevel() const { return level; }
    double getBaseStats() const { return baseStats; }

    /**
     * Prototype Pattern: Pure virtual clone for polymorphic copying.
     */
    virtual Character* clone() const = 0;

    /**
     * Polymorphism: Method to show unique role contributions.
     */
    virtual double computeContribution() const = 0;

    /**
     * Dynamic cast target: Default no-op implementation.
     */
    virtual void performSpecialAction() const { /* Default no-op */ }

    // operator< for sorting
    bool operator<(const Character& other) const {
        return this->name < other.name;
    }
};

// --- Descendant Classes ---

/**
 * DPSCharacter: High damage focus.
 * Implementation of methods resides in DPSCharacter.cpp.
 */
class DPSCharacter : public Character {
private:
    double critRate;
    double critDamage;
public:
    DPSCharacter(std::string n, int l, double stats, double cr, double cd);
    Character* clone() const override;
    double computeContribution() const override;
    void unleashUltimate() const;
};

/**
 * SubDPSCharacter: Balanced damage and utility.
 * Implementation of methods resides in SubDPSCharacter.cpp.
 */
class SubDPSCharacter : public Character {
private:
    double energyRecharge;
    double utilityMultiplier;
public:
    SubDPSCharacter(std::string n, int l, double stats, double er, double util);
    Character* clone() const override;
    double computeContribution() const override;
};

/**
 * SupportCharacter: Buffing focus.
 * Implementation of methods resides in SupportCharacter.cpp.
 */
class SupportCharacter : public Character {
private:
    double buffPower;
public:
    SupportCharacter(std::string n, int l, double stats, double bp);
    Character* clone() const override;
    
    // Implementation in .cpp must throw NotImplementedException
    double computeContribution() const override;
};

#endif