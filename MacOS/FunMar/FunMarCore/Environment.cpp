#include "Environment.hpp"

PartialAbstraction& PartialAbstraction::operator=(const PartialAbstraction& partial) {
    if (&partial != this) {
        inputRealization = partial.inputRealization;
        abstraction = partial.abstraction;
        moveCallFunctionIterator();
    }
    return *this;
}

bool PartialAbstraction::moveCallFunctionIterator() {
    if (!isCallable()) {
        callFunctionIterator = abstraction.begin();
    }
    while (callFunctionIterator.isAtList()) {
        if (callFunctionIterator.isFunction()) { 
            return true; 
        }
        callFunctionIterator.next();
    }
    return false;
}

Environment& Environment::operator=(const Environment& env) {
    if (&env != this) {
        statementsIterator = env.statementsIterator;

        schemeIteratorBegin = env.schemeIteratorBegin;
        schemeIterator = env.schemeIterator;
    
        partialAbstraction = env.partialAbstraction;
        word = env.word;
    
        main = env.main;
    }
    return *this;
}