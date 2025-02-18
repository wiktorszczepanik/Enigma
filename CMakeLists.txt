cmake_minimum_required(VERSION 3.29)
project(Enigma)

set(CMAKE_CXX_STANDARD 20)

add_executable( enigma
        main.cpp
target_link_libraries(enigma fmt)
