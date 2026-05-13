#include "CharacterTeam.h"
#include "Character.h"
#include "Strategy.h"
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    // 1. Setup Container and Strategies
    CharacterTeam myTeam;
    TotalContributionStrategy totalEval;
    MaxContributionStrategy maxEval;

    // 2. Add characters to the hierarchy
    // (Ownership is handled by cloning inside addCharacter)
    DPSCharacter* diluc = new DPSCharacter("Diluc", 80, 2000.0, 0.7, 1.5);
    SubDPSCharacter* fischl = new SubDPSCharacter("Fischl", 70, 1500.0, 1.8, 0.8);
    
    myTeam.addCharacter(diluc);
    myTeam.addCharacter(fischl);

    // Clean up local pointers as the container stores its own clones
    delete diluc;
    delete fischl;

    std::cout << "--- Polymorphism Demo ---" << std::endl;
    // Polymorphism demonstration
    for (CharacterTeam::Iterator it = myTeam.begin(); it != myTeam.end(); ++it) {
        // polymorphism
        double contribution = (*it)->computeContribution(); 
        std::cout << "Character: " << (*it)->getName() << " | Contribution: " << contribution << std::endl;
    }

    std::cout << "\n--- Dynamic Cast Demo ---" << std::endl;
    // Access child-specific method via base pointer 
    for (auto it = myTeam.begin(); it != myTeam.end(); ++it) {
        DPSCharacter* dpsPtr = dynamic_cast<DPSCharacter*>(*it);
        if (dpsPtr) {
            dpsPtr->unleashUltimate();
        }
    }

    std::cout << "\n--- Strategy Pattern Demo ---" << std::endl;
    try {
        // strategy
        myTeam.setStrategy(&totalEval);
        std::cout << "Team Total Evaluation: " << myTeam.performEvaluation() << std::endl;
        
        myTeam.setStrategy(&maxEval);
        std::cout << "Team Max Evaluation: " << myTeam.performEvaluation() << std::endl;
    } catch (const StrategyNotSet& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Deep Copy Demo ---" << std::endl;
    // deep copy
    CharacterTeam clonedTeam = myTeam;
    std::cout << "Cloned team created successfully with unique memory addresses." << std::endl;

    std::cout << "\n--- Iterator & Algorithm Demo ---" << std::endl;
    // iterator
    auto it = std::find_if(myTeam.begin(), myTeam.end(), [](Character* c) {
        return c->getLevel() > 75; 
    });
    
    if (it != myTeam.end()) {
        std::cout << "Found high-level character: " << (*it)->getName() << std::endl;
    }

    std::cout << "\n--- Callback Demo ---" << std::endl;
    // callback
    myTeam.forEach([](Character* c) {
        std::cout << "Callback processing: " << c->getName() << " (Level " << c->getLevel() << ")" << std::endl;
    });

    return 0;
}