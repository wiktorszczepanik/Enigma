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
    auto load_rotors() -> void;
    auto load_number_sequence() -> void;
    auto load_plugboard() -> void;
};
