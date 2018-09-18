//
// Created by lehoej on 9/16/2018.
//

#ifndef CPPASSIGNMENTTWO_RECERSIVEBACKTRACK_H
#define CPPASSIGNMENTTWO_RECERSIVEBACKTRACK_H

#include<stack>
#include "GrowingTree.h"

class RecersiveBacktrack: public GrowingTree {
private:

public:
    // constructor
    RecersiveBacktrack(int width, int height);

    // growing tree loop
    void buildLoop ()override;

    // select newest piece from the map
    void selectPiece()override;

    // adding location to the top of the map
    void addLocation()override;

    // pop one location off the top of the stack
    void backTrack()override;
};


#endif // CPPASSIGNMENTTWO_RECERSIVEBACKTRACK_H
