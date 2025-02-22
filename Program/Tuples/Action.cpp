#include <algorithm>
#include <cctype>
#include <utility>

#include "Action.hpp"

Action::Action(std::pair<Mode, std::string> action) {
    mode = action.first;
    message = action.second;
    transform_message(message);
}

auto Action::get_message() -> std::string { return message; }

auto Action::transform_message(std::string& text) -> void {
    auto to_upper = [] (unsigned char c) { return std::toupper(c); };
    std::transform(text.begin(), text.end(), text.begin(), to_upper);
}
