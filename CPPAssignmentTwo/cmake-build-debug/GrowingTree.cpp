//
// Created by lehoej on 9/14/2018.
//

#include "GrowingTree.h"

#include <iostream>
#include <stack>
#include <random>
using namespace std;

// constructor maybe do something
GrowingTree::GrowingTree() {

}

// de-constructor possibly use to deallocate the memory taken up by the object
GrowingTree::~GrowingTree() {

}

// growing tree loop
void GrowingTree::buildLoop() {
    while(maze.isEmpty()==false){
        neighbourcellcheck(randx, randy); //select random coordinates for starting point of maze gen
    }
}

// check surounding cells
DIRECTION GrowingTree::neighborChk(int coordX, int coordY){
    if(){ // temporary value
        return true;
    }//check comparative checkers for available neighbour cells
    else{
        return false;
    }
}
void GrowingTree::carvePath(int coordX, int coordY){

    if(neighbourcellcheck(coordX, coordY)==false){
        BackstackingTree(coordX, coordY);
    }
    else {
        AddingOnTree(coordX, coordY);
    }
}
void GrowingTree::addingOnTop(int coordX, int coordY){
    mazeStack.push(coordX, coordY);
}
void GrowingTree::backTrack(){
    mazeStack.pop(// pop off one location);
}

int GrowingTree::generateRandom(int max){

}

// set the path of the of maze
void GrowingTree::storeNorth(){

}

void GrowingTree::storeNorth() {

}

void GrowingTree::storeSouth(){

}

void GrowingTree::storeEast(){

}

void GrowingTree::storeWest(){

}

// set visited

void GrowingTree::setVisited(){

}