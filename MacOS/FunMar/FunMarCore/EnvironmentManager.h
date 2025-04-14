#pragma once

#include "Environment.h"

class EnvironmentManager {
protected:
    EnvironmentStreams& envs;
public:
    EnvironmentManager(EnvironmentStreams& envs_) : envs(envs_) {}

    ~EnvironmentManager() = default;

    void fork(Statements::Iterator iter, const Word& wrd) { envs.push(iter, wrd); }

    void kill() { envs.pop(); }

};
