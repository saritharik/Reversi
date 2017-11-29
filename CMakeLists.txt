cmake_minimum_required(VERSION 3.8)
project(Ex2)

#set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(src lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)
set(SOURCE_FILES BoardConsole.cpp BoardConsole.h GameLogic.cpp GameLogic.h
        Point.cpp Point.h Board.h Player.h Human.cpp Human.h AI.cpp AI.h Game.cpp Game.h)
set(TEST_FILES tests/BoardTest.cpp
        tests/BoardTest.h tests/AITest.cpp tests/AITest.h tests/HumanTest.cpp tests/HumanTest.h
        tests/PointTest.cpp tests/PointTest.h  tests/GameLogicTest.cpp tests/GameLogicTest.h)

add_executable(Ex2 ${SOURCE_FILES} main.cpp)
add_executable(tests ${SOURCE_FILES} ${TEST_FILES} tests/gtest_main.cpp)

target_link_libraries(tests gtest gtest_main gmock)