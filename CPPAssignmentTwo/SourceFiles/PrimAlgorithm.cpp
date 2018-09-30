//
// Created by lehoej on 9/14/2018.
//

#include "../HeaderFiles/PrimAlgorithm.h"

// constructor
PrimAlgorithm::PrimAlgorithm(const int* width, const int* height,std::vector<std::vector<disposition>>* board) : GrowingTree(width,height,board)
{
    addLocation();
}

// select a random piece from the map
void PrimAlgorithm::selectPiece(){
    generateRandom(mapVector->size());
    this->index = randNum;
    this->position = (*mapVector)[index];
}

// adding location to the top of the map
void PrimAlgorithm::addLocation(){
    (*mapVector).push_back(position);
}

// delete the current location from map
void PrimAlgorithm::backTrack(){
    (*mapVector).erase((*mapVector).begin() + index);
}

// growing tree loop
void PrimAlgorithm::buildLoop(){
    while(!mapVector->empty()){
        selectPiece();
        carvePath();
    }
}

// carve path
void PrimAlgorithm::carvePath(){
    DIRECTION choice = neighborChk();
    switch(choice){
        case NORTH:
            moveNorth();
            addLocation();
            setVisited();
            break;
        case SOUTH:
            moveSouth();
            addLocation();
            setVisited();
            break;
        case EAST:
            moveEast();
            addLocation();
            setVisited();
            break;
        case WEST:
            moveWest();
            addLocation();
            setVisited();
            break;
        case EMPTY:
            backTrack();
            break;
        default:
            std::cout << "there has been an error" << std::endl;
            break;
    }
}