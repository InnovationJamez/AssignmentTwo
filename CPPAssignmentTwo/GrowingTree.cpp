//
// Created by lehoej on 9/14/2018.
//

#include "GrowingTree.h"

// fill board generate & start point
GrowingTree::GrowingTree(int x, int y)
        :width(x), height(y){
    this->index=0;
    fillBoard();
    setLocation();
    setVisited();
    addLocation();
}

// de-constructor deallocate the memory taken up by the object
GrowingTree::~GrowingTree() {
    delete board;
    delete mapTree;
}

// growing tree loop
void GrowingTree::buildLoop() {
    while(~mapTree->empty()){
        selectPiece();
        carvePath();
    }
}

// generate random number
void GrowingTree::generateRandom(int max){
    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_int_distribution<> dis(0, (max-1));
    this->randNum = dis(gen);
}

// set location
void GrowingTree::setLocation(){
    generateRandom(this->height);
    position.yPos = this->randNum;
    generateRandom(this->width);
    position.xPos = this->randNum;
}

// createBoard
void GrowingTree::fillBoard(){
    for(int row = 0;row<width; row++) {
        for(int col = 0; col<height; col++){
            disposition state;
            board[row][col].push_back(state);
        }
    }
}

// set the path of the of maze
void GrowingTree::storeNorth(){
    (*board)[this->position.xPos][this->position.yPos].binVal |= 10000;
}
void GrowingTree::storeSouth(){
    (*board)[this->position.xPos][this->position.yPos].binVal |= 01000;
}
void GrowingTree::storeEast(){
    (*board)[this->position.xPos][this->position.yPos].binVal |= 00100;
}
void GrowingTree::storeWest(){
    (*board)[this->position.xPos][this->position.yPos].binVal |= 00010;
}

// move functions: move in specified direction
void GrowingTree::moveNorth(){
    storeNorth();
    position.yPos--;
    storeSouth();
}
void GrowingTree::moveSouth(){
    storeSouth();
    position.yPos++;
    storeNorth();
}
void GrowingTree::moveEast(){
    storeEast();
    position.xPos++;
    storeWest();
}
void GrowingTree::moveWest(){
    storeWest();
    position.xPos--;
    storeEast();
}

// check functions check the neighbors return result
bool GrowingTree::checkNorth(){
    if((*board)[this->position.xPos][this->position.yPos-1].binVal & 0b00001
        && this->position.yPos != 0){
        return true;
    }
    else{
        return false;
    }
}
bool GrowingTree::checkSouth(){
    if((*board)[this->position.xPos][this->position.yPos+1].binVal & 0b00001
        && this->position.yPos != this->height-1){
        return true;
    }
    else{
        return false;
    }
}
bool GrowingTree::checkEast(){
    if((*board)[this->position.xPos+1][this->position.yPos].binVal & 0b00001
        && this->position.xPos != this->width-1){
        return true;
    }
    else{
        return false;
    }
}
bool GrowingTree::checkWest(){
    if((*board)[this->position.xPos-1][this->position.yPos].binVal & 0b00001
        && this->position.xPos != 0){
        return true;
    }
    else{
        return false;
    }
}

// check surounding cells
DIRECTION GrowingTree::neighborChk(){
    std::vector<DIRECTION> choice;
    if(checkNorth()){
        choice.push_back(NORTH);
    }else if(checkSouth()){
        choice.push_back(SOUTH);
    }else if(checkEast()){
        choice.push_back(EAST);
    }else if(checkWest()){
        choice.push_back(WEST);
    }if(choice.empty()){
        return EMPTY;
    }else{
        generateRandom(choice.size());
        return choice[this->randNum];
    }
}

// set visited
void GrowingTree::setVisited(){
    (*board)[this->position.xPos][this->position.yPos].binVal |= 00001;
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

// select the newest piece from the map
void GrowingTree::selectPiece(){
this->position = (*mapTree)[index];
}

// add location to the map
void GrowingTree::addLocation(){
    mapTree[index] = {this->position.xPos,this->position.yPos};
    this->index++;
}

// back track: remove the selected location from the map
void GrowingTree::backTrack(){
    mapTree->erase(index);
    this->index--;
}

