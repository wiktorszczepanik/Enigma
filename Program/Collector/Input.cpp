#include <cctype>
#include <map>
#include <stdexcept>
#include <vector>
#include <map>
#include <algorithm>
#include <filesystem>

#include "Input.hpp"

namespace input {

    Flags::Flags(std::vector<std::string>& input) {
        if (input.size() != 4) throw std::invalid_argument(
            "Incorrect number of arguments.\n");
        flags = struct_transform(input);
    }

    auto Flags::struct_transform(std::vector<std::string> input) -> std::map<Mode, std::string> {
        auto inner_flags = std::map<Mode, std::string>();
        for (auto i = input.begin(); i != input.end(); ++i) {
            if (*i == "-t" || *i == "--text")
                inner_flags[Mode::CRYPT] = *++i;
            else if (*i == "-s" || *i == "--setup")
                inner_flags[Mode::SETUP] = *++i;
            else throw std::invalid_argument("Invalid argument.");
        }
        if (inner_flags.size() != 2) throw std::invalid_argument(
            "Allowed flags are \'--text\' and \'--setup\'.");
        return inner_flags;
    }

    auto Flags::validate() -> void {
        namespace fs = std::filesystem;
        auto valid_t = false, valid_s = false;
        auto text = flags[Mode::CRYPT];
        valid_t = std::all_of(text.begin(), text.end(), [] (char c) {
            return std::isalpha(c);
        }) && text.size() != 0;
        if (!valid_t) throw std::invalid_argument(
            "The text contains other characters besides letters.");
        auto setup = flags[Mode::SETUP];
        valid_s = fs::exists(setup) && fs::is_regular_file(setup);
        if (!valid_s) throw std::invalid_argument(
            "The path does not exist or is not a file.");
    }

    auto Flags::get_action() -> std::pair<Mode, std::string> {
        return std::pair<Mode, std::string>(Mode::CRYPT, flags[Mode::CRYPT]);
    }

    auto Flags::get_setup() -> std::pair<Mode, std::string> {
            return std::pair<Mode, std::string>(Mode::SETUP, flags[Mode::SETUP]);
    }

}
