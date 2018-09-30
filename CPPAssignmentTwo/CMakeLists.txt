cmake_minimum_required(VERSION 3.12)
project(CPPAssignmentTwo)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLGAS "${CMAKE_CXX_FLAGS} ${extra_flags} -Wall -pedantic -std=c++14")
find_package(Boost)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif()

add_executable(CPPAssignmentTwo
        SourceFiles/builder.cpp

        HeaderFiles/GrowingTree.h
        SourceFiles/GrowingTree.cpp

        HeaderFiles/RecursiveBacktrack.h
        SourceFiles/RecursiveBacktrack.cpp

        HeaderFiles/PrimAlgorithm.h
        SourceFiles/PrimAlgorithm.cpp

        HeaderFiles/BinaryGenerator.h
        SourceFiles/BinaryGenerator.cpp

        HeaderFiles/MazeLoader.h
        SourceFiles/MazeLoader.cpp
        )
