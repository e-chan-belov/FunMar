
#include "Rule.hpp"

Rule& Rule::operator=(const Rule& rule) {
    if (this != &rule) {
        input = rule.input; 
        output = rule.output;
        terminal = rule.terminal;
    }
    return *this;
}

Rule& Rule::operator=(Rule&& rule) noexcept {
    if (this != &rule) {
        input = std::move(rule.input); 
        output = std::move(rule.output);
        terminal = std::move(rule.terminal);
    }
    return *this;
}