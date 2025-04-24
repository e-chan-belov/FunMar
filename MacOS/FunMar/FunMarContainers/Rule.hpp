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
    Rule(const Rule& rule) : input(rule.input), output(rule.output), terminal(rule.terminal) {}
    Rule(Rule&& rule) : input(std::move(rule.input)), output(std::move(rule.output)), terminal(rule.terminal) {}

    Rule& operator=(const Rule& rule);
    Rule& operator=(Rule&& rule) noexcept;
    
    ~Rule() {}
    
    Abstraction& getInput() { return input; }
    const Abstraction& getInput() const { return input; }

    void setInput(const Abstraction& input_) { input = input_; }

    FunctionAbstraction& getOutput() { return output; }
    const FunctionAbstraction& getOutput() const { return output; }

    void setOutput(const FunctionAbstraction& output_) { output = output_; }

    std::string getStringRepresentation() const { return input.getStringRepresentation() + (terminal ? "=>" : "->") + output.getStringRepresentation(); }
};

class Scheme : public FunMarList<Rule> { 
public:
    using FunMarList<Rule>::FunMarList; 
    Scheme(const FunMarList<Rule>& list) : FunMarList(list) {}
    Scheme(FunMarList<Rule>&& list) : FunMarList(std::move(list)) {}

    class ObserverIterator : public FunMarList<Rule>::ObserverIterator {
    public:
        using FunMarList<Rule>::ObserverIterator::ObserverIterator;

        const Rule& getRule() const { return getValue(); }
    };

    ObserverIterator begin() const { return ObserverIterator(head); }
};

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

    class ObserverIterator : public FunMarList<std::variant<Rule, Scheme>>::ObserverIterator {
    public:
        using FunMarList<std::variant<Rule, Scheme>>::ObserverIterator::ObserverIterator;
        
        bool isRule() const { return std::holds_alternative<Rule>(getValue()); }
        bool isScheme() const { return !isRule(); }
        
        const Rule& getRule() const { return std::get<Rule>(getValue()); }
        const Scheme& getScheme() const { return std::get<Scheme>(getValue()); }
        Scheme::ObserverIterator getSchemeBegin() const { return getScheme().begin(); }
    };
    
    ObserverIterator begin() const { return ObserverIterator(head); }
};

class StatementsGenerator : public FunMarListGenerator<std::variant<Rule, Scheme>> { 
public:
    using FunMarListGenerator<std::variant<Rule, Scheme>>::FunMarListGenerator; 
    Statements generate() { return FunMarListGenerator<std::variant<Rule, Scheme>>::generate(); }
};
