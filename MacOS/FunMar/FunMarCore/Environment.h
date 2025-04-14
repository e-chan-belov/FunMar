#pragma once

#include "Rule.hpp"
#include <stack>

struct InputRealization {
    size_t begin;
    size_t size;
};

class PartialAbstraction {
protected:
    InputRealization inputRealization;
    FunctionAbstraction abstraction;
    FunctionAbstraction::Iterator callFunctionIterator;
public:
    PartialAbstraction() {}
    PartialAbstraction(InputRealization input, const FunctionAbstraction& abs) : inputRealization(input), abstraction(abs) {}
    PartialAbstraction(InputRealization input, FunctionAbstraction&& abs) : inputRealization(input), abstraction(std::move(abs)) {}

    bool isActive() { return callFunctionIterator.isAtList(); }

    FunctionAbstraction::Iterator begin() { return abstraction.begin(); }

    void setFunctionIterator(FunctionAbstraction::Iterator callFunctionIterator_) { callFunctionIterator = callFunctionIterator_; }
    FunctionAbstraction::Iterator getFunctionIterator() { return callFunctionIterator; }

    bool isRealized() { return abstraction.isRealized(); }
    Word getRealization() { return abstraction.getRealization(); }

    InputRealization getInputRealization() { return inputRealization; }

    void dispose() { callFunctionIterator = FunctionAbstraction::Iterator(nullptr); }
};


class Environment {
protected:
    Statements::Iterator statementsIterator;

    Scheme::Iterator schemeIteratorBegin;
    Scheme::Iterator schemeIterator;

    PartialAbstraction partialAbstraction;
    Word word;

    bool main;
public:
    Environment() = default;
    Environment(Statements::Iterator stmt, const Word& wrd, bool main_ = false) : statementsIterator(stmt), word(wrd), main(main_){}

    Environment& operator=(const Environment& env);
    //Environment operator=(Environment&& env);

    bool isPartiallyAbstract() { return partialAbstraction.isActive(); }
    bool isSchemeActive() { return schemeIterator.isAtList(); }
    bool isFunctionActive() { return statementsIterator.isAtList(); }

    void nextSchemeRule() { schemeIterator.next(); }
    void resetScheme() { schemeIterator = schemeIteratorBegin; }
    void nextFunctionRule() { statementsIterator.next(); }

    const Rule& getSchemeRule() { return schemeIterator.getRule(); }

    bool isStatementRule() { return statementsIterator.isRule(); }
    bool isStatementScheme() { return statementsIterator.isScheme(); }

    const Rule& getFunctionRule() { return statementsIterator.getRule(); }
    void activateScheme() {schemeIterator = schemeIteratorBegin = statementsIterator.getSchemeBegin(); } 

    PartialAbstraction& getPartialAbstraction() { return partialAbstraction; }
    const PartialAbstraction& getPartialAbstraction() const { return partialAbstraction; }

    Word& getWord() { return word; }
    const Word& getWord() const { return word; }

    bool isMain() { return main; }
};

class EnvironmentStreams {
protected:
    std::stack<Environment> envs;
    Environment current;
public:
    EnvironmentStreams() = default;
    EnvironmentStreams(Statements::Iterator stmt) { current = Environment(stmt, "", true); }

    void init(const Word& wrd) { current.getWord() = wrd; }

    void push(Statements::Iterator stmt, const Word& wrd) { 
        envs.push(current);
        current = Environment(stmt, wrd);
    }
    void pop() {
        current = envs.top();
        envs.pop();
    }
    Environment& top() { return current; }

    Environment& getReference() { return current; }
};