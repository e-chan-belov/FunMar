#pragma once

#include "EnvironmentManager.hpp"

class AbstractionManager {
protected:
    EnvironmentManager& environmentManager;
    Environment& current;
    const std::unordered_map<Variable, Statements>& functions;
public:
    AbstractionManager(EnvironmentManager& environmentManager_, Environment& current_, const std::unordered_map<Variable, Statements>& funcs);

    ~AbstractionManager() = default;

    bool tryRealzingRule(const Rule& rule);
    //bool tryRealzingRule(Rule&& rule);

    void realizeFunctionAbstraction();

    void returnAnswer();

};
