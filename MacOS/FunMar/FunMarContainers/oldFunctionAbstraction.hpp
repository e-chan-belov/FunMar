#pragma once

#include "Abstraction.hpp"

class Function {
protected:
    Variable var;
    Abstraction argument;
public:
    Function(Variable var_, const Abstraction& arg) : var(var_), argument(arg) {}
    Function(const Function& obj) : var(obj.var), argument(obj.argument) {}
    Function(Function&& obj) : var(obj.var), argument(std::move(obj.argument)) {}
    
    Function operator=(const Function& obj);
    Function operator=(Function&& obj);
    
    ~Function() {}
    
    Variable getName() { return var; }
    Abstraction& getArgument() { return argument; }
    
    bool isRealized() { return argument.isRealized(); }
};

class FunctionAbstractionNode {
public: // todo: inherence AbstractionNode
    FunctionAbstractionNode* next;
    std::variant<Word, Variable, Function> value;
public:
    FunctionAbstractionNode(std::variant<Word, Variable, Function> value_, FunctionAbstractionNode* next_ = nullptr) : value(value_), next(next_) {}
    
    FunctionAbstractionNode(const FunctionAbstractionNode& node) : next(nullptr), value(node.value) {}
    
    ~FunctionAbstractionNode() {}
    
    bool isWord() { return std::holds_alternative<Word>(value); }
    bool isVariable() { return std::holds_alternative<Variable>(value); }
    bool isFunction() { return std::holds_alternative<Function>(value); }
    
    void realize(Word result) { value = result; }
    FunctionAbstractionNode* merge(FunctionAbstractionNode* left);
    
    std::string getValue();
    Function& getFunction() { return std::get<Function>(value); }
};

class FunctionAbstraction {
protected:
    FunctionAbstractionNode* head;
public:
    FunctionAbstraction(FunctionAbstractionNode* head_ = nullptr) : head(head_) { }
    FunctionAbstraction(const FunctionAbstraction& obj);
    FunctionAbstraction(FunctionAbstraction&& obj) : head(obj.head) { obj.head = nullptr; }
    
    FunctionAbstraction operator=(const FunctionAbstraction& obj);
    FunctionAbstraction operator=(FunctionAbstraction&& obj);
    
    ~FunctionAbstraction();
    
    bool isRealized() { return head->next == nullptr && head->isWord(); }
    std::string getRealization() { return std::get<Word>(head->value); }
    
    class Iterator {
    protected:
        FunctionAbstractionNode* previous;
        FunctionAbstractionNode* current;
    public:
        Iterator(FunctionAbstractionNode* head) : current(head), previous(nullptr) {}
        Iterator(const Iterator& iter) : current(iter.current), previous(iter.previous) {}
        
        Iterator operator=(const Iterator& iter);
        
        bool operator==(const Iterator& iter) { return current == iter.current && previous == iter.previous; }
        
        std::string getValue() { return current->getValue(); }
        Word& getWord() { return std::get<Word>(current->value); }
        Variable& getVariable() { return std::get<Variable>(current->value); }
        Function& getFunction() { return current->getFunction(); }
        
        bool isAtList() { return current != nullptr; }
        bool hasNext() { return current->next != nullptr; }
        void next() { previous = current; current = current->next; }
        
        bool isWord() { return current->isWord(); }
        bool isVariable() { return current->isVariable(); }
        bool isFunction() { return current->isFunction(); }
        
        void realize(Word result) { current->realize(result); }
        void merge();
    };
    
    Iterator begin() { return Iterator(head); }
    
    std::string getStringRepresentation();
};

class FunctionAbstractionGenerator {
protected:
    FunctionAbstractionNode* head;
    FunctionAbstractionNode* tail;
public:
    FunctionAbstractionGenerator() : head(nullptr), tail(nullptr) {}
    ~FunctionAbstractionGenerator() {}
    
    void push(Word value);
    void push(Variable value);
    void push(Function value);
    FunctionAbstraction generate();
};
