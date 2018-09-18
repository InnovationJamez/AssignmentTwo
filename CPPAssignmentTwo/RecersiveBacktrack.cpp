//
// Created by lehoej on 9/16/2018.
//

#include "RecersiveBacktrack.h"

//constructor
RecersiveBacktrack::RecersiveBacktrack(int width, int height) : GrowingTree(width,height){
    addLocation();
}

// growing tree loop
void RecersiveBacktrack::buildLoop(){
    selectPiece();
    carvePath();
}

// select newest piece from the map
void RecersiveBacktrack::selectPiece(){

}

// adding location to the top of the map
void RecersiveBacktrack::addLocation(){

}

// pop one location off the top of the stack
void RecersiveBacktrack::backTrack(){

}