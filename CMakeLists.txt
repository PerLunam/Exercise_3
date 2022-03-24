cmake_minimum_required(VERSION 3.21)
project(Exercise_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Exercise_3
        character.cpp
        character.h
        fighter.cpp
        fighter.h
        hero.cpp
        hero.h
        item.cpp
        item.h
        main.cpp
        npc.cpp
        npc.h
        sorcerer.cpp
        sorcerer.h
        type.h)
