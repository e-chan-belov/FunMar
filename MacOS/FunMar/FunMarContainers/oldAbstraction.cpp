#include "Abstraction.hpp"

AbstractionNode* AbstractionNode::merge(AbstractionNode* previous) {
    AbstractionNode* cur = this;
    Word tmp = "";
    if (isWord()) {
        if (previous != nullptr && previous->isWord()) {
            previous->next = next;
            tmp += std::get<Word>(previous->value) + std::get<Word>(value);
            cur = previous;
        } // either thing will be executed
        else {
            tmp += std::get<Word>(value);
        }
        if (next != nullptr && next->isWord()) {
            cur->next = next->next;
            tmp += std::get<Word>(next->value);
            delete next;
        }
        if (tmp != "") { cur->value = tmp; }
    }
    if (cur == previous) {
        return this;
    }
    else {
        return nullptr;
    }
}

std::string AbstractionNode::getValue() { 
    if (std::holds_alternative<Word>(value)) {
        return static_cast<std::string>(std::get<Word>(value));
    }
    else if (std::holds_alternative<Variable>(value)) {
        return static_cast<std::string>(std::get<Variable>(value));
    }
    return "";
}

Abstraction::Abstraction(const Abstraction& obj) {
    if (obj.head == nullptr) {
        head = obj.head;
        return;
    }
    head = new AbstractionNode(*obj.head);
    AbstractionNode* ptr = obj.head;
    AbstractionNode* tail = head;
    while (ptr->next != nullptr) {
        tail->next = new AbstractionNode(*ptr->next);
        tail = tail->next;
        ptr = ptr->next;
    }
}

Abstraction Abstraction::operator=(const Abstraction& obj) {
    if (this != &obj) {
        while (head != nullptr) {
            AbstractionNode* next = head->next;
            delete head;
            head = next;
        }
        head = new AbstractionNode(*obj.head);
        AbstractionNode* ptr = obj.head;
        AbstractionNode* tail = head;
        while (ptr->next != nullptr) {
            tail->next = new AbstractionNode(*ptr->next);
            tail = tail->next;
            ptr = ptr->next;
        }
    }
    return *this;
}

Abstraction Abstraction::operator=(Abstraction&& obj) {
    if (this != &obj) {
        while (head != nullptr) {
            AbstractionNode* next = head->next;
            delete head;
            head = next;
        }
        head = obj.head;
        obj.head = nullptr;
    }
    return *this;
}

Abstraction::~Abstraction() {
    while (head != nullptr) {
        AbstractionNode* next = head->next;
        delete head;
        head = next;
    }
}

Abstraction::Iterator Abstraction::Iterator::operator=(const Abstraction::Iterator& iter) {
    current = iter.current;
    previous = iter.previous;
    return *this;
}

void Abstraction::Iterator::merge() { // after merging you must kill iterator at all costs!
    AbstractionNode* ptr = current->merge(previous);
    if (ptr != nullptr) {
        delete ptr;
    }
}

std::string Abstraction::getStringRepresentation() {
    std::string ans = "";
    Abstraction::Iterator iter = begin();
    for (; iter.hasNext(); iter.next()) {
        if (iter.isWord()) {
            ans += "'" + iter.getValue() + "'";
        }
        else {
            ans += iter.getValue();
        }
    }
    if (iter.isWord()) {
        ans += "'" + iter.getValue() + "'";
    }
    else {
        ans += iter.getValue();
    }
    return ans;
}

void AbstractionGenerator::push(Word value) {
    if (head != nullptr) {
        tail->next = new AbstractionNode(value);
        tail = tail->next;
    }
    else {
        tail = head = new AbstractionNode(value);
    }
}

void AbstractionGenerator::push(Variable value) {
    if (head != nullptr) {
        tail->next = new AbstractionNode(value);
        tail = tail->next;
    }
    else {
        tail = head = new AbstractionNode(value);
    }
}

Abstraction AbstractionGenerator::generate() {
    Abstraction temp(head);
    head = tail = nullptr;
    return temp;
}
