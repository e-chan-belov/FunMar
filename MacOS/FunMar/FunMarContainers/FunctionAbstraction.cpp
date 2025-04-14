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
    if (!isWord()) { return; }
    Word tmp = "";
    if (previous.pointer != nullptr && std::holds_alternative<Word>(previous.getValue())) {
        tmp = std::get<Word>(previous.getValue()) + getWord();
        previous.pointer->next = current.pointer->next;
        delete current.pointer;
        current.pointer = previous.pointer;
        previous.pointer = nullptr;
    }
    else {
        tmp = getWord();
    }
    if (hasNext() && std::holds_alternative<Word>(current.pointer->next->getValue())) {
        tmp += std::get<Word>(current.pointer->next->getValue());
        current.pointer->next = current.pointer->next->next;
        delete current.pointer->next;
    }
    getWord() = tmp;
}

std::string FunctionAbstraction::getStringRepresentation() const {
    std::string ans = "";
    for (FunctionAbstraction::Iterator iter = begin(); iter.isAtList(); iter.next()) {
        if (iter.isWord()) {
            ans += "'" + iter.getWord() + "'";
        }
        else if (iter.isVariable()) {
            ans += iter.getVariable();
        }
        else {
            Function& f = iter.getFunction();
            ans += f.getName() + "(" + f.getArgument().getStringRepresentation() + ")";
        }
    }
    return ans;
}
