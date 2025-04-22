#pragma once

#include "Rule.hpp"
#include "Environment.hpp"
#include "DecisionManager.hpp"
#include <unordered_map>
#include <stack>

class Kernel {
protected:
    std::unordered_map<Variable, Statements> functions;
    EnvironmentStreams envs;

    DecisionManager decisionManager;
    AbstractionManager abstractionManager;
    EnvironmentManager environmentManager;
public:
    Kernel(const std::unordered_map<Variable, Statements>& task);

    Word& execute(const Word& argument);

    ~Kernel() {}
};
