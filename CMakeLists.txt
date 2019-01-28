cmake_minimum_required(VERSION 3.13)
project(Capstone)

set(CMAKE_CXX_STANDARD 17)

# Test runner (speeds compilation)
add_library(TestRunner STATIC
		test/TestRunner.cpp)

# Main
add_executable(Main
		source/main.cpp
		source/Board.cpp
		source/Piece.cpp
		source/Piece.hpp
		source/Square.cpp
		source/Square.hpp)

# Tests
add_executable(BoardTest
		test/BoardTest.cpp
		source/Board.cpp
		source/Piece.cpp
		source/Piece.hpp
		source/Square.cpp
		source/Square.hpp)
target_link_libraries(BoardTest TestRunner)