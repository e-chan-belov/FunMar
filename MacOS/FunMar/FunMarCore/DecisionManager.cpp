#include "DecisionManager.hpp"
#include <iostream>


bool DecisionManager::makeDecision() {
    if (current.isPartiallyAbstract()) {
        abstractionManager.realizeFunctionAbstraction();
        return true;
    }
    else if (current.isSchemeActive()) {
        Rule rule = current.getSchemeRule();
        bool flag = abstractionManager.tryRealzingRule(rule);
        if (flag) {
            current.resetScheme();
        }
        else {
            current.nextSchemeRule();
        }
        return true;
    }
    else if (current.isFunctionActive()) {
        if (current.isStatementScheme()) {
            current.activateScheme();
        } else {
            Rule rule = current.getFunctionRule();
            abstractionManager.tryRealzingRule(rule);
        }
        current.nextFunctionRule();
        return true;
    }
    else {
        if (!current.isMain()) {
            abstractionManager.returnAnswer();
            return true;
        }
        else {
            return false;
        }
    }
}