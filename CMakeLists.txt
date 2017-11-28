cmake_minimum_required(VERSION 3.8)
project(Ex2)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp BoardConsole.cpp BoardConsole.h GameLogic.cpp GameLogic.h Point.cpp Point.h Board.h Player.h Human.cpp Human.h AI.cpp AI.h Game.cpp Game.h)
add_executable(Ex2 ${SOURCE_FILES})