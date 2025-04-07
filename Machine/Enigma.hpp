#pragma once

#include <string>
#include <vector>

#include "../Program/Tuples/Setup.hpp"
#include "../Program/Tuples/Action.hpp"
#include "../Program/Constants/Mode.hpp"
#include "Components/Keyboard.hpp"
#include "Components/Plugboard.hpp"
#include "Components/Reflector.hpp"

class Enigma {
    std::vector<Rotor> rotors;
    Plugboard plugboard;
    Reflector reflector;
    Keyboard keyboard;
    public:
    Enigma(std::vector<Rotor>&, Plugboard, Reflector, Keyboard);
    auto calculate(char) -> char;
    auto set_key() -> void;
};
