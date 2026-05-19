#include "CharacterTeam.h"
#include <algorithm>
#include <vector> 

struct CharacterTeam::Impl {
    std::vector<Character*> members;
};

// --- CharacterTeam implementation ---

CharacterTeam::CharacterTeam() : pimpl(new Impl()), currentStrategy(nullptr) {}

CharacterTeam::~CharacterTeam() {
    for (auto c : pimpl->members) delete c;
    delete pimpl;
}

// Deep Copy constructor
CharacterTeam::CharacterTeam(const CharacterTeam& other) 
    : pimpl(new Impl()), currentStrategy(other.currentStrategy) {
    for (auto c : other.pimpl->members) {
        pimpl->members.push_back(c->clone()); 
    }
}

// Assignment operator
CharacterTeam& CharacterTeam::operator=(const CharacterTeam& other) {
    if (this != &other) {
        // 1. Išvalome seną atmintį
        for (auto c : pimpl->members) delete c;
        pimpl->members.clear();

        // 2. Nukopijuojame naujus duomenis
        currentStrategy = other.currentStrategy;
        for (auto c : other.pimpl->members) {
            pimpl->members.push_back(c->clone());
        }
    }
    return *this;
}

// Add character to the team
void CharacterTeam::addCharacter(Character* c) {
    if (c) {
        pimpl->members.push_back(c); // Perimame pointerį tiesiogiai, klonuoti nereikia, jei kviečiantysis perduoda naują objektą
    }
}

// Remove character by name
void CharacterTeam::removeCharacter(const std::string& name) {
    auto it = std::remove_if(pimpl->members.begin(), pimpl->members.end(),
        [&name](Character* c) {
            if (c && c->getName() == name) {
                delete c;
                return true;
            }
            return false;
        });
    pimpl->members.erase(it, pimpl->members.end());
}

void CharacterTeam::setStrategy(TeamEvaluationStrategy* strategy) {
    currentStrategy = strategy; 
}

double CharacterTeam::performEvaluation() const {
    if (!currentStrategy) {
        throw StrategyNotSet(); 
    }
    return currentStrategy->calculate(pimpl->members); 
}

void CharacterTeam::forEach(std::function<void(Character*)> callback) {
    for (auto c : pimpl->members) {
        callback(c); 
    }
}

// --- Custom Iterator Implementation ---
CharacterTeam::Iterator CharacterTeam::begin() { 
    return Iterator(pimpl->members.empty() ? nullptr : &pimpl->members[0]); 
}

CharacterTeam::Iterator CharacterTeam::end() { 
    return Iterator(pimpl->members.empty() ? nullptr : &pimpl->members[0] + pimpl->members.size()); 
}

CharacterTeam::Iterator::Iterator(Character** p) : ptr(p) {}

CharacterTeam::Iterator::reference CharacterTeam::Iterator::operator*() { 
    return *ptr; 
}

CharacterTeam::Iterator& CharacterTeam::Iterator::operator++() { 
    ++ptr; 
    return *this; 
}

bool CharacterTeam::Iterator::operator!=(const Iterator& other) const { 
    return ptr != other.ptr; 
}

bool CharacterTeam::Iterator::operator==(const Iterator& other) const { 
    return ptr == other.ptr; 
}