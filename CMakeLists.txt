cmake_minimum_required(VERSION 3.27)
project(C_Supinfo)

set(CMAKE_CXX_STANDARD 14)

include_directories(Include)

add_executable(C_Supinfo
        ../Source/main.cpp
        ../Source/Tiles.cpp
        ../Include/Tiles.h
        ../Include/Player.h
        ../Include/Board.h
        ../Source/Player.cpp
        ../Source/Board.cpp
        ../include/menu.h
        ../source/menu.cpp
        ../source/game.cpp
        ../include/game.h

    )
