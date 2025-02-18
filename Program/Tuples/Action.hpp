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
    auto check_message() const -> void;
    auto transform_message() -> void;
};
