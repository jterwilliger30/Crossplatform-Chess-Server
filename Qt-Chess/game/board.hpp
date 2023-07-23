#ifndef BOARD_H
#define BOARD_H

#include <utility>

#include "player.hpp"
#include "bitboard.hpp"

#include "./pieces/pawn.hpp"
#include "./pieces/bishop.hpp"
#include "./pieces/rook.hpp"
#include "./pieces/king.hpp"
#include "./pieces/queen.hpp"
#include "./pieces/knight.hpp"

class Board {
public:
    Board(PlayerSPtr p1, PlayerSPtr p2, BitboardSPtr GAMESTATE, BitboardSPtr P1_OCCUPIED, BitboardSPtr P2_OCCUPIED);

    BitboardSPtr gamestate;
    BitboardSPtr p1_occupied;
    BitboardSPtr p2_occupied;

    void update_board_state();
    void reset_board();
    void print_board();

    void preview_turn(PlayerSPtr player);
    void take_turn(PlayerSPtr player, Spot start, Spot end);

//private:
    PlayerSPtr player1;
    PlayerSPtr player2;

    const std::shared_ptr<Pawnboard> p1_pawn;
    const std::shared_ptr<Bishopboard> p1_bishop;
    const std::shared_ptr<Rookboard> p1_rook;
    const std::shared_ptr<Knightboard> p1_knight;
    const std::shared_ptr<Queenboard> p1_queen;
    const std::shared_ptr<Kingboard> p1_king;

    const std::shared_ptr<Pawnboard> p2_pawn;
    const std::shared_ptr<Bishopboard> p2_bishop;
    const std::shared_ptr<Rookboard> p2_rook;
    const std::shared_ptr<Knightboard> p2_knight;
    const std::shared_ptr<Queenboard> p2_queen;
    const std::shared_ptr<Kingboard> p2_king;
};
#endif