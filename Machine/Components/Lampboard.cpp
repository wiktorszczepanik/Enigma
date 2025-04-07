#include <iostream>
#include <iterator>

#include "Lampboard.hpp"

namespace machine::lampboard {
    auto lights(std::string text) -> void {
        std::cout << text << std::endl;
    }
}
