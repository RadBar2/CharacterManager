#include "Character.h"

/**
 * Constructor for the base Character class.
 * Initializes common attributes shared by all descendants in the hierarchy[cite: 11].
 */
Character::Character(std::string n, int l, double stats) 
    : name(n), level(l), baseStats(stats) {}

