//
// Created by lehoej on 9/14/2018.
//

#ifndef CPPASSIGNMENTTWO_GROWINGTREE_H
#define CPPASSIGNMENTWO_GROWINGTREE_H

enum DIRECTION{
    NORTH = 1;
    SOUTH = 2;
    EAST = 3;
    WEST = 4;
};

struct Cell{
    int dispo; // use bin vallue
};

struct coords
{
    int xPos, yPos;
};

class GrowingTree {
private:
    stack<int, int> mazeStack;
    vector<vector<Cell>> board;
    coords position;
public:
    // setPath this can also be done as part of the direction selector
    void storeNorth();

    void storeSouth();

    void storeEast();

    void storeWest();

    // set visited

    void setVisited();

    // constructor maybe do something
    GrowingTree();

    // de-constructor possibly use to deallocate the memory taken up by the object
    ~GrowingTree();

    // growing tree loop
    void buildLoop();

    // check surounding cells
    DIRECTION neighborChk(int coordX, int coordY);

    // move in direction and carve path
    void carvePath(int coordX, int coordY);

    // generate random number
    int generateRandom(int max);

    // adding location to the top of tha stack
    void addingOnTop(int coordX, int coordY);

    // pop one location off the top of the stack
    void backTrack();
};


#endif //CPPASSIGNMENTTWO_GROWINGTREE_H
