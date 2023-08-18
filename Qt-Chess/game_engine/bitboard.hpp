#ifndef BITBOARD_H
#define BITBOARD_H

#include <cstdint>

#include "./spots_enum.hpp"

class Bitboard {

public:
    uint64_t bitboard;

    Bitboard();
    Bitboard(uint64_t);

    void print_board();
    void set_bit(Spot);
    void pop_bit(Spot);
    bool is_occupied(Spot);
};
#endif