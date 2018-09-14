//
// Created by lehoej on 9/14/2018.
//

#include "growingTree.h"

#include <iostream>
#include <stack>
#include <random>
using namespace std;

GrowingTree::GrowingTree() {

}
GrowingTree::~GrowingTree() {

}

void GrowingTree::growingTreeMain() {
    while(maze.isEmpty()==false){
        neighbourcellcheck(randx, randy); //select random coordinates for starting point of maze gen
    }
}
bool GrowingTree::neighborChk(int coordX, int coordY){
    if(){ // temporary value
        return true;
    }//check comparative checkers for available neighbour cells
    else{
        return false;
    }
}
void GrowingTree::pathChooser(int coordinatex, int coordinatey){

    if(neighbourcellcheck(coordX, coordY)==false){
        BackstackingTree(coordX, coordY);
    }
    else {
        AddingOnTree(coordX, coordY);
    }
}
void GrowingTree::addingOnTree(int coordX, int coordY){
    mazeStack.push(coordX, coordY);
}
void GrowingTree::backTrack(int coordX, int coordY){
    mazeStack.pop(coordX, coordY);
}