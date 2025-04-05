#pragma once

#include <string>
#include <variant>

class Word : public std::string { 
public:
    using std::string::string; 
    Word(const std::string& str) : std::string(str) {}
};

namespace std { // костыль
    template <>
    struct hash<Word> {
        size_t operator()(const Word& w) const {
            return hash<std::string>()(w);
        }
    };
}

class Variable : public std::string { 
public:
    using std::string::string; 
    Variable(const std::string& str) : std::string(str) {}
};

namespace std { // костыль
    template <>
    struct hash<Variable> {
        size_t operator()(const Variable& w) const {
            return hash<std::string>()(w);
        }
    };
}

class AbstractionNode {
public:
    AbstractionNode* next;
    std::variant<Word, Variable> value;
public:
    AbstractionNode(std::variant<Word, Variable> value_, AbstractionNode* next_ = nullptr) : value(value_), next(next_) {}
    
    AbstractionNode(const AbstractionNode& node) : next(nullptr), value(node.value) {}
    
    ~AbstractionNode() {}
    
    bool isWord() { return std::holds_alternative<Word>(value); }
    bool isVariable() { return std::holds_alternative<Variable>(value); }
    
    void realize(Word result) { value = result; }
    AbstractionNode* merge(AbstractionNode* left);
    
    std::string getValue();
};

class Abstraction {
protected:
    AbstractionNode* head;
public:
    Abstraction(AbstractionNode* head_ = nullptr) : head(head_) { }
    Abstraction(const Abstraction& obj);
    Abstraction(Abstraction&& obj) : head(obj.head) { obj.head = nullptr; }
    
    Abstraction operator=(const Abstraction& obj);
    Abstraction operator=(Abstraction&& obj);
    
    ~Abstraction();
    
    bool isRealized() { return head->next == nullptr && head->isWord(); }
    std::string getRealization() { return std::get<Word>(head->value); }
    
    class Iterator {
    protected:
        AbstractionNode* previous;
        AbstractionNode* current;
    public:
        Iterator(AbstractionNode* head) : current(head), previous(nullptr) {}
        Iterator(const Iterator& iter) : current(iter.current), previous(iter.previous) {}
        
        Iterator operator=(const Iterator& iter);
        
        bool operator==(const Iterator& iter) { return current == iter.current && previous == iter.previous; }
        
        std::string getValue() { return current->getValue(); }
        Word& getWord() { return std::get<Word>(current->value); }
        Variable& getVariable() { return std::get<Variable>(current->value); }
        
        bool isAtList() { return current != nullptr; }
        bool hasNext() { return current->next != nullptr; }
        void next() { previous = current; current = current->next; }
        
        bool isWord() { return current->isWord(); }
        bool isVariable() { return current->isVariable(); }
        
        void realize(Word result) { current->realize(result); }
        void merge();
    };
    
    Iterator begin() { return Iterator(head); }
    
    std::string getStringRepresentation();
};

class AbstractionGenerator {
protected:
    AbstractionNode* head;
    AbstractionNode* tail;
public:
    AbstractionGenerator(void) : head(nullptr), tail(nullptr) {}
    ~AbstractionGenerator() {}
    
    void push(Word value);
    void push(Variable value);
    Abstraction generate();
};
