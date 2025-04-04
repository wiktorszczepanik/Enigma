#pragma once

#include <string>
#include <vector>

#include "../Program/Tuples/Setup.hpp"
#include "../Program/Tuples/Action.hpp"
#include "../Program/Constants/Mode.hpp"
#include "Components/Plugboard.hpp"

class Enigma {
    std::vector<Rotor> rotors;
    Plugboard plugboard;
    std::string message;
    public:
    Enigma(std::vector<Rotor>&, Plugboard, std::string);
    auto calculate() -> std::string;
};
