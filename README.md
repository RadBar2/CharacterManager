# Character Management System Documentation
This documentation outlines the design and implementation of the Character Management System, a C++ project demonstrating advanced Object-Oriented Programming (OOP) principles and Design Patterns.

## Overview
The system is designed to manage a roster of game characters with varying roles (DPS, Sub-DPS, and Support). It utilizes a robust container system to organize these characters and evaluate their performance based on interchangeable strategies.

## UML Class Diagram
```mermaid
    classDiagram
    %% Exceptions
    class std_runtime_error { <<external>> }
    class std_logic_error { <<external>> }
    
    class StrategyNotSet {
        +StrategyNotSet()
    }
    class NotImplementedException {
        +NotImplementedException()
    }

    std_runtime_error <|-- StrategyNotSet
    std_logic_error <|-- NotImplementedException

    %% Character Hierarchy
    class Character {
        <<abstract>>
        #string name
        #int level
        #double baseStats
        +clone()* Character
        +computeContribution()* double
        +performSpecialAction()
    }

    class DPSCharacter {
        -double critRate
        -double critDamage
        +clone() Character
        +computeContribution() double
        +unleashUltimate()
    }

    class SubDPSCharacter {
        -double energyRecharge
        -double utilityMultiplier
        +clone() Character
        +computeContribution() double
    }

    class SupportCharacter {
        -double buffPower
        +clone() Character
        +computeContribution() double
    }

    Character <|-- DPSCharacter
    Character <|-- SubDPSCharacter
    Character <|-- SupportCharacter

    %% Strategy Pattern
    class TeamEvaluationStrategy {
        <<interface>>
        +calculate(vector characters)* double
    }

    class TotalContributionStrategy {
        +calculate(vector characters) double
    }

    class MaxContributionStrategy {
        +calculate(vector characters) double
    }

    TeamEvaluationStrategy <|-- TotalContributionStrategy
    TeamEvaluationStrategy <|-- MaxContributionStrategy

    %% CharacterTeam and Pimpl
    class CharacterTeam {
        -Impl* pimpl
        -TeamEvaluationStrategy* currentStrategy
        +addCharacter(Character* c)
        +setStrategy(TeamEvaluationStrategy* s)
        +performEvaluation() double
    }

    class Impl {
        +vector members
    }

    class Iterator {
        -vector_iterator iter
        +operator*() Character*
    }

    %% Relationships
    CharacterTeam *-- Impl : Pimpl Idiom
    CharacterTeam o-- TeamEvaluationStrategy : Uses Strategy
    CharacterTeam -- Iterator : Provides
    Impl o-- Character : Manages Clones
```

## Make options
1. **Build default target (module + demo)**
   ```bash
   make -f makefile.txt
   ```
2. **Run Demo**
   ```bash
   make -f makefile.txt run
   ```
3. **Run Test**
   ```bash
   make -f makefile.txt run-test
   ``` 
4. **Cleans Everything**
   ```bash
   make -f makefile.txt clean
   ```
5. **Rebuilds Everything**
   ```bash
   make -f makefile.txt rebuild
   ```
