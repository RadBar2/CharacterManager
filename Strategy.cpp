#include "Strategy.h"
#include <algorithm>

// Strategy A: Calculates the sum of all polymorphic contributions [cite: 5, 56]
double TotalContributionStrategy::calculate(const std::vector<Character*>& characters) const {
    double total = 0.0;
    for (const auto* character : characters) {
        if (character) {
            total += character->computeContribution(); // Polymorphic call [cite: 33, 48]
        }
    }
    return total;
}

// Strategy B: Finds the maximum contribution among characters [cite: 57]
double MaxContributionStrategy::calculate(const std::vector<Character*>& characters) const {
    if (characters.empty()) return 0.0;
    
    double maxVal = 0.0;
    for (const auto* character : characters) {
        if (character) {
            double current = character->computeContribution(); // Polymorphic call 
            if (current > maxVal) {
                maxVal = current;
            }
        }
    }
    return maxVal;
}