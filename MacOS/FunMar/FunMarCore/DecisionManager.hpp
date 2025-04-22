#pragma once

#include "AbstractionManager.hpp"
#include "Environment.hpp"

class DecisionManager {
protected:
    AbstractionManager& abstractionManager;
    Environment& current;
public:
    DecisionManager(AbstractionManager& abstractionManager_, Environment& current_) :  abstractionManager(abstractionManager_),
        current(current_) {}

    ~DecisionManager() = default;

    bool makeDecision();
};
