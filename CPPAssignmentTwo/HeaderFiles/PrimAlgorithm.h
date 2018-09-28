//
// Created by lehoej on 9/14/2018.
//

#ifndef CPPASSIGNMENTTWO_PRIMALGORITHM_H
#define CPPASSIGNMENTTWO_PRIMALGORITHM_H

#include "../HeaderFiles/GrowingTree.h"

class PrimAlgorithm: public GrowingTree {
private:
public:
    // constructor
    PrimAlgorithm(int width, int height, std::string binFileName);
    // select newest piece from the map
    inline void selectPiece()override;

    // adding location to the top of the map
    void addLocation()override;

    // pop one location off the top of the stack
    void backTrack()override;

    // growing tree loop
    void buildLoop()override;
};


#endif // CPPASSIGNMENTTWO_PRIMALGORITHM_H
