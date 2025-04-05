#include "Abstraction.hpp"

void Abstraction::Iterator::merge() {
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

std::string Abstraction::getStringRepresentation() {
    std::string ans = "";
    for (Abstraction::Iterator iter = begin(); iter.isAtList(); iter.next()) {
        if (iter.isWord()) {
            ans += "'" + iter.getWord() + "'";
        }
        else {
            ans += iter.getVariable();
        }
    }
    return ans;
}