#pragma once

#include "Rotor.hpp"
#include <map>
#include <string>
#include <tuple>

class Plugboard {
    // Max 13 connections = 26 values in map
    std::string left;
    std::string right;
    public:
    Plugboard();
    auto connection_append(char, char) -> void;
    auto forward(int) -> int;
    auto backward(int) -> int;
    auto print_plugboard() -> void;
};
