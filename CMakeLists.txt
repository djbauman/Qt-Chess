cmake_minimum_required(VERSION 3.13)
project(Capstone)

set(CMAKE_CXX_STANDARD 17)

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
		source/Pawn.cpp)

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
		source/Pawn.cpp)
target_link_libraries(BoardTest TestRunner)