#include "AbstractionManager.hpp"
#include <queue>
#include <list>
#include <iostream>

AbstractionManager::AbstractionManager(EnvironmentManager& environmentManager_, Environment& current_, std::unordered_map<Variable, Statements>& funcs) : environmentManager(environmentManager_), current(current_), functions(funcs) {}

bool AbstractionManager::tryRealzingRule(const Rule& rule) {
    const Word& currentWord = current.getWord();
    std::unordered_map<Variable, Word> vars;
    InputRealization prev, next;
    Variable var;
    prev = {0, 0};
    InputRealization ans = prev;
    for (Abstraction::ObserverIterator iter = rule.getInput().begin(); iter.isAtList(); iter.next()) {
        if (iter.isWord()) { // произойдёт максимум один раз
            prev.size = iter.getWord().size();
            prev.begin = currentWord.find(iter.getWord());
            if (prev.begin == currentWord.npos) {
                return false;
            }

            ans.begin = prev.begin;
            ans.size = prev.size;
            
        }
        else if (iter.isVariable()) {
            var = iter.getVariable();
            if (iter.hasNext()) {
                
                iter.next();
                
                next.size = iter.getWord().size();
                next.begin = currentWord.find(iter.getWord(), prev.begin + prev.size);
                
                if (next.begin == currentWord.npos || next.begin == prev.begin + prev.size) { // стоит ли убирать next.begin == prev.begin + prev.size? вопрос на правила языка. решить в будущем.
                    return false;
                }
                vars[var] = currentWord.substr(prev.begin + prev.size, next.begin - (prev.begin + prev.size));
                
            }
            else {
                next.begin = 0; next.size = 0;
                vars[var] = currentWord.substr(prev.begin + prev.size);
            }
            ans.size += vars[var].size() + next.size;
            prev = next;
            
        }
    }

    current.setPartialAbstraction(PartialAbstraction(ans, rule.getOutput()));

    //FunctionAbstraction::Iterator callFuncIter(nullptr);
    for (FunctionAbstraction::Iterator iter = current.getPartialAbstraction().begin(); iter.isAtList(); iter.next()) {
        if (iter.isVariable()) {
            iter.realize(vars[iter.getVariable()]);
            iter.merge();
        }
        else if (iter.isFunction()) {
            for (Abstraction::Iterator funcIter = iter.getFunction().getArgument().begin(); funcIter.isAtList(); funcIter.next()) {
                if (funcIter.isVariable()) {
                    funcIter.realize(vars[funcIter.getVariable()]);
                    funcIter.merge();
                }
            }
        }
    }
    current.getPartialAbstraction().moveCallFunctionIterator();
    //std::cout << current.getPartialAbstraction().getFunctionIterator().getFunction().getName() << std::endl;
    if (current.getPartialAbstraction().isRealized()) {
        InputRealization inptreal = current.getPartialAbstraction().getInputRealization();
        Word realization = current.getPartialAbstraction().getRealization();
        current.getWord() = current.getWord().substr(0, inptreal.begin) + realization + current.getWord().substr(inptreal.begin + inptreal.size);
        current.getPartialAbstraction().dispose();
    }
    return true;
}

void AbstractionManager::realizeFunctionAbstraction() {
    PartialAbstraction& partial = current.getPartialAbstraction();
    Variable FunctionName = partial.getFunctionCall().getName();
    
    Word word = partial.getFunctionCall().getArgument().getRealization();
    environmentManager.fork(functions[FunctionName].begin(), word);
}

void AbstractionManager::returnAnswer() {
    Word ans = current.getWord();
    environmentManager.kill();
    PartialAbstraction& partial = current.getPartialAbstraction();
    partial.realizeOneFunction(ans);
    
    if (partial.isRealized()) {
        InputRealization inptreal = partial.getInputRealization();
        Word realization = partial.getRealization();
        current.getWord() = current.getWord().substr(0, inptreal.begin) + realization + current.getWord().substr(inptreal.begin + inptreal.size);
        partial.dispose();
    }
    else {
        partial.moveCallFunctionIterator();
    }
}