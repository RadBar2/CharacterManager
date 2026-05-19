#include "Character.h"
#include <iostream>

// --- Custom Exceptions Implementation ---

StrategyNotSet::StrategyNotSet() 
    : std::runtime_error("Error: Team strategy has not been set.") {}

NotImplementedException::NotImplementedException() 
    : std::logic_error("Functionality not available for this role.") {}


// --- Base Class Implementation ---

Character::Character(std::string n, int l, double stats) 
    : name(n), level(l), baseStats(stats) {}

std::string Character::getName() const { 
    return name; 
}

int Character::getLevel() const { 
    return level; 
}

double Character::getBaseStats() const { 
    return baseStats; 
}

void Character::performSpecialAction() const { 
    // Default no-op 
}

bool Character::operator<(const Character& other) const {
    return this->name < other.name;
}

