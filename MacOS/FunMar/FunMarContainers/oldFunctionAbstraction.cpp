#include "FunctionAbstraction.hpp"

Function Function::operator=(const Function& obj) {
    if (this != &obj) {
        var = obj.var;
        argument = obj.argument;
    }
    return *this;
}
Function Function::operator=(Function&& obj) {
    if (this != &obj) {
        var = obj.var;
        argument = obj.argument;
    }
    return *this;
}

FunctionAbstractionNode* FunctionAbstractionNode::merge(FunctionAbstractionNode* previous) {
    FunctionAbstractionNode* cur = this;
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


FunctionAbstraction::FunctionAbstraction(const FunctionAbstraction& obj) {
    if (obj.head == nullptr) {
        head = obj.head;
        return;
    }
    head = new FunctionAbstractionNode(*obj.head);
    FunctionAbstractionNode* ptr = obj.head;
    FunctionAbstractionNode* tail = head;
    while (ptr->next != nullptr) {
        tail->next = new FunctionAbstractionNode(*ptr->next);
        tail = tail->next;
        ptr = ptr->next;
    }
}

FunctionAbstraction FunctionAbstraction::operator=(const FunctionAbstraction& obj) {
    if (this != &obj) {
        while (head != nullptr) {
            FunctionAbstractionNode* next = head->next;
            delete head;
            head = next;
        }
        head = new FunctionAbstractionNode(*obj.head);
        FunctionAbstractionNode* ptr = obj.head;
        FunctionAbstractionNode* tail = head;
        while (ptr->next != nullptr) {
            tail->next = new FunctionAbstractionNode(*ptr->next);
            tail = tail->next;
            ptr = ptr->next;
        }
    }
    return *this;
}

FunctionAbstraction FunctionAbstraction::operator=(FunctionAbstraction&& obj) {
    if (this != &obj) {
        while (head != nullptr) {
            FunctionAbstractionNode* next = head->next;
            delete head;
            head = next;
        }
        head = obj.head;
        obj.head = nullptr;
    }
    return *this;
}

FunctionAbstraction::~FunctionAbstraction() {
    while (head != nullptr) {
        FunctionAbstractionNode* next = head->next;
        delete head;
        head = next;
    }
}

FunctionAbstraction::Iterator FunctionAbstraction::Iterator::operator=(const FunctionAbstraction::Iterator& iter) {
    current = iter.current;
    previous = iter.previous;
    return *this;
}

void FunctionAbstraction::Iterator::merge() { // after merging you must kill iterator at all costs!
    FunctionAbstractionNode* ptr = current->merge(previous);
    if (ptr != nullptr) {
        delete ptr;
    }
}

std::string FunctionAbstractionNode::getValue() { 
    if (std::holds_alternative<Word>(value)) {
        return static_cast<std::string>(std::get<Word>(value));
    }
    else if (std::holds_alternative<Variable>(value)) {
        return static_cast<std::string>(std::get<Variable>(value));
    }
    else if (std::holds_alternative<Function>(value)) { // is not used
        Function temp = std::get<Function>(value);
        return temp.getName() + "(" + temp.getArgument().getStringRepresentation() + ")";
    }
    return "";
}

std::string FunctionAbstraction::getStringRepresentation() {
    std::string ans = "";
    FunctionAbstraction::Iterator iter = begin();
    for (; iter.hasNext(); iter.next()) {
        if (iter.isWord()) {
            ans += "'" + iter.getValue() + "'";
        }
        else if (iter.isVariable()) {
            ans += iter.getValue();
        }
        else {
            ans += iter.getValue();
        }
    }
    if (iter.isWord()) {
        ans += "'" + iter.getValue() + "'";
    }
    else if (iter.isVariable()) {
        ans += iter.getValue();
    }
    else {
        ans += iter.getValue(); //костыль. исправить.
    }
    return ans;
}

void FunctionAbstractionGenerator::push(Word value) {
    if (head != nullptr) {
        tail->next = new FunctionAbstractionNode(value);
        tail = tail->next;
    }
    else {
        tail = head = new FunctionAbstractionNode(value);
    }
}

void FunctionAbstractionGenerator::push(Variable value) {
    if (head != nullptr) {
        tail->next = new FunctionAbstractionNode(value);
        tail = tail->next;
    }
    else {
        tail = head = new FunctionAbstractionNode(value);
    }
}

void FunctionAbstractionGenerator::push(Function value) {
    if (head != nullptr) {
        tail->next = new FunctionAbstractionNode(value);
        tail = tail->next;
    }
    else {
        tail = head = new FunctionAbstractionNode(value);
    }
}

FunctionAbstraction FunctionAbstractionGenerator::generate() {
    FunctionAbstraction temp(head);
    head = tail = nullptr;
    return temp;
}


