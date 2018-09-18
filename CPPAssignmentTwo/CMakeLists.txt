cmake_minimum_required(VERSION 3.12)
project(CPPAssignmentTwo)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_Flags "${CMAKE_CXX_FLAGS} -Wall -pedantic")

add_executable(CPPAssignmentTwo
        builder.cpp
        GrowingTree.h
        GrowingTree.cpp
        PrimAlgorithm.h
        PrimAlgorithm.cpp
        RecursiveBacktrack.h
        RecursiveBacktrack.cpp
        )
