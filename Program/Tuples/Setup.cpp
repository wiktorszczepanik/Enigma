#include <array>
#include <exception>
#include <vector>
#include <ios>
#include <iostream>
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

auto Setup::util() -> std::tuple<std::array<Rotor, 3>, Plugboard> {
    auto file = std::fstream(path, std::ios::in);
    if (!file.is_open()) throw std::ios_base::failure(
        "Cannot open the file.");
    auto rotors = load_rotors(file);
    auto plugboard = load_plugboard(file);
    return std::make_tuple(rotors, plugboard);
}

auto Setup::load_rotors(std::fstream& file) -> std::array<Rotor, 3> {
    auto rotors_line = std::string({});
    std::getline(file, rotors_line);
    auto rotors = std::vector<std::string>();
    auto line = std::stringstream(rotors_line);
    auto token = std::string({});
    while (std::getline(line, token, '|'))
        rotors.push_back(token);


}
