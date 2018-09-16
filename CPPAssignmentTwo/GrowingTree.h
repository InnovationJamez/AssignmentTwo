//
// Created by lehoej on 9/14/2018.
//

#ifndef CPPASSIGNMENTTWO_GROWINGTREE_H
#define CPPASSIGNMENTTWO_GROWINGTREE_H

#include <iostream>
#include <random>
#include <map>

enum DIRECTION{
    NORTH = 1,
    SOUTH = 2,
    EAST = 3,
    WEST = 4,
    EMPTY = 5
};

struct disposition{
    int binVal;
    disposition():binVal(0b00000){}
};

struct coords{
    int xPos, yPos;
};

class GrowingTree {
private:
    std::vector<std::vector<disposition>>* board = new std::vector<std::vector<disposition>>;
    coords position;
    std::map<int,coords>* mapTree = new std::map<int, coords>;
    int randNum, width, height, index;

public:

    // generate random number
    void generateRandom(int max);

    // set location
    void setLocation();

    // createBoard
    void fillBoard();

    // set path functions set the direction of the path
    void storeNorth();

    void storeSouth();

    void storeEast();

    void storeWest();

    // move functions move in specified direction

    void moveNorth();
    void moveSouth();
    void moveEast();
    void moveWest();

    // check functions check the neighbors return result

    bool checkNorth();
    bool checkSouth();
    bool checkEast();
    bool checkWest();

    // check surounding cells
    DIRECTION neighborChk();

    // set visited
    void setVisited();

    // fill board generate & start point
    GrowingTree(int x, int y);

    // de-constructor deallocate the memory taken up by the object
    ~GrowingTree();

    // growing tree loop
    void buildLoop();

    // move in direction and carve path
    void carvePath();

    // select newest piece from the map
    virtual void selectPiece();

    // adding location to the top of tha stack
    virtual void addLocation();

    // pop one location off the top of the stack
    virtual void backTrack();
};


#endif // CPPASSIGNMENTTWO_GROWINGTREE_H
