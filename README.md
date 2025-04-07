## Enigma

This is a C++ implementation of an Enigma machine, inspired by the historical cipher machine used during World War II. It mimics the encryption process using rotors, plugboards, and a reflector. The program takes an input message (-t), encrypts it using the settings provided by the user (-s), and outputs the encrypted message.

### Features

- Rotor-based encryption: Simulates the encryption process using rotors, similar to the original Enigma machine.
- Plugboard simulation: Mimics the plugboard used in the Enigma machine for additional letter swapping.
- Reflector functionality: Implements the reflector mechanism, which reflects the signal back through the rotors.

### Flags

Flag    | Alias     | Description
--------|-----------|---------------------------------------------------------------------------------
-t      | --text    | Specifies the message to be encrypted.
-s      | --setup   | Specifies the setup file that contains the rotor, plugboard and reflector configuration.

### Examples

```Bash
$ ./enigma -t "HelloWorld" -s ../Config/setup1
QBTGBGDQYP
```
```Bash
$ ./enigma --text "test" --setup ../Config/setup1
GBFW
```

### Requirements

To use this program, ensure you have a compatible **C++** compiler and **cmake** to build the project.
```cmake
cmake_minimum_required(VERSION 3.29)
set(CMAKE_CXX_STANDARD 20)
```
