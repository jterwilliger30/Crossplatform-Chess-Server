#include <memory>
#include <map>

#include "game_engine/piece.hpp"

class NetworkProtobufInterface {
public:
    std::unique_ptr<char[]> load_protobuffer(PlayerSPtr p1, PlayerSPtr p2);
    void unload_protobuffer(std::unique_ptr<char[]> data, size_t size, PlayerSPtr p1, PlayerSPtr p2);

    std::map<char, uint64_t> extractBitboards(PlayerSPtr player);

};