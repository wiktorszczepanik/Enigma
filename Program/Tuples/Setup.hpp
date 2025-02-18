#pragma once

#include <array>
#include <filesystem>
#include <string>
#include <utility>

#include "../Constants/Mode.hpp"
#include "../../Machine/Components/Rotor.hpp"
#include "../../Machine/Components/Plugboard.hpp"

class Setup {
    Mode mode;
    std::filesystem::path path;
    std::array<Rotor, 3> rotors;
    Plugboard plugboard;
    public:
    Setup(std::pair<Mode, std::string>);
    auto util() -> void;
    private:
    auto set_rotors() -> void;
    auto set_number_sequence() -> void;
    auto set_plugboard() -> void;
};
