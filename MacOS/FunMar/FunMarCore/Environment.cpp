#include "Environment.h"

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