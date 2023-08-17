QT += \
    core gui \
    widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

LIBS+=-L/usr/local/lib -lprotoc -lprotobuf
INCLUDEPATH += /usr/local/include

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    protobuf/schema.pb.cc \
    game/bitboard.cpp \
    game/board.cpp \
    game/game.cpp \
    game/piece.cpp \
    game/pieces/bishop.cpp \
    game/pieces/king.cpp \
    game/pieces/knight.cpp \
    game/pieces/pawn.cpp \
    game/pieces/queen.cpp \
    game/pieces/rook.cpp \
    main.cpp \
    mainwindow.cpp \
    networkinterface.cpp


HEADERS += \
    protobuf/schema.pb.h \
    $$files("*.hpp", true) \
    $$files("*.ipp", true) \
    game/bit_masks.hpp \
    game/bitboard.hpp \
    game/board.hpp \
    game/game.hpp \
    game/piece.hpp \
    game/pieces/bishop.hpp \
    game/pieces/king.hpp \
    game/pieces/knight.hpp \
    game/pieces/pawn.hpp \
    game/pieces/queen.hpp \
    game/pieces/rook.hpp \
    game/player.hpp \
    mainwindow.h \
    networkinterface.h \
    protobuf/schema.pb.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

