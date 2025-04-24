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
    Function(Function&& obj) noexcept : var(obj.var), argument(std::move(obj.argument)) {}
    
    Function& operator=(const Function& obj);
    Function& operator=(Function&& obj) noexcept;
    
    ~Function() {}
    
    Variable& getName() { return var; }
    const Variable& getName() const { return var; }

    void setName(const Variable& var_) { var = var_; }

    Abstraction& getArgument() { return argument; }
    const Abstraction& getArgument() const { return argument; }

    void setArgument(const Abstraction& arg) { argument = arg; }
    
    bool isRealized() { return argument.isRealized(); }
};

class FunctionAbstraction : public FunMarList<std::variant<Word, Variable, Function>> {
public:
    using FunMarList<std::variant<Word, Variable, Function>>::FunMarList;
    FunctionAbstraction(const FunMarList<std::variant<Word, Variable, Function>>& list) : FunMarList(list) {}
    FunctionAbstraction(FunMarList<std::variant<Word, Variable, Function>>&& list) noexcept : FunMarList(std::move(list)) {}

    
    bool isRealized() const { return head != nullptr && head->next == nullptr && std::holds_alternative<Word>(head->value); }
    Word& getRealization() { return std::get<Word>(head->value); }
    const Word& getRealization() const { return std::get<Word>(head->value); }

    class ObserverIterator {
    protected:
        FunMarList<std::variant<Word, Variable, Function>>::ObserverIterator previous;
        FunMarList<std::variant<Word, Variable, Function>>::ObserverIterator current;
    public:
        ObserverIterator(FunMarListNode<std::variant<Word, Variable, Function>>* head_ = nullptr) : previous(nullptr), current(head_) {}
        ObserverIterator(const ObserverIterator& iter) : previous(iter.previous), current(iter.current) {}

        ~ObserverIterator() = default;

        ObserverIterator& operator=(const ObserverIterator& iter) { if (this != &iter) { previous = iter.previous; current = iter.current; } return *this;  }

        bool isAtList() const {return current.isAtList(); }
        bool hasNext() const { return current.hasNext(); }
        void next() { previous = current; current.next(); }

        bool isWord() const { return std::holds_alternative<Word>(current.getValue());}
        bool isVariable() const { return std::holds_alternative<Variable>(current.getValue());}
        bool isFunction() const { return std::holds_alternative<Function>(current.getValue());}

        const Word& getWord() const { if (!isWord()) { throw "bad std::variant"; } return std::get<Word>(current.getValue()); }

        const Variable& getVariable() const { if (!isVariable()) { throw "bad std::variant"; } return std::get<Variable>(current.getValue()); }

        const Function& getFunction() const { if (!isFunction()) { throw "bad std::variant"; } return std::get<Function>(current.getValue()); }
    };
            
    ObserverIterator begin() const { return ObserverIterator(head); }
    
    class Iterator {
    protected:
        FunMarList<std::variant<Word, Variable, Function>>::Iterator previous;
        FunMarList<std::variant<Word, Variable, Function>>::Iterator current;
    public:
        Iterator(FunMarListNode<std::variant<Word, Variable, Function>>* head_ = nullptr) : previous(nullptr), current(head_) {}
        Iterator(const Iterator& iter) : previous(iter.previous), current(iter.current) {}

        Iterator& operator=(const Iterator& iter) { if (this != &iter) { previous = iter.previous; current = iter.current; } return *this;  }

        bool isAtList() const {return current.isAtList(); }
        bool hasNext() const { return current.hasNext(); }
        void next() { previous = current; current.next(); }

        bool isWord() const { return std::holds_alternative<Word>(current.getValue());}
        bool isVariable() const { return std::holds_alternative<Variable>(current.getValue());}
        bool isFunction() const { return std::holds_alternative<Function>(current.getValue());}

        Word& getWord() { if (!isWord()) { throw "bad std::variant"; } return std::get<Word>(current.getValue()); }
        const Word& getWord() const { if (!isWord()) { throw "bad std::variant"; } return std::get<Word>(current.getValue()); }

        Variable& getVariable() { if (!isVariable()) { throw "bad std::variant"; } return std::get<Variable>(current.getValue()); }
        const Variable& getVariable() const { if (!isVariable()) { throw "bad std::variant"; } return std::get<Variable>(current.getValue()); }

        Function& getFunction() { if (!isFunction()) { throw "bad std::variant"; } return std::get<Function>(current.getValue()); }
        const Function& getFunction() const { if (!isFunction()) { throw "bad std::variant"; } return std::get<Function>(current.getValue()); }

        void realize(const Word& result) { current.setValue(result); }
        void realize(Word&& result) noexcept { current.setValue(std::move(result)); }
        void merge();
    };
    
    Iterator begin() { return Iterator(head); }
    
    std::string getStringRepresentation() const;
};

class FunctionAbstractionGenerator : public FunMarListGenerator<std::variant<Word, Variable, Function>> {
    public:
        using FunMarListGenerator<std::variant<Word, Variable, Function>>::FunMarListGenerator;
    
        FunctionAbstraction generate() { return FunMarListGenerator<std::variant<Word, Variable, Function>>::generate(); }
    };
    
