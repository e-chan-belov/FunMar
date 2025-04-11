#pragma once

#include "AbstractionManager.h"
#include "Environment.h"

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
