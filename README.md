## Enigma

This is a C++ implementation of an Enigma machine, inspired by the historical cipher machine used during World War II. It mimics the encryption process using rotors, plugboards, and a reflector. The program takes an input message (-t), encrypts it using the settings provided by the user (-s), and outputs the encrypted message. The values used for machine components are based on the settings used in the early models of the "Enigma I" machine.

### Features

- Rotor-based encryption: Simulates the encryption process using rotors, same as original Enigma machine.
- Plugboard simulation: Mimics the plugboard used in the Enigma machine for additional letter swapping.
- Reflector functionality: Implements the reflector mechanism, which reflects the signal back through the rotors.

### Flags
The program supports the following command-line flags:
Flag    | Alias     | Description
--------|-----------|---------------------------------------------------------------------------------
--text  | -t        | Specifies the message to be encrypted.
--setup | -s        | Specifies the setup file that contains the rotor, plugboard and reflector configuration.

### Example
In the Enigma machine, the processes of encryption and decryption are identical, meaning that to decrypt a message, you use the same procedure as for encryption:
```Bash
$ ./enigma -t "HelloWorld" -s ../Config/setup1
QBTGBGDQYP
$ ./enigma --text "QBTGBGDQYP" --setup ../Config/setup1
HELLOWORLD
```

### Requirements

To use this program, ensure you have a compatible **C++** compiler and **cmake** to build the project.
```cmake
cmake_minimum_required(VERSION 3.29)
set(CMAKE_CXX_STANDARD 20)
```
