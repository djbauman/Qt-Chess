#-------------------------------------------------
#
# Project created by QtCreator 2019-03-13T16:23:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chess-7
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

SOURCES += \
    display.cpp \
    main.cpp \
    space.cpp \
    chess-files/Bishop.cpp \
    chess-files/Board.cpp \
    chess-files/Game.cpp \
    chess-files/King.cpp \
    chess-files/Knight.cpp \
    chess-files/Pawn.cpp \
    chess-files/Piece.cpp \
    chess-files/Queen.cpp \
    chess-files/Rook.cpp \
    chess-files/Square.cpp

HEADERS += \
    display.h \
    space.h \
    chess-files/Bishop.hpp \
    chess-files/Board.hpp \
    chess-files/Game.hpp \
    chess-files/King.hpp \
    chess-files/Knight.hpp \
    chess-files/Pawn.hpp \
    chess-files/Piece.hpp \
    chess-files/Queen.hpp \
    chess-files/Rook.hpp \
    chess-files/Square.hpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
