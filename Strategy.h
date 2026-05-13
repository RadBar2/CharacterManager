#ifndef STRATEGY_H
#define STRATEGY_H

#include "Character.h"
#include <vector>

/**
 * Strategy Interface
 * Defines how the team's contribution is evaluated.
 */
class TeamEvaluationStrategy {
public:
    virtual ~TeamEvaluationStrategy() = default;
    
    // Pure virtual method that the container will delegate work to 
    virtual double calculate(const std::vector<Character*>& characters) const = 0;
};

/**
 * Strategy A: Total Contribution
 * Sums up the contribution of all characters in the team.
 */
class TotalContributionStrategy : public TeamEvaluationStrategy {
public:
    double calculate(const std::vector<Character*>& characters) const override;
};

/**
 * Strategy B: Max Contribution
 * Finds the single highest contribution value in the team.
 */
class MaxContributionStrategy : public TeamEvaluationStrategy {
public:
    double calculate(const std::vector<Character*>& characters) const override;
};

#endif