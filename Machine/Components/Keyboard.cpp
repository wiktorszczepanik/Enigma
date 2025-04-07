#include <vector>
#include <string>
#include <stdexcept>

#include "Keyboard.hpp"


Keyboard::Keyboard() {
    letters = std::string("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

auto Keyboard::forward(char letter) -> int {
    return letters.find(letter);
}

auto Keyboard::backward(int signal) -> char {
    return letters.at(signal);
}

namespace machine::keyboard {

    auto type_in(int argc, char* argv[]) -> std::vector<std::string> {
        auto flags = std::vector<std::string>();
        auto in_quotes = false;
        auto modified_flag = std::string({});
        for (int i = 1; i < argc; i++) {
            auto arg = std::string(argv[i]);
            if (arg.front() == '"' && !in_quotes) {
                modified_flag = arg.erase(0, 1);
                in_quotes = true;
            } else if (arg.back() == '"' && in_quotes) {
                modified_flag.append(" " + arg.erase(arg.size() - 1, 1));
                in_quotes = false;
            } else if (in_quotes)
                modified_flag.append(" " + arg);
            else flags.push_back(argv[i]);
        }
        if (in_quotes)
            throw std::invalid_argument(
                "Unclosed quotes in last argument.");
        return flags;
    }

}
