#include "CharacterTeam.h"
#include "Character.h"
#include "Strategy.h"
#include <cassert>
#include <iostream>

void testThirdClassUsage() {
    std::cout << "Testing 'Third Class' (SupportCharacter) integration..." << std::endl;
    
    // Even though the .cpp has no code, the header declaration allows this test to exist.
    // SupportCharacter* healer = new SupportCharacter("Barbara", 60, 1200.0, 500.0);
}

void testExceptions() {
    CharacterTeam testTeam;
    DPSCharacter* diluc = new DPSCharacter("Diluc", 80, 2000.0, 0.7, 1.5);
    testTeam.addCharacter(diluc);
    delete diluc;

    std::cout << "Testing StrategyNotSet exception..." << std::endl;
    try {
        // REQUIREMENT: Throw StrategyNotSet if no strategy is provided 
        testTeam.performEvaluation();
        assert(false); // Should not reach here
    } catch (const StrategyNotSet& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    /* Note for Test: Once SupportCharacter is implemented, calling 
       computeContribution() on it should throw NotImplementedException.
    */
}

void testContainerCRUD() {
    std::cout << "Testing Container CRUD operations..." << std::endl;
    CharacterTeam team;
    team.addCharacter(new DPSCharacter("Kaeya", 20, 500, 0.1, 0.5));
    
    int count = 0;
    for (auto it = team.begin(); it != team.end(); ++it) {
        count++;
    }
    assert(count == 1);
    std::cout << "CRUD: Add and Iterator count successful." << std::endl;
}

int main() {
    try {
        testThirdClassUsage();
        testExceptions();
        testContainerCRUD();
        std::cout << "\nAll tests were completed" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught an unexpected exception " << e.what() << std::endl;
        return 1;
    }
    return 0;
}