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
    GameState proto_state;

    std::map<char, uint64_t> p1_bitboards = extractBitboards(p1);
    std::map<char, uint64_t> p2_bitboards = extractBitboards(p2);

    proto_state.set_p1_pawn(p1_bitboards['P']);
    proto_state.set_p2_pawn(p2_bitboards['P']);

    proto_state.set_p1_knignt(p1_bitboards['N']);
    proto_state.set_p2_knignt(p2_bitboards['N']);

    proto_state.set_p1_rook(p1_bitboards['R']);
    proto_state.set_p2_rook(p2_bitboards['R']);

    proto_state.set_p1_bishop(p1_bitboards['B']);
    proto_state.set_p2_bishop(p2_bitboards['B']);

    proto_state.set_p1_king(p1_bitboards['K']);
    proto_state.set_p2_king(p2_bitboards['K']);

    proto_state.set_p1_queen(p1_bitboards['Q']);
    proto_state.set_p2_queen(p2_bitboards['Q']);

    size_t message_size = proto_state.ByteSizeLong();
    char* buffer = new char[message_size];

    if (!(proto_state.SerializeToArray(buffer, message_size)))
    {
        throw std::invalid_argument("Protobuf serialization failed");
    }
    
    delete buffer;
}

void NetworkInterface::ClientConnect()
{

}

void NetworkInterface::ServerListen()
{

}

std::map<char, uint64_t> NetworkInterface::extractBitboards(std::shared_ptr<Player> player)
{
    std::map<char, uint64_t> retVal;

    retVal['P'] = std::dynamic_pointer_cast<Pawnboard>(player->pieceboard_map['P'])->pieceboard.bitboard;
    retVal['N'] = std::dynamic_pointer_cast<Knightboard>(player->pieceboard_map['N'])->pieceboard.bitboard;
    retVal['R'] = std::dynamic_pointer_cast<Rookboard>(player->pieceboard_map['R'])->pieceboard.bitboard;
    retVal['B'] = std::dynamic_pointer_cast<Bishopboard>(player->pieceboard_map['B'])->pieceboard.bitboard;
    retVal['K'] = std::dynamic_pointer_cast<Kingboard>(player->pieceboard_map['K'])->pieceboard.bitboard;
    retVal['Q'] = std::dynamic_pointer_cast<Queenboard>(player->pieceboard_map['Q'])->pieceboard.bitboard;

    return retVal;
}
