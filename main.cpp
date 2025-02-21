#include <exception>
#include <iostream>

#include "Program/Collector/Input.hpp"
#include "Program/Tuples/Action.hpp"
#include "Program/Tuples/Setup.hpp"
#include "Machine/Enigma.hpp"
#include "Machine/Components/Keyboard.hpp"
#include "Machine/Components/Lampboard.hpp"

auto main(int argc, char* argv[]) -> int {
    try {
        auto input_values = machine::keyboard::type_in(argc, argv);
        auto flags = input::Flags(input_values);
        flags.validate();
        auto action = Action(flags.get_action());
        action.util();
        auto setup = Setup(flags.get_setup());
        setup.util();
        auto enigma = Enigma(setup, action);
        auto output = enigma.calculate();
        machine::lampboard::lights(output);
    } catch(std::exception& exception) {
        std::cout << exception.what();
        return 1;
    }
    return 0;
}
