#include <iostream>
#include <stdexcept>

#include "Plugboard.hpp"

auto Plugboard::connection_append(char key, char value) -> void {
    for (auto [k, v] : connections) {
        if (key == k || key == v ||
            value == k || value == v)
            throw std::invalid_argument(
                "Incorrect connections in plugboard.");
    }
    connections[key] = value;
}

auto Plugboard::print_plugboard() -> void {
    for (auto [k, v] : connections)
        std::cout << k << " : " << v << std::endl;
}
