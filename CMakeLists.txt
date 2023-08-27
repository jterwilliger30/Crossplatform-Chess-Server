cmake_minimum_required(VERSION 3.0.0)
project(Chess-Server)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS "-Wall -g")
set(Protobuf_USE_STATIC_LIBS ON)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/externals)
include_directories(${CMAKE_SOURCE_DIR}/externals/asio)
include_directories(${CMAKE_SOURCE_DIR}/game_engine)
include_directories(${CMAKE_SOURCE_DIR}/pieces)
include_directories(${CMAKE_SOURCE_DIR}/protobuf)

IF (WIN32)
  message("------ Windows detected ------\n")

  #add_library(protobuf STATIC IMPORTED) # or STATIC instead of SHARED
  #set_target_properties(protobuf PROPERTIES
  #  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/libbar.so"
  #  INTERFACE_INCLUDE_DIRECTORIES "C:\Program Files (x86)\protobuf\include"
  #)

  #LINK_DIRECTORIES("C:/Program Files (x86)/protobuf/lib")
  find_package(Protobuf CONFIG REQUIRED
    HINTS
      ${CMAKE_SOURCE_DIR}/externals/protobuf-21.12/build/Release
      #"C:/Program Files/protobuf"
      #"C:/Program Files (x86)/protobuf"
      )
ELSE()
  LINK_DIRECTORIES(/usr/local/lib) #make cross-platform
  find_package(Protobuf REQUIRED)
ENDIF()

IF (Protobuf_FOUND)
  message("\nPROTOBUF FOUND\n")
ELSE()
  message("\nProtobuf not found....\n")
ENDIF()


#include_directories(${Protobuf_INCLUDE_DIRS})
#include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(SOURCE
    ${SOURCE}
    ${PROTO_SRCS}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/networkinterface.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerInterface.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/schema.pb.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/protobuf_asio_interface.cpp

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
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerInterface.hpp

    ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/schema.pb.h
    ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/protobuf_asio_interface.hpp

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

#target_link_libraries(chess.bin ${Protobuf_PROTOC_LIBRARIES} ${Protobuf_LIBRARIES})
#target_link_libraries(chess.bin protobuf protoc)
target_link_libraries(chess.bin PUBLIC protobuf::libprotoc protobuf::libprotobuf)