cmake_minimum_required(VERSION 3.0.0)
project(Chess-Server)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall")

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/externals)
include_directories(${CMAKE_SOURCE_DIR}/externals/asio)
include_directories(${CMAKE_SOURCE_DIR}/game_engine)
include_directories(${CMAKE_SOURCE_DIR}/pieces)
include_directories(${CMAKE_SOURCE_DIR}/protobuf)

LINK_DIRECTORIES(/usr/local/lib)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(SOURCE
    ${SOURCE}
    ${PROTO_SRCS}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/networkinterface.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/schema.pb.cc

    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/piece.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/game.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/board.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/bitboard.cpp
    
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/pieces/bishop.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/pieces/king.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/pieces/knight.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/pieces/pawn.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/pieces/queen.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/pieces/rook.cpp
  )

set(HEADERS
    ${HEADERS}
    ${PROTO_HDRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/networkinterface.h

    ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/schema.pb.h

    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/spots_enum.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/player.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/piece.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/game.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/board.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/bitboard.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/bit_masks.hpp
 
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/pieces/bishop.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/pieces/king.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/pieces/knight.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/pieces/pawn.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/pieces/queen.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine/pieces/rook.hpp
)

add_executable(chess.bin ${SOURCE} ${HEADERS})

target_link_libraries(chess.bin ${Protobuf_LIBRARIES})
target_link_libraries(chess.bin protoc protobuf)