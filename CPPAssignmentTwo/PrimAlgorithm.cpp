//
// Created by lehoej on 9/14/2018.
//

#include "PrimAlgorithm.h"

// constructor
PrimAlgorithm::PrimAlgorithm(int width, int height) : GrowingTree(width,height)
{
    addLocation();
}

// select a random piece from the map
void PrimAlgorithm::selectPiece(){
    generateRandom(mapTree->size());
    auto it = mapTree->begin();
    std::advance(it,this->randNum);
    this->index = it->first;
    this->position = (*mapTree)[index];
}

// adding location to the top of the map
void PrimAlgorithm::addLocation(){
    (*mapTree)[index] = {this->position.xPos,this->position.yPos};
}

// delete the current location from map
void PrimAlgorithm::backTrack(){
    mapTree->erase(index);
}

// growing tree loop
void PrimAlgorithm::buildLoop(){
    while(!mapTree->empty()){
        selectPiece();
        carvePath();
    }
}

// carve path
void GrowingTree::carvePath(){
    DIRECTION choice = neighborChk();
    switch(choice){
        case NORTH:
            moveNorth();
            addLocation();
            break;
        case SOUTH:
            moveSouth();
            addLocation();
            break;
        case EAST:
            moveEast();
            addLocation();
            break;
        case WEST:
            moveWest();
            addLocation();
            break;
        case EMPTY:
            backTrack();
            break;
        default:
            std::cout << "there has been an error" << std::endl;
            break;
    }
}