#include <vector>
#include <iostream>

#include "Enigma.hpp"
#include "Components/Keyboard.hpp"
#include "Components/Plugboard.hpp"
#include "Components/Reflector.hpp"
#include "Components/Rotor.hpp"

Enigma::Enigma(std::vector<Rotor>& rotors, Plugboard plugboard, Reflector reflector, Keyboard keyboard)
    : rotors(rotors), plugboard(plugboard), reflector(reflector), keyboard(keyboard) {}

auto Enigma::calculate(char letter) -> char {

    if (rotors[1].left[0] == rotors[1].notch
        && rotors[2].left[0] == rotors[2].notch) {
        rotors[0].rotate(1);
        rotors[1].rotate(1);
        rotors[2].rotate(1);
    } else if (rotors[1].left[0] == rotors[1].notch) {
        rotors[0].rotate(1);
        rotors[1].rotate(1);
        rotors[2].rotate(1);
    } else if (rotors[2].left[0] == rotors[2].notch) {
        rotors[1].rotate(1);
        rotors[2].rotate(1);
    } else rotors[2].rotate(1);

    auto signal = keyboard.forward(letter);
    signal = plugboard.forward(signal);
    signal = rotors[2].forward(signal);
    signal = rotors[1].forward(signal);
    signal = rotors[0].forward(signal);

    signal = reflector.reflect(signal);

    signal = rotors[0].backward(signal);
    signal = rotors[1].backward(signal);
    signal = rotors[2].backward(signal);
    signal = plugboard.backward(signal);
    letter = keyboard.backward(signal);

    return letter;
}

auto Enigma::set_key() -> void {
    rotors[0].rotate_to_letter(static_cast<char>(rotors[0].position + 64));
    rotors[1].rotate_to_letter(static_cast<char>(rotors[1].position + 64));
    rotors[2].rotate_to_letter(static_cast<char>(rotors[2].position + 64));
}
