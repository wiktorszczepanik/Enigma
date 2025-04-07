#include <ios>
#include <iostream>
#include <iterator>

#include "Rotor.hpp"

Rotor::Rotor(int rotor_id, int position)
    : rotor_id(rotor_id), position(position) {
        left = std::string("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        switch (rotor_id) {
            case 1: right = set_rotor_1(); break;
            case 2: right = set_rotor_2(); break;
            case 3: right = set_rotor_3(); break;
            case 4: right = set_rotor_4(); break;
            case 5: right = set_rotor_5(); break;
        }
    }

auto Rotor::forward(int signal) -> int {
    auto letter = right[signal];
    return left.find(letter);
}

auto Rotor::backward(int signal) -> int {
    auto letter = left[signal];
    return right.find(letter);
}

auto Rotor::rotate(int n) -> void {
    for (auto i = 0; i < n; i++) {
        left = left.substr(1) + left.at(0);
        right = right.substr(1) + right.at(0);
    }
}

auto Rotor::rotate_to_letter(char letter) -> void {
    auto alp = std::string("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    auto n = alp.find(letter);
    rotate(n);
}

auto Rotor::set_rotor_1() -> std::string {
    return std::string("EKMFLGDQVZNTOWYHXUSPAIBRCJ");
    notch = 'Q';
}

auto Rotor::set_rotor_2() -> std::string {
    return std::string("AJDKSIRUXBLHWTMCQGZNPYFVOE");
    notch = 'E';
}

auto Rotor::set_rotor_3() -> std::string {
    return std::string("BDFHJLCPRTXVZNYEIWGAKMUSQO");
    notch = 'V';
}

auto Rotor::set_rotor_4() -> std::string {
    return std::string("ESOVPZJAYQUIRHXLNFTGKDCMWB");
    notch = 'J';
}

auto Rotor::set_rotor_5() -> std::string {
    return std::string("VZBRGITYUPSDNHLXAWMJQOFECK");
    notch = 'Z';
}

auto Rotor::print_rotor() -> void {
    std::cout << left << std::endl;
    std::cout << right << std::endl;
}
