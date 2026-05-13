#include "CharacterTeam.h"
#include <algorithm>

// Pimpl structure definition
struct CharacterTeam::Impl {
    std::vector<Character*> members;
};

CharacterTeam::CharacterTeam() : pimpl(new Impl()), currentStrategy(nullptr) {}

CharacterTeam::~CharacterTeam() {
    for (auto c : pimpl->members) delete c;
    delete pimpl;
}

// Deep Copy Implementation using the Prototype Pattern (clone)
CharacterTeam::CharacterTeam(const CharacterTeam& other) : pimpl(new Impl()), currentStrategy(other.currentStrategy) {
    for (auto c : other.pimpl->members) {
        pimpl->members.push_back(c->clone()); 
    }
}

void CharacterTeam::addCharacter(Character* c) {
    pimpl->members.push_back(c->clone()); // Store a copy
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

CharacterTeam::Iterator CharacterTeam::begin() { return Iterator(pimpl->members.begin()); }
CharacterTeam::Iterator CharacterTeam::end() { return Iterator(pimpl->members.end()); }

// Callback Demonstration
void CharacterTeam::forEach(std::function<void(Character*)> callback) {
    for (auto c : pimpl->members) {
        callback(c); 
    }
}