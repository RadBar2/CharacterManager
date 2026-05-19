#ifndef CHARACTERTEAM_H
#define CHARACTERTEAM_H

#include "Character.h"
#include "Strategy.h"
#include <iterator>
#include <functional>

class CharacterTeam {
private:
    struct Impl;
    Impl* pimpl;
    TeamEvaluationStrategy* currentStrategy;

public:
    CharacterTeam();
    ~CharacterTeam();

    // Deep Copy & Assignment
    CharacterTeam(const CharacterTeam& other);
    CharacterTeam& operator=(const CharacterTeam& other);

    // CRUD Operations
    void addCharacter(Character* c); 
    void removeCharacter(const std::string& name);

    // Strategy Pattern Methods
    void setStrategy(TeamEvaluationStrategy* strategy); 
    double performEvaluation() const; 

    // Callback functionality
    void forEach(std::function<void(Character*)> callback); 

    // Custom Iterator
    class Iterator {
    private:
        Character** ptr;
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = Character*;
        using difference_type = std::ptrdiff_t;
        using pointer = Character**;
        using reference = Character*&;

        Iterator(Character** p);
        reference operator*();
        Iterator& operator++();
        bool operator!=(const Iterator& other) const;
        bool operator==(const Iterator& other) const;
    };

    Iterator begin();
    Iterator end();
};

#endif