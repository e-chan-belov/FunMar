#include "FunctionAbstraction.hpp"

Function& Function::operator=(const Function& obj) {
    if (this != &obj) {
        var = obj.var;
        argument = obj.argument;
    }
    return *this;
}

Function& Function::operator=(Function&& obj) noexcept {
    if (this != &obj) {
        var = std::move(obj.var);
        argument = std::move(obj.argument);
    }
    return *this;
}

void FunctionAbstraction::Iterator::merge() {
    if (!isWord()) { throw -1; }
    if (previous.isAtList() && std::holds_alternative<Word>(previous.getValue())) {
        current.leftMerge(previous, (std::variant<Word, Variable, Function>)(Word)(std::get<Word>(previous.getValue()) + getWord()));
    }
    if (hasNext()) {
        FunctionAbstraction::Iterator nxt = *this;
        nxt.next();
        if (nxt.isWord()) {
            current.rightMerge((std::variant<Word, Variable, Function>)(Word)(getWord() + nxt.getWord()));
        }
    }
}

std::string FunctionAbstraction::getStringRepresentation() const {
    std::string ans = "";
    for (FunctionAbstraction::ObserverIterator iter = begin(); iter.isAtList(); iter.next()) {
        if (iter.isWord()) {
            ans += "'" + iter.getWord() + "'";
        }
        else if (iter.isVariable()) {
            ans += iter.getVariable();
        }
        else {
            const Function& f = iter.getFunction();
            ans += f.getName() + "(" + f.getArgument().getStringRepresentation() + ")";
        }
    }
    return ans;
}
