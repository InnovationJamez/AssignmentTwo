cmake_minimum_required(VERSION 3.12)
project(CPPAssignmentTwo)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_Flags "${CMAKE_CXX_FLAGS} -Wall -pedantic")

find_package(Boost)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif()

add_executable(CPPAssignmentTwo
        SourceFiles/builder.cpp

        HeaderFiles/GrowingTree.h
        SourceFiles/GrowingTree.cpp

        HeaderFiles/PrimAlgorithm.h
        SourceFiles/PrimAlgorithm.cpp

        HeaderFiles/RecursiveBacktrack.h
        SourceFiles/RecursiveBacktrack.cpp

        SourceFiles/MazeLoader.cpp
        HeaderFiles/MazeLoader.h
        )
