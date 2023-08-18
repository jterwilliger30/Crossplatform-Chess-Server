QT += \
    core gui \
    widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

LIBS+= -L/usr/local/lib -lprotoc -lprotobuf
INCLUDEPATH += \
    /usr/local/include \
    $$PWD/externals \
    $$PWD/externals/asio

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    protobuf/schema.pb.cc \
    game_engine/bitboard.cpp \
    game_engine/board.cpp \
    game_engine/game.cpp \
    game_engine/piece.cpp \
    game_engine/pieces/bishop.cpp \
    game_engine/pieces/king.cpp \
    game_engine/pieces/knight.cpp \
    game_engine/pieces/pawn.cpp \
    game_engine/pieces/queen.cpp \
    game_engine/pieces/rook.cpp \
    main.cpp \
    mainwindow.cpp \
    networkinterface.cpp

HEADERS += \
    protobuf/schema.pb.h \
    $$files("*.hpp", true) \
    $$files("*.ipp", true) \
    game_engine/bit_masks.hpp \
    game_engine/bitboard.hpp \
    game_engine/board.hpp \
    game_engine/game.hpp \
    game_engine/piece.hpp \
    game_engine/pieces/bishop.hpp \
    game_engine/pieces/king.hpp \
    game_engine/pieces/knight.hpp \
    game_engine/pieces/pawn.hpp \
    game_engine/pieces/queen.hpp \
    game_engine/pieces/rook.hpp \
    game_engine/player.hpp \
    mainwindow.h \
    networkinterface.h \
    protobuf/schema.pb.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

