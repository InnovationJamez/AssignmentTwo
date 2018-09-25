//
// Created by lehoej on 9/16/2018.
//

#include "../HeaderFiles/RecursiveBacktrack.h"

//constructor
RecursiveBacktrack::RecursiveBacktrack(int width, int height) : GrowingTree(width,height){
    addLocation();
}

// select newest piece from the map
void RecursiveBacktrack::selectPiece(){
    this->position = mapStack.top();
}

// adding location to the top of the map
void RecursiveBacktrack::addLocation(){
    mapStack.push(this->position);
}

// pop one location off the top of the stack
void RecursiveBacktrack::backTrack(){
    mapStack.pop();
}

// growing tree loop
void RecursiveBacktrack::buildLoop(){
    while(!mapStack.empty()){
        selectPiece();
        carvePath();
    }
}

// carve path
void RecursiveBacktrack::carvePath(){
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