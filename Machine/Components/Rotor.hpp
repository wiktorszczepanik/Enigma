#pragma once

#include <map>
#include <vector>

class Rotor {
    int rotor_id, start_position;
    int current_position;
    std::map<char, char> rotor;
    Rotor() = default;
    public:
    Rotor(int, int);
    auto get_rotor_1() -> std::map<char, char>;
    auto get_rotor_2() -> std::map<char, char>;
    auto get_rotor_3() -> std::map<char, char>;
    auto get_rotor_4() -> std::map<char, char>;
    auto get_rotor_5() -> std::map<char, char>;
    auto print_rotor() -> void;
};
