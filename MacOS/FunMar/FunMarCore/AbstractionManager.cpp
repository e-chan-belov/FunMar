#include "AbstractionManager.h"
#include <queue>
#include <list>

// bool findAndPlaceRealization(InputRealization& cur, const Word& where, const Word& what) {
//     cur.size = what.size();
//     cur.begin = where.find(what);
//     if (cur.begin == where.npos) {
//         return false;
//     }
//     return true;
// }

bool AbstractionManager::tryRealzingRule(const Rule& rule) {
    Word& currentWord = current.getWord();
    std::unordered_map<Variable, Word> vars;
    InputRealization prev, next;
    Variable var;
    prev.begin = 0; prev.size = 0;
    InputRealization ans = prev;
    for (const Abstraction::Iterator iter = rule.getInput().begin(); iter.isAtList(); iter.next()) {
        if (iter.isWord()) { // произойдёт максимум один раз
            prev.size = iter.getWord().size();
            prev.begin = currentWord.find(iter.getWord());
            if (prev.begin == currentWord.npos) {
                return false;
            }

            ans.begin = prev.begin;
            ans.size += prev.size;
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

                vars[var] = currentWord.substr(prev.begin + prev.size, next.begin - prev.begin - 1);
            }
            else {
                next.begin = 0; next.size = 0;
                vars[var] = currentWord.substr(prev.begin + prev.size);
            }
            ans.size += vars[var].size() + next.size;
            prev = next;
        }
    }
    current.getPartialAbstraction() = PartialAbstraction(ans, rule.getOutput());

    FunctionAbstraction::Iterator callFuncIter(nullptr);
    for (FunctionAbstraction::Iterator iter = current.getPartialAbstraction().begin(); iter.isAtList(); iter.next()) {
        if (iter.isVariable()) {
            iter.realize(vars[iter.getVariable()]);
            iter.merge();
        }
        else if (iter.isFunction()) {
            if (!callFuncIter.isAtList()) { callFuncIter = iter;}
            for (Abstraction::Iterator funcIter = iter.getFunction().getArgument().begin(); funcIter.isAtList(); funcIter.next()) {
                if (funcIter.isVariable()) {
                    funcIter.realize(vars[funcIter.getVariable()]);
                    funcIter.merge();
                }
            }
        }
    }
    current.getPartialAbstraction().setFunctionIterator(callFuncIter);
    return true;
}

void AbstractionManager::realizeFunctionAbstraction() {
    PartialAbstraction& partial = current.getPartialAbstraction();
    Variable FunctionName = partial.getFunctionIterator().getFunction().getName();
    Word word = partial.getFunctionIterator().getFunction().getArgument().getRealization();
    environmentManager.fork(functions[FunctionName].begin(), word);
}

void AbstractionManager::returnAnswer() {
    Word ans = current.getWord();
    environmentManager.kill();
    PartialAbstraction& partial = current.getPartialAbstraction();
    partial.getFunctionIterator().realize(ans);
    partial.getFunctionIterator().merge();
    
    if (partial.isRealized()) {
        InputRealization inptreal = partial.getInputRealization();
        Word realization = partial.getRealization();
        current.getWord() = current.getWord().substr(0, inptreal.begin) + realization + current.getWord().substr(inptreal.begin + inptreal.size);
        partial.dispose();
    }
    else {
        FunctionAbstraction::Iterator iter = partial.getFunctionIterator();
        while (iter.isFunction() && iter.isAtList()) {
            iter.next();
        }
    }
}