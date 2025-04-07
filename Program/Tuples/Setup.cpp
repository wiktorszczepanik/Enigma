#include <array>
#include <exception>
#include <stdexcept>
#include <string>
#include <vector>
#include <ios>
#include <iostream>
#include <array>
#include <map>
#include <filesystem>
#include <sstream>
#include <utility>
#include <fstream>

#include "Setup.hpp"

Setup::Setup(std::pair<Mode, std::string> setup) {
    namespace fs = std::filesystem;
    mode = setup.first;
    path = fs::path(setup.second);
}

auto Setup::util() -> std::tuple<std::vector<Rotor>, Plugboard, Reflector, Keyboard> {
    auto file = std::fstream(path, std::ios::in);
    if (!file.is_open()) throw std::ios_base::failure(
        "Cannot open the file.");
    auto rotors = load_rotors(file);
    auto reflector = load_reflector(file);
    auto plugboard = load_plugboard(file);
    auto keyboard = Keyboard();
    file.close();
    return std::make_tuple(rotors, plugboard, reflector, keyboard);
}

auto Setup::load_rotors(std::fstream& file) -> std::vector<Rotor> {
    auto rotors_line = std::string({});
    std::getline(file, rotors_line);
    auto rotors = std::vector<std::string>();
    auto line = std::stringstream(rotors_line);
    auto token = std::string({});
    while (std::getline(line, token, '|'))
        rotors.push_back(token);
    auto map = std::map<int, int>();
    for (auto rotor : rotors) {
        auto rotor_id = std::stoi(rotor.substr(1, 1));
        auto start_position = std::stoi(
            rotor.substr(rotor.find("{") + 1, rotor.length()));
        if (map.find(rotor_id) != map.end()) throw std::ios_base::failure(
            "Same rotors are selected."
        );
        map.insert({rotor_id, start_position});
    }
    if (map.size() != 3) throw std::invalid_argument(
        "Machine must have 3 rotors."
    );
    auto rotors_list = std::vector<Rotor>();
    for (auto [k, v] : map)
        rotors_list.push_back(Rotor(k, v));
    return rotors_list;
}

auto Setup::load_reflector(std::fstream& file) -> Reflector {
    auto type = int();
    auto reflector_line = std::string();
    std::getline(file, reflector_line);
    if (reflector_line == "A") type = 1;
    else if (reflector_line == "B") type = 2;
    else if (reflector_line == "C") type = 3;
    else throw std::invalid_argument("Invalid reflector type.");
    return Reflector(type);
}

auto Setup::load_plugboard(std::fstream& file) -> Plugboard {
    auto plugboard = Plugboard();
    auto line = std::string();
    while (std::getline(file, line)) {
        if (line.length() == 3 && (line[1] == '-' || line[1] == '=')) {
            plugboard.connection_append(line[0], line[2]);
            // plugboard.connection_append(line[2], line[0]);
        } else throw std::invalid_argument("Incorrect plugboard syntax.");
    }
    return plugboard;
}
