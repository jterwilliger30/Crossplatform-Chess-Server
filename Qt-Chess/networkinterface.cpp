#include "networkinterface.h"

#include <iostream>

#include "protobuf/schema.pb.h"

#include "game_engine/pieces/pawn.hpp"
#include "game_engine/pieces/bishop.hpp"
#include "game_engine/pieces/king.hpp"
#include "game_engine/pieces/queen.hpp"
#include "game_engine/pieces/knight.hpp"
#include "game_engine/pieces/rook.hpp"


NetworkInterface::NetworkInterface()
{

}

void NetworkInterface::sendGameState(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2)
{
    GameState gamestate_protobuf;

    gamestate_protobuf.set_p1_pawn(std::dynamic_pointer_cast<Pawnboard>(p1->pieceboard_map['P'])->pieceboard.bitboard);
    gamestate_protobuf.set_p2_pawn(std::dynamic_pointer_cast<Pawnboard>(p2->pieceboard_map['P'])->pieceboard.bitboard);

    gamestate_protobuf.set_p1_bishop(std::dynamic_pointer_cast<Bishopboard>(p1->pieceboard_map['B'])->pieceboard.bitboard);
    gamestate_protobuf.set_p2_bishop(std::dynamic_pointer_cast<Bishopboard>(p2->pieceboard_map['B'])->pieceboard.bitboard);

    gamestate_protobuf.set_p1_rook(std::dynamic_pointer_cast<Rookboard>(p1->pieceboard_map['R'])->pieceboard.bitboard);
    gamestate_protobuf.set_p2_rook(std::dynamic_pointer_cast<Rookboard>(p2->pieceboard_map['R'])->pieceboard.bitboard);

    gamestate_protobuf.set_p1_king(std::dynamic_pointer_cast<Kingboard>(p1->pieceboard_map['K'])->pieceboard.bitboard);
    gamestate_protobuf.set_p2_king(std::dynamic_pointer_cast<Kingboard>(p2->pieceboard_map['K'])->pieceboard.bitboard);

    gamestate_protobuf.set_p1_queen(std::dynamic_pointer_cast<Queenboard>(p1->pieceboard_map['P'])->pieceboard.bitboard);
    gamestate_protobuf.set_p2_queen(std::dynamic_pointer_cast<Queenboard>(p2->pieceboard_map['P'])->pieceboard.bitboard);

    gamestate_protobuf.set_p1_knignt(std::dynamic_pointer_cast<Knightboard>(p1->pieceboard_map['N'])->pieceboard.bitboard);
    gamestate_protobuf.set_p2_knignt(std::dynamic_pointer_cast<Knightboard>(p2->pieceboard_map['N'])->pieceboard.bitboard);

    size_t message_size = gamestate_protobuf.ByteSizeLong();
    char* buffer = new char[message_size];

    //if (!(gamestate_protobuf.SerializeToArray(buffer, message_size)))
    {
    //    throw std::invalid_argument("Protobuf serialization failed");
    }

    
    //std::cout << buffer;
    delete buffer;
}

void NetworkInterface::ClientConnect()
{

}

void NetworkInterface::ServerListen()
{

}
