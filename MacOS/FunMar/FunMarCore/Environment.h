#pragma once

#include "Rule.hpp"

struct InputRealization {
    size_t begin;
    size_t end;
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

    FunctionAbstraction::Iterator begin() { return abstraction.begin(); }

    void setFunctionIterator(FunctionAbstraction::Iterator callFunctionIterator_) { callFunctionIterator = callFunctionIterator_; }
    FunctionAbstraction::Iterator getFunctionIterator() { return callFunctionIterator; }
};


class Environment {
protected:
    Statements::Iterator statementsIterator;

    Scheme::Iterator schemeIteratorBegin;
    Scheme::Iterator schemeIterator;

    PartialAbstraction partialAbstraction;
    Word word;
public:
    Environment(Statements::Iterator stmt, Word wrd) : statementsIterator(stmt), word(wrd) {}

    bool isPartiallyAbstract();
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

    PartialAbstraction& getPartialAbstraction();
    Word& getWord() { return word; }
};