#pragma once

#include <string>
#include <vector>

class Keyboard {
    std::string letters;
    public:
    Keyboard();
    auto forward(char) -> int;
    auto backward(int) -> char;
};

namespace machine::keyboard {
    auto type_in(int argc, char* argv[])
        -> std::vector<std::string>;
}
