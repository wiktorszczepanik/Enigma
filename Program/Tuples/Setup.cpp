#include <filesystem>

#include "Setup.hpp"

Setup::Setup(std::pair<Mode, std::string> setup) {
    namespace fs = std::filesystem;
    mode = setup.first;
    path = fs::path(setup.second);
}

// Setup::load_rotors() -> void {
//     //
// }
