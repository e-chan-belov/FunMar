#pragma once

#include <string>
#include <variant>
#include "FunMarList.hpp"

class Word : public std::string { 
public:
    using std::string::string; 
    Word(const std::string& str) : std::string(str) {}
};

namespace std { // костыль
    template <>
    struct hash<Word> {
        size_t operator()(const Word& w) const {
            return hash<std::string>()(w);
        }
    };
}

class Variable : public std::string { 
public:
    using std::string::string; 
    Variable(const std::string& str) : std::string(str) {}
};

namespace std { // костыль
    template <>
    struct hash<Variable> {
        size_t operator()(const Variable& w) const {
            return hash<std::string>()(w);
        }
    };
}

class Abstraction : public FunMarList<std::variant<Word, Variable>> {
public:
    using FunMarList<std::variant<Word, Variable>>::FunMarList;
    Abstraction(const FunMarList<std::variant<Word, Variable>>& list) : FunMarList(list) {}
    Abstraction(FunMarList<std::variant<Word, Variable>>&& list) : FunMarList(std::move(list)) {}

    bool isRealized() { return head->next == nullptr && std::holds_alternative<Word>(head->value); }
    Word getRealization() { return std::get<Word>(head->value); }

    class Iterator {
    protected:
        FunMarList<std::variant<Word, Variable>>::Iterator previous;
        FunMarList<std::variant<Word, Variable>>::Iterator current;
    public:
        Iterator(FunMarListNode<std::variant<Word, Variable>>* head_ = nullptr) : previous(nullptr), current(head_) {}

        bool isAtList() const {return current.isAtList(); }
        bool hasNext() const { return current.hasNext(); }
        void next() { previous = current; current.next(); }

        bool isWord() const { return std::holds_alternative<Word>(current.getValue());}
        bool isVariable() const { return std::holds_alternative<Variable>(current.getValue());}

        Word& getWord() { return std::get<Word>(current.getValue()); }
        const Word& getWord() const { return std::get<Word>(current.getValue()); }

        Variable& getVariable() { return std::get<Variable>(current.getValue()); }
        const Variable& getVariable() const { return std::get<Variable>(current.getValue()); }

        void realize(Word result) { current.getValue() = result; }
        void merge();
    };

    Iterator begin() { return Iterator(head); }
    const Iterator begin() const { return Iterator(head); }

    std::string getStringRepresentation() const;
};

class AbstractionGenerator : public FunMarListGenerator<std::variant<Word, Variable>> {
public:
    using FunMarListGenerator<std::variant<Word, Variable>>::FunMarListGenerator;

    Abstraction generate() { return FunMarListGenerator<std::variant<Word, Variable>>::generate(); }
};

