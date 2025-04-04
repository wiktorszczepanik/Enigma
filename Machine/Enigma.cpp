#include <vector>

#include "Enigma.hpp"
#include "Components/Plugboard.hpp"
#include "Components/Rotor.hpp"

Enigma::Enigma(std::vector<Rotor>& rotors, Plugboard plugboard, std::string message)
    : rotors(rotors), plugboard(plugboard), message(message) {}

auto Enigma::calculate() -> std::string {
    auto out_message = std::string();
    auto swiching_char = char();
    for (int i = 0; i < message.length(); i++) {
        swiching_char = message.at(i);
    }
}
