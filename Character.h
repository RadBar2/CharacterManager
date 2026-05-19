#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <stdexcept>

// --- Custom Exceptions ---

class StrategyNotSet : public std::runtime_error {
public:
    StrategyNotSet();
};

class NotImplementedException : public std::logic_error {
public:
    NotImplementedException();
};

// --- Base Class ---

class Character {
protected:
    std::string name;
    int level;
    double baseStats;

public:
    Character(std::string n, int l, double stats);
    virtual ~Character() = default; // Virtual destructor for proper cleanup of derived classes

    // Disable copy semantics to enforce unique ownership and prevent slicing
    Character(const Character& other) = delete;
    Character& operator=(const Character& other) = delete;

    // Getters
    std::string getName() const;
    int getLevel() const;
    double getBaseStats() const;

    // Prototype Pattern
    virtual Character* clone() const = 0;

    // Polymorphism
    virtual double computeContribution() const = 0;

    // Dynamic cast target
    virtual void performSpecialAction() const;

    // operator< for sorting
    bool operator<(const Character& other) const;
};

// --- Descendant Classes ---

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

class SubDPSCharacter : public Character {
private:
    double energyRecharge;
    double utilityMultiplier;
public:
    SubDPSCharacter(std::string n, int l, double stats, double er, double util);
    Character* clone() const override;
    double computeContribution() const override;
};

class SupportCharacter : public Character {
private:
    double buffPower;
public:
    SupportCharacter(std::string n, int l, double stats, double bp);
    Character* clone() const override;
    double computeContribution() const override;
};

#endif