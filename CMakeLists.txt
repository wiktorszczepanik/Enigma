cmake_minimum_required(VERSION 3.29)
project(Enigma)

set(CMAKE_CXX_STANDARD 20)

include_directories(
	Config
	Machine/Components
	Machine
	Program/Collector
	Program/Constants
	Program/Tuples
)

file(GLOB SOURCES
	main.cpp
	Machine/Components/*.cpp
	Machine/*.cpp
	Program/Collector/*.cpp
	Program/Tuples/*.cpp
)

add_executable(enigma ${SOURCES})
