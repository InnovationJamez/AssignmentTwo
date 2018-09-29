//
// Created by lehoej on 9/21/2018.
//

#ifndef CPPASSIGNMENTTWO_MAZELOADER_H
#define CPPASSIGNMENTTWO_MAZELOADER_H
#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>

struct position{
    int xPos, yPos;
};

class MazeLoader {
private:
    int mazeWidth;
    int mazeHeight;
    int noOfWalls;
    float bufferWidth;
    float bufferHeight;
    position a, b;
    std::string binFileName;
    std::string SVGFileName;
    int result = 0;
    std::vector<int>* connections= new std::vector<int>;
    std::fstream* binFile = new std::fstream;
    std::fstream* svgFile = new std::fstream;
public:
    MazeLoader(std::string bin, std::string svg);
    ~MazeLoader();
    void openBinFile();
    void readBinFile();
    void closeBinFile();
    void openSVG();
    void readConnections();
    void drawConnection();
    void closeSVG();
    void binToInt(std::string binVal);
};


#endif //CPPASSIGNMENTTWO_MAZELOADER_H
