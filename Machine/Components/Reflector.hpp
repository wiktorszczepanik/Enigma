#pragma once

#include <map>
#include <string>

class Reflector {
    int reflector_id;
    std::string left;
    std::string right;
    int notch;
    public:
    Reflector(int);
    auto reflect(int signal) -> int;
    auto set_reflector_1() -> std::string;
    auto set_reflector_2() -> std::string;
    auto set_reflector_3() -> std::string;
    auto print_reflector() -> void;
};
