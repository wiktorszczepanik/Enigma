#include <cmath>
#include <iostream>
#include <stdexcept>

#include "Plugboard.hpp"

Plugboard::Plugboard() {
    left = std::string("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    right = std::string("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

auto Plugboard::connection_append(char key, char value) -> void {
    auto fir_index = left.find(key);
    auto sec_index = left.find(value);
    left.at(fir_index) = value;
    left.at(sec_index) = key;
}

auto Plugboard::forward(int signal) -> int {
    auto letter = right[signal];
    return left.find(letter);
}

auto Plugboard::backward(int signal) -> int {
    auto letter = left[signal];
    return right.find(letter);
}

auto Plugboard::print_plugboard() -> void {
    std::cout << left << std::endl;
    std::cout << right << std::endl;
}
