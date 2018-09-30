//
// Created by lehoej on 9/30/2018.
//

#include "../HeaderFiles/BinaryGenerator.h"

BinaryGenerator::BinaryGenerator(std::vector<std::vector<disposition>>* board,const int* width, const int* height, std::string* binFileName)
:board(board), width(*width), height(*height), binFileName(*binFileName)
{

}

void BinaryGenerator::openBinFile(){
    (*binFile).open("MazeFiles/" + binFileName, std::ios::in | std::ios::out | std::ios::trunc);
}

// convert a base ten number to binary
void BinaryGenerator::intToBin(){
    binNum = "";
    while (num > 0)
    {
        binNum = binNum + (num % 2 == 1 ? '1' : '0');
        num = num / 2;
    }
    while(binNum.length() < 32)
    {
        binNum = binNum + '0';
    }
}

// iterate through the vector<vector<cell>> and find where the walls are
void BinaryGenerator::connectionChecker(){
    edgeNo = 0;
    for(int i = 0; i<width;i++){
        for(int j = 0; j<(height-1); j++){
            if((*board)[i][j].binVal & 0b01000){
                edgeNo++;
                position.yPos = j;
                position.xPos = i;
                southWall();
            }
        }
    }
    for(int j = 0; j<height; j++){
        for(int i = 0; i<(width-1);i++){
            if((*board)[i][j].binVal & 0b0010){
                edgeNo++;
                position.yPos = j;
                position.xPos = i;
                eastWall();
            }
        }
    }

}

// store binary number in bin file
void BinaryGenerator::addToBinFile(){
    for (int counter = 0; counter <= (int)binNum.size(); counter++) {
        binFile->put(binNum[counter]);
    }
}

// add number of edges to third spot in wallList
void BinaryGenerator::addEdgeNum(){
    num = width;
    intToBin();
    addToBinFile();
    num = height;
    intToBin();
    addToBinFile();
    num = edgeNo;
    intToBin();
    addToBinFile();
}

// add values for edges
void BinaryGenerator::addEdges(){
    for (int i : (*numberList)) {
        num = i;
        intToBin();
        addToBinFile();
    }
}

// deallocate memory taken up by the binFile fstream object
void BinaryGenerator::deleteBinFile(){
    binFile->close();
    delete binFile;
    delete numberList;
}

// add numbers to wall container
void BinaryGenerator::addToWallList(){
    (*numberList).push_back(num);
}

// GrowingTree::south edge
void BinaryGenerator::southWall(){
    num = position.xPos;
    addToWallList();
    num = position.yPos;
    addToWallList();
    num = position.xPos;
    addToWallList();
    num = position.yPos+1;
    addToWallList();
}

// east edge
void BinaryGenerator::eastWall(){
    num = position.xPos;
    addToWallList();
    num = position.yPos;
    addToWallList();
    num = position.xPos+1;
    addToWallList();
    num = position.yPos;
    addToWallList();
}

void BinaryGenerator::binaryMain(){
    openBinFile();
    connectionChecker();
    addEdgeNum();
    addEdges();
    deleteBinFile();
}