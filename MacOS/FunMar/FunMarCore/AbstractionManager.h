#pragma once

#include "EnvironmentManager.h"

class AbstractionManager {
protected:
    EnvironmentManager& environmentManager;
    Environment& current;
public:
    AbstractionManager(EnvironmentManager& environmentManager_, Environment& current_);

    ~AbstractionManager() = default;

    bool tryRealzingRule(const Rule& rule);
    bool tryRealzingRule(Rule&& rule);

    void realizeFunctionAbstraction();

    void returnAnswer();

};
