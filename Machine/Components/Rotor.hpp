#pragma once

#include <map>
#include <vector>
#include <array>
#include <string>

class Rotor {
    int rotor_id;
    Rotor() = default;
    public:
    int position;
    std::string left;
    std::string right;
    char notch;
    Rotor(int, int);
    auto forward(int signal) -> int;
    auto backward(int signal) -> int;
    auto rotate(int) -> void;
    auto rotate_to_letter(char) -> void;
    auto set_rotor_1() -> std::string;
    auto set_rotor_2() -> std::string;
    auto set_rotor_3() -> std::string;
    auto set_rotor_4() -> std::string;
    auto set_rotor_5() -> std::string;
    auto print_rotor() -> void;
};
