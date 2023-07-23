#include <bitset>
#include <iostream>

#include "./bitboard.hpp"

Bitboard::Bitboard()
{
    bitboard = 0;
}

Bitboard::Bitboard(uint64_t val)
{
    bitboard = val;
}



void Bitboard::print_board()
{
    std::bitset<64> bitset = this->bitboard;

    // N.B. Bitsets index from L.S.B.
    for (int idx = 0; idx < 64; idx++)
    {
        if (idx % 8 == 0)
        {
            std::cout << "\n";
        }
        std::cout << bitset[63 - idx] << " ";


    }
    std::cout << std::endl;
}

void Bitboard::set_bit(Spot spt)
{
    std::bitset<64> bitset = this->bitboard;
    bitset.set( 63 - static_cast<unsigned int>(spt) , true);
    this->bitboard = (uint64_t) bitset.to_ullong();
}

void Bitboard::pop_bit(Spot spt)
{
    std::bitset<64> bitset = this->bitboard;
    bitset.set( 63 - static_cast<unsigned int>(spt) , false);
    this->bitboard = (uint64_t) bitset.to_ullong();
}

bool Bitboard::is_occupied(Spot spt)
{
    std::bitset<64> bitset = this->bitboard;
    return bitset[63 - static_cast<unsigned int>(spt)];
}
