#pragma once

#include <map>

class Plugboard {
    // Max 13 connections = 26 values in map
    std::map<unsigned char, unsigned char> connections;
};
