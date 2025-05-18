#pragma once

#include "Rule.hpp"
#include "Environment.hpp"
#include "DecisionManager.hpp"
#include <unordered_map>
#include <stack>

typedef enum {debug, release} ExecutionStatus;

class Kernel {
protected:
    std::unordered_map<Variable, Statements> functions;
    EnvironmentStreams envs;

    DecisionManager decisionManager;
    AbstractionManager abstractionManager;
    EnvironmentManager environmentManager;
public:
    Kernel(const std::unordered_map<Variable, Statements>& task, ExecutionStatus status = release);

    Word& execute(const Word& argument);

    ~Kernel() {}
};
