#include <ios>
#include <iostream>
#include <iterator>

#include "Rotor.hpp"

Rotor::Rotor(int rotor_id, int start_position)
    : rotor_id(rotor_id), start_position(start_position) {
        current_position = start_position;
        switch (rotor_id) {
            case 1: rotor = get_rotor_1(); break;
            case 2: rotor = get_rotor_2(); break;
            case 3: rotor = get_rotor_3(); break;
            case 4: rotor = get_rotor_4(); break;
            case 5: rotor = get_rotor_5(); break;
        }
    }

auto Rotor::get_rotor_1() -> std::map<char, char> {
    return std::map<char, char>{
        {'A', 'P'}, {'B', 'D'}, {'C', 'L'}, {'D', 'F'},
        {'E', 'T'}, {'F', 'R'}, {'G', 'K'}, {'H', 'B'},
        {'I', 'O'}, {'J', 'M'}, {'K', 'W'}, {'L', 'C'},
        {'M', 'Z'}, {'N', 'V'}, {'O', 'Y'}, {'P', 'G'},
        {'Q', 'A'}, {'R', 'X'}, {'S', 'J'}, {'T', 'S'},
        {'U', 'H'}, {'V', 'I'}, {'W', 'N'}, {'X', 'E'},
        {'Y', 'Q'}, {'Z', 'U'}
    };
}

auto Rotor::get_rotor_2() -> std::map<char, char> {
    return std::map<char, char>{
        {'A', 'J'}, {'B', 'Q'}, {'C', 'T'}, {'D', 'H'},
        {'E', 'W'}, {'F', 'K'}, {'G', 'X'}, {'H', 'P'},
        {'I', 'Z'}, {'J', 'G'}, {'K', 'B'}, {'L', 'F'},
        {'M', 'N'}, {'N', 'D'}, {'O', 'V'}, {'P', 'A'},
        {'Q', 'Y'}, {'R', 'L'}, {'S', 'O'}, {'T', 'S'},
        {'U', 'M'}, {'V', 'C'}, {'W', 'E'}, {'X', 'R'},
        {'Y', 'U'}, {'Z', 'I'}
    };
}

auto Rotor::get_rotor_3() -> std::map<char, char> {
    return std::map<char, char>{
        {'A', 'M'}, {'B', 'N'}, {'C', 'O'}, {'D', 'P'},
        {'E', 'Q'}, {'F', 'R'}, {'G', 'S'}, {'H', 'T'},
        {'I', 'U'}, {'J', 'V'}, {'K', 'W'}, {'L', 'X'},
        {'M', 'Y'}, {'N', 'Z'}, {'O', 'A'}, {'P', 'B'},
        {'Q', 'C'}, {'R', 'D'}, {'S', 'E'}, {'T', 'F'},
        {'U', 'G'}, {'V', 'H'}, {'W', 'I'}, {'X', 'J'},
        {'Y', 'K'}, {'Z', 'L'}
    };
}

auto Rotor::get_rotor_4() -> std::map<char, char> {
    return std::map<char, char>{
        {'A', 'R'}, {'B', 'F'}, {'C', 'L'}, {'D', 'P'},
        {'E', 'G'}, {'F', 'Z'}, {'G', 'Y'}, {'H', 'M'},
        {'I', 'K'}, {'J', 'X'}, {'K', 'C'}, {'L', 'S'},
        {'M', 'V'}, {'N', 'B'}, {'O', 'N'}, {'P', 'T'},
        {'Q', 'A'}, {'R', 'U'}, {'S', 'O'}, {'T', 'H'},
        {'U', 'D'}, {'V', 'W'}, {'W', 'E'}, {'X', 'J'},
        {'Y', 'Q'}, {'Z', 'I'}
    };
}

auto Rotor::get_rotor_5() -> std::map<char, char> {
    return std::map<char, char>{
        {'A', 'F'}, {'B', 'M'}, {'C', 'X'}, {'D', 'A'},
        {'E', 'T'}, {'F', 'Z'}, {'G', 'R'}, {'H', 'N'},
        {'I', 'S'}, {'J', 'C'}, {'K', 'V'}, {'L', 'O'},
        {'M', 'B'}, {'N', 'W'}, {'O', 'U'}, {'P', 'Q'},
        {'Q', 'J'}, {'R', 'Y'}, {'S', 'L'}, {'T', 'D'},
        {'U', 'K'}, {'V', 'P'}, {'W', 'H'}, {'X', 'I'},
        {'Y', 'E'}, {'Z', 'G'}
    };
}

auto Rotor::print_rotor() -> void {
    for (auto [k, v] : rotor)
        std::cout << k << " : " << v << std::endl;
}
