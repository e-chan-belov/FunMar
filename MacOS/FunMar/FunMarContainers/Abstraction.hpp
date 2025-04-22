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
    Abstraction(FunMarList<std::variant<Word, Variable>>&& list) noexcept : FunMarList(std::move(list)) {}

    bool isRealized() { return head != nullptr && head->next == nullptr && std::holds_alternative<Word>(head->getValue()); }
    Word& getRealization() { return std::get<Word>(head->getValue()); }
    const Word& getRealization() const { return std::get<Word>(head->getValue()); }

    class ObserverIterator {
    protected:
        FunMarList<std::variant<Word, Variable>>::ObserverIterator previous;
        FunMarList<std::variant<Word, Variable>>::ObserverIterator current;
    public:
        ObserverIterator(FunMarListNode<std::variant<Word, Variable>>* head_ = nullptr) : previous(nullptr), current(head_) {}
        ObserverIterator(const ObserverIterator& iter) : previous(iter.previous), current(iter.current) {}

        ~ObserverIterator() = default;

        ObserverIterator& operator=(const ObserverIterator& iter) { if (this != &iter) { previous = iter.previous; current = iter.current; } return *this;  }

        bool isAtList() const {return current.isAtList(); }
        bool hasNext() const { return current.hasNext(); }
        void next() { previous = current; current.next(); }

        bool isWord() const { return std::holds_alternative<Word>(current.getValue());}
        bool isVariable() const { return std::holds_alternative<Variable>(current.getValue());}

        const Word& getWord() const { if (!isWord()) { throw "bad std::variant"; } return std::get<Word>(current.getValue()); }

        const Variable& getVariable() const { if (!isVariable()) { throw "bad std::variant"; } return std::get<Variable>(current.getValue()); }
    };
        
    ObserverIterator begin() const { return ObserverIterator(head); }

    class Iterator {
    protected:
        FunMarList<std::variant<Word, Variable>>::Iterator previous;
        FunMarList<std::variant<Word, Variable>>::Iterator current;
    public:
        Iterator(FunMarListNode<std::variant<Word, Variable>>* head_ = nullptr) : previous(nullptr), current(head_) {}
        Iterator(const Iterator& iter) : previous(iter.previous), current(iter.current) {}

        ~Iterator() = default;

        Iterator& operator=(const Iterator& iter) { if (this != &iter) { previous = iter.previous; current = iter.current; } return *this;  }

        bool isAtList() const {return current.isAtList(); }
        bool hasNext() const { return current.hasNext(); }
        void next() { previous = current; current.next(); }

        bool isWord() const { return std::holds_alternative<Word>(current.getValue());}
        bool isVariable() const { return std::holds_alternative<Variable>(current.getValue());}

        Word& getWord() { if (!isWord()) { throw "bad std::variant"; } return std::get<Word>(current.getValue()); }
        const Word& getWord() const { if (!isWord()) { throw "bad std::variant"; } return std::get<Word>(current.getValue()); }

        Variable& getVariable() { if (!isVariable()) { throw "bad std::variant"; } return std::get<Variable>(current.getValue()); }
        const Variable& getVariable() const { if (!isVariable()) { throw "bad std::variant"; } return std::get<Variable>(current.getValue()); }

        void realize(const Word& result) { current.setValue(result); }
        void realize(Word&& result) noexcept { current.setValue(std::move(result)); }
        void merge();
    };

    Iterator begin() { return Iterator(head); }

    std::string getStringRepresentation() const;
};

class AbstractionGenerator : public FunMarListGenerator<std::variant<Word, Variable>> {
public:
    using FunMarListGenerator<std::variant<Word, Variable>>::FunMarListGenerator;

    Abstraction generate() { return FunMarListGenerator<std::variant<Word, Variable>>::generate(); }
};

