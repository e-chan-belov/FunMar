#pragma once

#include "Rule.hpp"
#include <stack>
#include <iostream>

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
    PartialAbstraction() : inputRealization({0, 0}), abstraction(), callFunctionIterator() {}
    PartialAbstraction(const PartialAbstraction& partial) : 
    inputRealization(partial.inputRealization), abstraction(partial.abstraction) {
        moveCallFunctionIterator();
    }
    PartialAbstraction(PartialAbstraction&& partial) : inputRealization(partial.inputRealization), abstraction(std::move(partial.abstraction)), callFunctionIterator(partial.callFunctionIterator) {}

    
    PartialAbstraction(InputRealization input, const FunctionAbstraction& abs) : inputRealization(input), abstraction(abs), callFunctionIterator(nullptr) {}
    PartialAbstraction(InputRealization input, FunctionAbstraction&& abs) : inputRealization(input), abstraction(std::move(abs)), callFunctionIterator(nullptr) {}

    PartialAbstraction& operator=(const PartialAbstraction& partial);

    bool isActive() const { return callFunctionIterator.isAtList() && abstraction.size() != 0; }

    FunctionAbstraction::Iterator begin() { return abstraction.begin(); }
    FunctionAbstraction::ObserverIterator begin() const { return abstraction.begin(); }

    //void setFunctionIterator(FunctionAbstraction::Iterator callFunctionIterator_) { callFunctionIterator = callFunctionIterator_; }
    bool moveCallFunctionIterator();
    //FunctionAbstraction::Iterator getFunctionIterator() { return callFunctionIterator; }

    const Function& getFunctionCall() const { return callFunctionIterator.getFunction(); }

    void realizeOneFunction(const Word& word) { 
        callFunctionIterator.realize(word); 
        callFunctionIterator.merge();
        moveCallFunctionIterator();
    }

    bool isRealized() const { return abstraction.isRealized(); }
    Word& getRealization() { return abstraction.getRealization(); }
    const Word& getRealization() const { return abstraction.getRealization(); }

    InputRealization& getInputRealization() { return inputRealization; }

    const FunctionAbstraction& getFunctionAbstraction() const { return abstraction; }

    void dispose() { callFunctionIterator = FunctionAbstraction::Iterator(nullptr); abstraction = FunctionAbstraction(); }
};


class Environment {
protected:
    Statements::ObserverIterator statementsIterator;

    Scheme::ObserverIterator schemeIteratorBegin;
    Scheme::ObserverIterator schemeIterator;

    PartialAbstraction partialAbstraction;
    Word word;

    bool main;
public:
    Environment() = default;
    Environment(Statements::ObserverIterator stmt, const Word& wrd, bool main_ = false) : statementsIterator(stmt), word(wrd), main(main_) {}
    
    Environment(const Environment& env) : statementsIterator(env.statementsIterator), schemeIteratorBegin(env.schemeIteratorBegin),
        schemeIterator(env.schemeIterator), partialAbstraction(env.partialAbstraction), word(env.word), main(env.main) {}

    Environment& operator=(const Environment& env);
    //Environment operator=(Environment&& env);

    bool isPartiallyAbstract() const { return partialAbstraction.isActive(); }
    bool isSchemeActive() const { return schemeIterator.isAtList(); }
    bool isFunctionActive() const { return statementsIterator.isAtList(); }

    void nextSchemeRule() { schemeIterator.next(); }
    void resetScheme() { schemeIterator = schemeIteratorBegin; }
    void nextFunctionRule() { statementsIterator.next(); }

    const Rule& getSchemeRule() const { return schemeIterator.getRule(); }

    bool isStatementRule() const { return statementsIterator.isRule(); }
    bool isStatementScheme() const { return statementsIterator.isScheme(); }

    const Rule& getFunctionRule() const { return statementsIterator.getRule(); }
    void activateScheme() {schemeIterator = schemeIteratorBegin = statementsIterator.getSchemeBegin(); } 

    PartialAbstraction& getPartialAbstraction() { return partialAbstraction; }
    const PartialAbstraction& getPartialAbstraction() const { return partialAbstraction; }

    void setPartialAbstraction(const PartialAbstraction& partial) { partialAbstraction = partial; }
    void setPartialAbstraction(PartialAbstraction&& partial) { partialAbstraction = std::move(partial); }

    Word& getWord() { return word; }
    const Word& getWord() const { return word; }

    bool isMain() const { return main; }
};

class EnvironmentStreams {
protected:
    std::stack<Environment> envs;
    Environment current;
public:
    EnvironmentStreams() = default;
    EnvironmentStreams(Statements::ObserverIterator stmt) { current = Environment(stmt, "", true); }

    void init(const Word& wrd) { current.getWord() = wrd; }

    void push(Statements::ObserverIterator stmt, const Word& wrd) { 
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