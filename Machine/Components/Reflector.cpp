#include <map>
#include <iostream>

#include "Reflector.hpp"

Reflector::Reflector(int reflector_id) : reflector_id(reflector_id) {
        left = std::string("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        switch (reflector_id) {
            case 1: right = set_reflector_1(); break;
            case 2: right = set_reflector_2(); break;
            case 3: right = set_reflector_3(); break;
        }
}

auto Reflector::reflect(int signal) -> int {
    auto letter = right[signal];
    return left.find(letter);
}

auto Reflector::set_reflector_1() -> std::string {
    return std::string("EJMZALYXVBWFCRQUONTSPIKHGD");
    notch = 'A';
}

auto Reflector::set_reflector_2() -> std::string {
    return std::string("YRUHQSLDPXNGOKMIEBFZCWVJAT");
    notch = 'B';
}

auto Reflector::set_reflector_3() -> std::string {
    return std::string("FVPJIAOYEDRZXWGCTKUQSBNMHL");
    notch = 'C';
}

auto Reflector::print_reflector() -> void {
    std::cout << left << std::endl;
    std::cout << right << std::endl;
}
