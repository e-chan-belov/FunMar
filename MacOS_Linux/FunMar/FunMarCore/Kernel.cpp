#include "Kernel.hpp"
#include <iostream>

Kernel::Kernel(const std::unordered_map<Variable, Statements>& task, ExecutionStatus status) : functions(task),
    envs(functions[(Variable)"main"].begin()), //todo
    environmentManager(envs),
    abstractionManager(environmentManager, envs.getReference(), functions),
    decisionManager(abstractionManager, envs.getReference()) {
}

Word& Kernel::execute(const Word& argument) {
    envs.init(argument);
    while (decisionManager.makeDecision()) {}
    return envs.top().getWord();
}