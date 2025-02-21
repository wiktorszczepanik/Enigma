
#include "Setup.hpp"

Setup::Setup(std::pair<Mode, std::string> setup) {
    mode = setup.first;
    path = setup.second;
}
