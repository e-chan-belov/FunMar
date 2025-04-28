#pragma once

#include "Environment.hpp"

class EnvironmentManager {
protected:
    EnvironmentStreams& envs;
public:
    EnvironmentManager(EnvironmentStreams& envs_) : envs(envs_) {}

    ~EnvironmentManager() = default;

    void fork(const Statements& func, const Word& wrd) { envs.push(func.begin(), wrd); }

    void kill() { envs.pop(); }

};
