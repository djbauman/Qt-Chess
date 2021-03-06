cmake_minimum_required(VERSION 3.13)
project(Capstone)

set(CMAKE_CXX_STANDARD 17)
add_compile_options("-W" "-Wall" "-O3" "-pedantic")

# Test runner (speeds compilation)
add_library(TestRunner STATIC
		test/TestRunner.cpp)

# Main
add_executable(Main
		source/main.cpp
		source/Game.hpp
		source/Game.cpp
		source/Board.hpp
		source/Board.cpp
		source/Piece.hpp
		source/Piece.cpp
		source/Square.hpp
		source/Square.cpp
		source/Pawn.hpp
		source/Pawn.cpp
		source/Rook.hpp 
		source/Rook.cpp
		source/Bishop.hpp 
		source/Bishop.cpp 
		source/Knight.hpp 
		source/Knight.cpp 
		source/King.hpp 
		source/King.cpp
		source/Queen.hpp
		source/Queen.cpp)

# Tests
add_executable(BoardTest
		test/BoardTest.cpp
		source/Game.hpp
		source/Game.cpp
		source/Board.hpp
		source/Board.cpp
		source/Piece.hpp
		source/Piece.cpp
		source/Square.hpp
		source/Square.cpp
		source/Pawn.hpp
		source/Pawn.cpp
		source/Rook.hpp 
		source/Rook.cpp
		source/Bishop.hpp 
		source/Bishop.cpp 
		source/Knight.hpp 
		source/Knight.cpp 
		source/King.hpp 
		source/King.cpp
		source/Queen.hpp
		source/Queen.cpp)
target_link_libraries(BoardTest TestRunner)

add_executable(GameTest
		test/GameTest.cpp
		source/Game.hpp
		source/Game.cpp
		source/Board.hpp
		source/Board.cpp
		source/Piece.hpp
		source/Piece.cpp
		source/Square.hpp
		source/Square.cpp
		source/Pawn.hpp
		source/Pawn.cpp
		source/Rook.hpp
		source/Rook.cpp
		source/Bishop.hpp
		source/Bishop.cpp
		source/Knight.hpp
		source/Knight.cpp
		source/King.hpp
		source/King.cpp
		source/Queen.hpp
		source/Queen.cpp)
target_link_libraries(BoardTest TestRunner)

add_executable(KingTest
		test/KingTest.cpp
		source/Game.hpp
		source/Game.cpp
		source/Board.hpp
		source/Board.cpp
		source/Piece.hpp
		source/Piece.cpp
		source/Square.hpp
		source/Square.cpp
		source/Pawn.hpp
		source/Pawn.cpp
		source/Rook.hpp
		source/Rook.cpp
		source/Bishop.hpp
		source/Bishop.cpp
		source/Knight.hpp
		source/Knight.cpp
		source/King.hpp
		source/King.cpp
		source/Queen.hpp
		source/Queen.cpp)
target_link_libraries(KingTest TestRunner)

add_executable(KnightTest
		test/KnightTest.cpp
		source/Game.hpp
		source/Game.cpp
		source/Board.hpp
		source/Board.cpp
		source/Piece.hpp
		source/Piece.cpp
		source/Square.hpp
		source/Square.cpp
		source/Pawn.hpp
		source/Pawn.cpp
		source/Rook.hpp
		source/Rook.cpp
		source/Bishop.hpp
		source/Bishop.cpp
		source/Knight.hpp
		source/Knight.cpp
		source/King.hpp
		source/King.cpp
		source/Queen.hpp
		source/Queen.cpp)
target_link_libraries(KnightTest TestRunner)

add_executable(BishopTest
		test/BishopTest.cpp
		source/Game.hpp
		source/Game.cpp
		source/Board.hpp
		source/Board.cpp
		source/Piece.hpp
		source/Piece.cpp
		source/Square.hpp
		source/Square.cpp
		source/Pawn.hpp
		source/Pawn.cpp
		source/Rook.hpp
		source/Rook.cpp
		source/Bishop.hpp
		source/Bishop.cpp
		source/Knight.hpp
		source/Knight.cpp
		source/King.hpp
		source/King.cpp
		source/Queen.hpp
		source/Queen.cpp)
target_link_libraries(KnightTest TestRunner)
