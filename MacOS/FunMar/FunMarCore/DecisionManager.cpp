#include "DecisionManager.hpp"
#include <iostream>

void DecisionManager::terminalRuleDecision() {
    current.flushFunctionEnv();
    current.flushScheme();
}

bool DecisionManager::killEnvDecision() {
    if (!current.isMain()) {
        abstractionManager.returnAnswer();
        return true;
    }
    else {
        return false;
    }
}


bool DecisionManager::makeDecision() {
    if (current.isPartiallyAbstract()) {
        abstractionManager.realizeFunctionAbstraction();
        return true;
    }
    else if (current.isSchemeActive()) {
        Rule rule = current.getSchemeRule();
        bool flag = abstractionManager.tryRealzingRule(rule);
        if (flag) {
            if (rule.isTerminal()) {
                current.flushScheme();
            }
            else {
                current.resetScheme();
            }
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
            bool flag = abstractionManager.tryRealzingRule(rule);
            if (flag && rule.isTerminal()) {
                terminalRuleDecision();
                return true;
            }
        }
        current.nextFunctionRule();
        return true;
    }
    else {
        return killEnvDecision();
    }
}