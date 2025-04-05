#pragma once


#include "FunctionAbstraction.hpp"
#include "FunMarList.hpp"

class Rule {
protected:
    Abstraction input;
    FunctionAbstraction output;
    
    bool terminal;
public:
    Rule(const Abstraction& input_, const FunctionAbstraction& output_, bool term) : input(input_), output(output_), terminal(term) {}
    Rule(Abstraction&& input_, FunctionAbstraction&& output_, bool term) : input(input_), output(output_), terminal(term) {}
    
    ~Rule() {}
    
    Abstraction getInput() { return input; }
    FunctionAbstraction getOutput() { return output; }
};

class Scheme : public FunMarList<Rule> { 
public:
    using FunMarList<Rule>::FunMarList; 
    Scheme(const FunMarList<Rule>& list) : FunMarList(list) {}
    Scheme(FunMarList<Rule>&& list) : FunMarList(std::move(list)) {}

    class Iterator : public FunMarList<Rule>::Iterator {
    public:
        using FunMarList<Rule>::Iterator::Iterator;

        Rule& getRule() { return getValue(); }
    };

    Iterator begin() { return Iterator(head); }
};

// fix this generator
class SchemeGenerator : public FunMarListGenerator<Rule> { 
public:
    using FunMarListGenerator<Rule>::FunMarListGenerator; 
    Scheme generate() { return FunMarListGenerator<Rule>::generate(); }
};

class Statements : public FunMarList<std::variant<Rule, Scheme>> {
public:
    using FunMarList<std::variant<Rule, Scheme>>::FunMarList;
    Statements(const FunMarList<std::variant<Rule, Scheme>>& list) : FunMarList(list) {}
    Statements(FunMarList<std::variant<Rule, Scheme>>&& list) : FunMarList(std::move(list)) {}

    class Iterator : public FunMarList<std::variant<Rule, Scheme>>::Iterator {
    public:
        using FunMarList<std::variant<Rule, Scheme>>::Iterator::Iterator;
        
        bool isRule() { return std::holds_alternative<Rule>(getValue()); }
        bool isScheme() { return !isRule(); }
        
        Rule& getRule() { return std::get<Rule>(getValue()); }
        Scheme& getScheme() { return std::get<Scheme>(getValue()); }
        Scheme::Iterator getSchemeBegin() { return getScheme().begin(); }
    };
    
    Iterator begin() { return Iterator(head); }
};

// fix this generator
class StatementsGenerator : public FunMarListGenerator<std::variant<Rule, Scheme>> { 
public:
    using FunMarListGenerator<std::variant<Rule, Scheme>>::FunMarListGenerator; 
    Statements generate() { return FunMarListGenerator<std::variant<Rule, Scheme>>::generate(); }
};
