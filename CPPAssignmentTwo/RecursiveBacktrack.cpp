//
// Created by lehoej on 9/16/2018.
//

#include "RecursiveBacktrack.h"

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
    mapStack.push(position);
}

// pop one location off the top of the stack
void RecursiveBacktrack::backTrack(){
    mapStack.pop(position);
}

// growing tree loop
void RecursiveBacktrack::buildLoop(){
    while(!mapStack.empty()){
        selectPiece();
        carvePath();
    }
}