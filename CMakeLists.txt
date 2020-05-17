cmake_minimum_required(VERSION 3.15)
project(POO2Labo4_2020)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(POO2Labo4_2020
        Action.cpp
        Action.h
        Buffy.cpp
        Buffy.h
        Controller.cpp
        Controller.h
        Field.cpp
        Field.h
        Grille.cpp
        Grille.h
        Humain.cpp
        Humain.h
        Humanoid.cpp
        Humanoid.h
        main.cpp
        Vampire.cpp
        Vampire.h)
