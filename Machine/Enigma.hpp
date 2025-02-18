#pragma once

#include <string>

#include "../Program/Tuples/Setup.hpp"
#include "../Program/Tuples/Action.hpp"
#include "../Program/Constants/Mode.hpp"

class Enigma {
    public:
    Enigma(Setup&, Action&);
    auto calculate() -> std::string;
    auto get_mode() -> Mode;
};
