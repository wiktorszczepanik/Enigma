#pragma once

#include <string>

#include "../Constants/Mode.hpp"

class Action {
    Mode mode;
    std::string message;
    public:
    Action(std::pair<Mode, std::string>);
    auto util() -> void;
    private:
    auto transform_message(std::string&) -> void;
};
