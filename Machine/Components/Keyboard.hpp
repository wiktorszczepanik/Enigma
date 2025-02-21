#pragma once

#include <string>
#include <vector>

namespace machine::keyboard {
    auto type_in(int argc, char* argv[])
        -> std::vector<std::string>;
}
