#pragma once

#include "EnvironmentManager.h"

class AbstractionManager {
protected:
    EnvironmentManager& environmentManager;
    Environment& current;
    std::unordered_map<Variable, Statements>& functions;
public:
    AbstractionManager(EnvironmentManager& environmentManager_, Environment& current_, std::unordered_map<Variable, Statements>& funcs);

    ~AbstractionManager() = default;

    bool tryRealzingRule(const Rule& rule);
    //bool tryRealzingRule(Rule&& rule);

    void realizeFunctionAbstraction();

    void returnAnswer();

};
