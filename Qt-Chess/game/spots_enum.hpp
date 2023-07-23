#ifndef SPOTS_H
#define SPOTS_H

#include <map>
#include <string>

enum class Spot : unsigned int {
    A8, B8, C8, D8, E8, F8, G8, H8,  // 0 - 7
    A7, B7, C7, D7, E7, F7, G7, H7,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A1, B1, C1, D1, E1, F1, G1, H1  // 56 - 63
};

namespace {
std::map<std::string, Spot> str_to_spot =  {   
    {"A8", Spot::A8}, {"B8", Spot::B8}, {"C8", Spot::C8}, {"D8", Spot::D8}, {"E8", Spot::E8},
     {"F8", Spot::F8}, {"G8", Spot::G8}, {"H8", Spot::H8},
    {"A7", Spot::A7}, {"B7", Spot::B7}, {"C7", Spot::C7}, {"D7", Spot::D7}, {"E7", Spot::E7},
     {"F7", Spot::F7}, {"G7", Spot::G7}, {"H7", Spot::H7},
    {"A6", Spot::A6}, {"B6", Spot::B6}, {"C6", Spot::C6}, {"D6", Spot::D6}, {"E6", Spot::E6},
     {"F6", Spot::F6}, {"G6", Spot::G6}, {"H6", Spot::H6},
    {"A5", Spot::A5}, {"B5", Spot::B5}, {"C5", Spot::C5}, {"D5", Spot::D5}, {"E5", Spot::E5},
     {"F5", Spot::F5}, {"G5", Spot::G5}, {"H5", Spot::H5},
    {"A4", Spot::A4}, {"B4", Spot::B4}, {"C4", Spot::C4}, {"D4", Spot::D4}, {"E4", Spot::E4},
     {"F4", Spot::F4}, {"G4", Spot::G4}, {"H4", Spot::H4},
    {"A3", Spot::A3}, {"B3", Spot::B3}, {"C3", Spot::C3}, {"D3", Spot::D3}, {"E3", Spot::E3},
     {"F3", Spot::F3}, {"G3", Spot::G3}, {"H3", Spot::H3},
    {"A2", Spot::A2}, {"B2", Spot::B2}, {"C2", Spot::C2}, {"D2", Spot::D2}, {"E2", Spot::E2},
     {"F2", Spot::F2}, {"G2", Spot::G2}, {"H2", Spot::H2},
    {"A1", Spot::A1}, {"B1", Spot::B1}, {"C1", Spot::C1}, {"D1", Spot::D1}, {"E1", Spot::E1},
     {"F1", Spot::F1}, {"G1", Spot::G1}, {"H1", Spot::H1}
};
};

#endif

