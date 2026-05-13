#ifndef CHARACTERTEAM_H
#define CHARACTERTEAM_H

#include "Character.h"
#include "Strategy.h"
#include <vector>
#include <iterator>
#include <functional>

class CharacterTeam {
private:
    // Pimpl Idiom: Hide implementation details in the .cpp file
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
    void addCharacter(Character* c); // Takes ownership or clones
    void removeCharacter(const std::string& name);

    // Strategy Pattern Methods
    void setStrategy(TeamEvaluationStrategy* strategy); // [cite: 28, 30]
    double performEvaluation() const; // [cite: 28, 29]

    // Callback functionality
    void forEach(std::function<void(Character*)> callback); // [cite: 31, 32]

    // Custom Iterator Implementation (Forward Iterator Type)
    class Iterator {
    private:
        std::vector<Character*>::iterator iter;
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = Character*;
        using difference_type = std::ptrdiff_t;
        using pointer = Character**;
        using reference = Character*&;

        Iterator(std::vector<Character*>::iterator it) : iter(it) {}
        reference operator*() { return *iter; }
        Iterator& operator++() { ++iter; return *this; }
        bool operator!=(const Iterator& other) const { return iter != other.iter; }
        bool operator==(const Iterator& other) const { return iter == other.iter; }
    };

    Iterator begin();
    Iterator end();
};

#endif