//
// Created by lehoej on 9/30/2018.
//

#ifndef CPPASSIGNMENTTWO_BINARYGENERATOR_H
#define CPPASSIGNMENTTWO_BINARYGENERATOR_H

#include<vector>
#include<fstream>
#include <deque>
#include<memory>
#include "../HeaderFiles/GrowingTree.h"


class BinaryGenerator {
private:
    int num, edgeNo, width, height;
    coords position;
    std::deque<int>* numberList = new std::deque<int>;
    std::fstream* binFile = new std::fstream;
    std::string binNum, binFileName;
    std::vector<std::vector<disposition>>* board;
public:
    // get dimensions and the vector for the board
    BinaryGenerator(std::vector<std::vector<disposition>>* board,const int* width, const int* height, std::string* binFileName);

    // give the file object a file
    void openBinFile();

    // iterate through the vector<vector<cell>> and find where the walls are
    void connectionChecker();

    // store binary number in bin file
    void addToBinFile();

    // add number of edges to third spot in wallList
    void addEdgeNum();

    // add values for edges
    void addEdges();

    // deallocate memory taken up by the binFile fstream object
    void deleteBinFile();

    // add numbers to wall container
    void addToWallList();

    // GrowingTree::south edge
    void southWall();

    // east edge
    void eastWall();

    // convert from integer to binary
    void intToBin();

    // where everything happens
    void binaryMain();
};

#endif //CPPASSIGNMENTTWO_BINARYGENERATOR_H
