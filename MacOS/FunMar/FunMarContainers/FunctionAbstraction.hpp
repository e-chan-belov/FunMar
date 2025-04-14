#pragma once

#include "Abstraction.hpp"
#include "FunMarList.hpp"

class Function {
protected:
    Variable var;
    Abstraction argument;
public:
    Function(Variable var_, const Abstraction& arg) : var(var_), argument(arg) {}
    Function(const Function& obj) : var(obj.var), argument(obj.argument) {}
    Function(Function&& obj) : var(obj.var), argument(std::move(obj.argument)) {}
    
    Function& operator=(const Function& obj);
    Function& operator=(Function&& obj) noexcept;
    
    ~Function() {}
    
    Variable getName() { return var; }
    Abstraction& getArgument() { return argument; }
    
    bool isRealized() { return argument.isRealized(); }
};

class FunctionAbstraction : public FunMarList<std::variant<Word, Variable, Function>> {
public:
    using FunMarList<std::variant<Word, Variable, Function>>::FunMarList;
    FunctionAbstraction(const FunMarList<std::variant<Word, Variable, Function>>& list) : FunMarList(list) {}
    FunctionAbstraction(FunMarList<std::variant<Word, Variable, Function>>&& list) : FunMarList(std::move(list)) {}

    
    bool isRealized() { return head->next == nullptr && std::holds_alternative<Word>(head->value); }
    Word getRealization() { return std::get<Word>(head->value); }
    
    class Iterator {
    protected:
        FunMarList<std::variant<Word, Variable, Function>>::Iterator previous;
        FunMarList<std::variant<Word, Variable, Function>>::Iterator current;
    public:
        Iterator(FunMarListNode<std::variant<Word, Variable, Function>>* head_ = nullptr) : previous(nullptr), current(head_) {}

        bool isAtList() const {return current.isAtList(); }
        bool hasNext() const { return current.hasNext(); }
        void next() { previous = current; current.next(); }

        bool isWord() const { return std::holds_alternative<Word>(current.getValue());}
        bool isVariable() const { return std::holds_alternative<Variable>(current.getValue());}
        bool isFunction() const { return std::holds_alternative<Function>(current.getValue());}

        Word& getWord() { return std::get<Word>(current.getValue()); }
        const Word& getWord() const { return std::get<Word>(current.getValue()); }

        Variable& getVariable() { return std::get<Variable>(current.getValue()); }
        const Variable& getVariable() const { return std::get<Variable>(current.getValue()); }

        Function& getFunction() { return std::get<Function>(current.getValue()); }
        const Function& getFunction() const { return std::get<Function>(current.getValue()); }

        void realize(Word result) { current.getValue() = result; }
        void merge();
    };
    
    Iterator begin() { return Iterator(head); }
    const Iterator begin() const { return Iterator(head); }
    
    std::string getStringRepresentation() const;
};

class FunctionAbstractionGenerator : public FunMarListGenerator<std::variant<Word, Variable, Function>> {
    public:
        using FunMarListGenerator<std::variant<Word, Variable, Function>>::FunMarListGenerator;
    
        FunctionAbstraction generate() { return FunMarListGenerator<std::variant<Word, Variable, Function>>::generate(); }
    };
    
