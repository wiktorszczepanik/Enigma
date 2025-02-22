#pragma once

#include <string>

#include "../Program/Tuples/Setup.hpp"
#include "../Program/Tuples/Action.hpp"
#include "../Program/Constants/Mode.hpp"
#include "Components/Plugboard.hpp"

class Enigma {
    public:
    Enigma(std::array<Rotor, 3>, Plugboard, std::string);
    auto calculate() -> std::string;
};
