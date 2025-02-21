#pragma once

#include <string>
#include <vector>
#include <map>

#include "../Constants/Mode.hpp"

namespace input {
    class Flags {
        std::map<Mode, std::string> flags;
        public:
        Flags(std::vector<std::string>&);
        auto validate() -> void;
        auto get_action() -> std::pair<Mode, std::string>;
        auto get_setup() -> std::pair<Mode, std::string>;
        private:
        auto struct_transform(std::vector<std::string>) -> std::map<Mode, std::string>;
    };
}
