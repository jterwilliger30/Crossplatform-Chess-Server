#include <cstdint>

#include "./spots_enum.h"

class Bitboard {

public:
    uint64_t bitboard;
    Bitboard();

    void print_board();
    void set_bit(Spot);
    void pop_bit(Spot);
};