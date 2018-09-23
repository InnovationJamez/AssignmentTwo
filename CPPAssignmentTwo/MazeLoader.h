//
// Created by lehoej on 9/21/2018.
//

#ifndef CPPASSIGNMENTTWO_MAZELOADER_H
#define CPPASSIGNMENTTWO_MAZELOADER_H
#include<iostream>
#include<fstream>
#include<vector>

class MazeLoader {
private:
    int mazeWidth;
    int mazeHeight;
    int noOfWalls;
    float bufferWidth;
    float bufferHeight;
    std::string binFileName;
    std::string SVGFileName;
    std::vector<int>* connections= new std::vector<int>;
    std::fstream* binFile = new std::fstream;
    std::fstream* svgFile = new std::fstream;
private:
    MazeLoader(std::string bin, std::string svg);
    ~MazeLoader();
    void openBinFile();
    void readBinFile();
    void storeConnections();
    void closeBinFile();
    void openSVG();
    void startSVG();
    void drawMaze();
    void drawConnection();
    void endSVG();
    void closeSVG();
};


#endif //CPPASSIGNMENTTWO_MAZELOADER_H
