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
    public:
    Setup(std::pair<Mode, std::string>);
    auto util() -> std::tuple<std::array<Rotor, 3>, Plugboard>;
    private:
    auto load_rotors(std::fstream&) -> std::array<Rotor, 3>;
    auto load_plugboard(std::fstream&) -> Plugboard;
};
