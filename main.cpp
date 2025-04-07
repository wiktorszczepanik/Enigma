#include <exception>
#include <iostream>
#include <ios>

#include "Machine/Components/Rotor.hpp"
#include "Program/Collector/Input.hpp"
#include "Program/Tuples/Action.hpp"
#include "Program/Tuples/Setup.hpp"
#include "Machine/Enigma.hpp"
#include "Machine/Components/Keyboard.hpp"
#include "Machine/Components/Lampboard.hpp"

auto main(int argc, char* argv[]) -> int {
    try {
        auto input_values = machine::keyboard::type_in(argc, argv);
        auto flags = input::Flags(input_values); flags.validate();
        auto action = Action(flags.get_action());
        auto message = action.get_message();
        auto setup = Setup(flags.get_setup());
        auto [rotors, plugboard, reflector, keyboard] = setup.util();
        auto enigma = Enigma(rotors, plugboard, reflector, keyboard);
        enigma.set_key();
        auto output_text = std::string();
        for (auto letter : message)
            output_text += enigma.calculate(letter);
        machine::lampboard::lights(output_text);
    } catch(std::exception& exception) {
        std::cout << exception.what() << std::endl;
        return 1;
    }
    return 0;
}
