#include "protobuf_asio_interface.hpp"

#include "protobuf/schema.pb.h"

#include "game_engine/pieces/pawn.hpp"
#include "game_engine/pieces/bishop.hpp"
#include "game_engine/pieces/king.hpp"
#include "game_engine/pieces/queen.hpp"
#include "game_engine/pieces/knight.hpp"
#include "game_engine/pieces/rook.hpp"

std::unique_ptr<char[]> NetworkProtobufInterface::load_protobuffer(PlayerSPtr p1, PlayerSPtr p2)
{
    GameState proto_state;

    std::map<char, uint64_t> p1_bitboards = extractBitboards(p1);
    std::map<char, uint64_t> p2_bitboards = extractBitboards(p2);

    proto_state.set_p1_pawn(p1_bitboards['P']);
    proto_state.set_p2_pawn(p2_bitboards['P']);

    proto_state.set_p1_knight(p1_bitboards['N']);
    proto_state.set_p2_knight(p2_bitboards['N']);

    proto_state.set_p1_rook(p1_bitboards['R']);
    proto_state.set_p2_rook(p2_bitboards['R']);

    proto_state.set_p1_bishop(p1_bitboards['B']);
    proto_state.set_p2_bishop(p2_bitboards['B']);

    proto_state.set_p1_king(p1_bitboards['K']);
    proto_state.set_p2_king(p2_bitboards['K']);

    proto_state.set_p1_queen(p1_bitboards['Q']);
    proto_state.set_p2_queen(p2_bitboards['Q']);

    size_t message_size = proto_state.ByteSizeLong();
    std::unique_ptr<char[]> buffer(new char[message_size]);

    if (!(proto_state.SerializeToArray(&buffer[0], message_size)))
    {
        throw std::invalid_argument("Protobuf serialization failed");
    }

    return buffer;
}

void NetworkProtobufInterface::unload_protobuffer(std::unique_ptr<char[]> data, size_t size, PlayerSPtr p1, PlayerSPtr p2)
{
    GameState received_state;
    received_state.ParseFromArray(&data[0], size);

    p1->pieceboard_map['P']->pieceboard.bitboard = received_state.p1_pawn();
    p2->pieceboard_map['P']->pieceboard.bitboard = received_state.p2_pawn();

    p1->pieceboard_map['N']->pieceboard.bitboard = received_state.p1_knight();
    p2->pieceboard_map['N']->pieceboard.bitboard = received_state.p2_knight();

    p1->pieceboard_map['R']->pieceboard.bitboard = received_state.p1_rook();
    p2->pieceboard_map['R']->pieceboard.bitboard = received_state.p2_rook();

    p1->pieceboard_map['B']->pieceboard.bitboard = received_state.p1_bishop();
    p2->pieceboard_map['B']->pieceboard.bitboard = received_state.p2_bishop();

    p1->pieceboard_map['K']->pieceboard.bitboard = received_state.p1_king();
    p2->pieceboard_map['K']->pieceboard.bitboard = received_state.p2_king();

    p1->pieceboard_map['Q']->pieceboard.bitboard = received_state.p1_queen();
    p2->pieceboard_map['Q']->pieceboard.bitboard = received_state.p2_queen();
}

std::map<char, uint64_t> NetworkProtobufInterface::extractBitboards(PlayerSPtr player)
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
