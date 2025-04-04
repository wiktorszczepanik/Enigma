#pragma once

#include "Rotor.hpp"
#include <map>

class Plugboard {
    // Max 13 connections = 26 values in map
    std::map<char, char> connections;
    public:
    Plugboard() = default;
    auto connection_append(char, char) -> void;
    auto print_plugboard() -> void;
};
