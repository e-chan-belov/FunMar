#include "Abstraction.hpp"

void Abstraction::Iterator::merge() {
    if (!isWord()) { throw -1; }
    if (previous.isAtList() && std::holds_alternative<Word>(previous.getValue())) {
        current.leftMerge(previous, (std::variant<Word, Variable>)(Word)(std::get<Word>(previous.getValue()) + getWord()));
    }
    if (hasNext()) {
        Abstraction::Iterator nxt = *this;
        nxt.next();
        if (nxt.isWord()) {
            current.rightMerge((std::variant<Word, Variable>)(Word)(getWord() + nxt.getWord()));
        }
    }
}

std::string Abstraction::getStringRepresentation() const {
    std::string ans = "";
    for (Abstraction::ObserverIterator iter = begin(); iter.isAtList(); iter.next()) {
        if (iter.isWord()) {
            ans += "'" + iter.getWord() + "'";
        }
        else {
            ans += iter.getVariable();
        }
    }
    return ans;
}