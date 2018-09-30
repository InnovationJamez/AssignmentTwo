//
// Created by lehoej on 9/14/2018.
//

#include "../HeaderFiles/GrowingTree.h"

// fill board generate & start point
GrowingTree::GrowingTree(const int* x, const int* y,std::vector<std::vector<disposition>>* board)
:width(*x), height(*y), board(board){
    this->index=0;
    fillBoard();
    setLocation();
    setVisited();
}

// de-constructor deallocate the memory taken up by the object
GrowingTree::~GrowingTree() {
    delete mapTree;
}

// growing tree loop
void GrowingTree::buildLoop() {
	while(index > 0) {
        selectPiece();
        carvePath();
		setVisited();
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
        std::vector<disposition>tempVec;
        for(int col = 0; col<height; col++){
            disposition state;
            tempVec.push_back(state);
        }
        board->push_back(tempVec);
    }
}

// set the path of the of maze
inline void GrowingTree::storeNorth(){
    (*board)[this->position.xPos][this->position.yPos].binVal |= 0b10000;
}
inline void GrowingTree::storeSouth(){
    (*board)[this->position.xPos][this->position.yPos].binVal |= 0b01000;
}
inline void GrowingTree::storeEast(){
    (*board)[this->position.xPos][this->position.yPos].binVal |= 0b00010;
}
inline void GrowingTree::storeWest(){
    (*board)[this->position.xPos][this->position.yPos].binVal |= 0b00100;
}

// move functions: move in specified direction
inline void GrowingTree::moveNorth(){
    storeNorth();
    this->position.yPos--;
    storeSouth();
}
inline void GrowingTree::moveSouth(){
    storeSouth();
    this->position.yPos++;
    storeNorth();
}
inline void GrowingTree::moveEast(){
    storeEast();
    this->position.xPos++;
    storeWest();
}
inline void GrowingTree::moveWest(){
    storeWest();
    this->position.xPos--;
    storeEast();
}

// check functions check the neighbors return result
inline bool GrowingTree::checkNorth(){
    if(this->position.yPos != 0){
		return ((*board)[this->position.xPos][this->position.yPos-1].binVal & 1) ? false : true;
    }
    else{
        return false;
    }
}
inline bool GrowingTree::checkSouth(){
    if(this->position.yPos != this->height-1){
		return ((*board)[this->position.xPos][this->position.yPos + 1].binVal & 1) ? false : true;
    }
    else{
        return false;
    }
}
inline bool GrowingTree::checkEast(){
    if(this->position.xPos != this->width-1){
		return ((*board)[this->position.xPos + 1][this->position.yPos].binVal & 1) ? false : true;
    }
    else{
        return false;
    }
}
inline bool GrowingTree::checkWest(){
    if(this->position.xPos != 0){
		return ((*board)[this->position.xPos - 1][this->position.yPos].binVal & 1) ? false : true;
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
    }if(checkSouth()){
        choice.push_back(SOUTH);
    }if(checkEast()){
        choice.push_back(EAST);
    }if(checkWest()){
        choice.push_back(WEST);
	}
	if(choice.empty()) {
		return EMPTY;
	}else{
        generateRandom(choice.size());
        return choice[this->randNum];
    }
}

// set visited
void GrowingTree::setVisited(){
    (*board)[this->position.xPos][this->position.yPos].binVal |= 0b00001;
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
this->position.xPos = (*mapTree)[index].xPos;
this->position.yPos = (*mapTree)[index].yPos;
}

// add location to the map
void GrowingTree::addLocation(){
	this->index++;
    (*mapTree)[index] = {this->position.xPos,this->position.yPos};
}

// back track: remove the selected location from the map
void GrowingTree::backTrack(){
    mapTree->erase(index);
    this->index--;
}
