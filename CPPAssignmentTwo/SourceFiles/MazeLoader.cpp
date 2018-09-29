//
// Created by lehoej on 9/21/2018.
//

#include "../HeaderFiles/MazeLoader.h"

MazeLoader::MazeLoader(std::string bin, std::string svg)
:binFileName(*&bin),SVGFileName(*&svg)
{
    bufferWidth = 1/mazeWidth;
    bufferHeight = 1/mazeHeight;
    openBinFile();
    readBinFile();
    closeBinFile();
    svgFile->open("SVGFiles/" + SVGFileName, std::ofstream::out | std::ofstream::trunc);
    openSVG();
    readConnections();
    closeSVG();
}

MazeLoader::~MazeLoader(){
    delete connections;
    svgFile->close();
    delete svgFile;
};

void MazeLoader::openBinFile(){
    binFile->open("MazeFiles/" + binFileName, std::ios::in | std::ios::out);
}
void MazeLoader::readBinFile(){
    char ch;
    binFile->seekg(0, std::ios::beg);
    std::string tempString;
    while(binFile->tellg() < (int)binFile->tellg()){
        binFile->get(ch);
        tempString += ch;
        if (tempString.size() == 33)
        {
            binToInt(tempString);
            connections->push_back(result);
            tempString.clear();
        }
    }
}

void MazeLoader::closeBinFile(){
    binFile->close();
    delete binFile;
}

void MazeLoader::openSVG(){
    (*svgFile) << "<svg viewBox='0 0 1 1' ";
    (*svgFile) << "width='500' height='500' ";
    (*svgFile) << "xmlns='http://www.w3.org/2000/svg'>\n";
    (*svgFile) << "<rect width='1' height='1' ";
    (*svgFile) << "style='fill: black' />\n";
}

void MazeLoader::closeSVG(){
    (*svgFile) << "</svg>\n";
    svgFile->close();
    delete svgFile;
}

void MazeLoader::readConnections(){
    mazeWidth = (*connections)[0];
    mazeHeight = (*connections)[1];
    noOfWalls = (*connections)[2];

    for(int i = 0; i < (*connections).size(); ++i){
        if (i % 4 == 3)
        {
            a.xPos = (*connections)[i];

        }if (i % 4 == 0)

            a.yPos = (*connections)[i];
        {
        }if (i % 4 == 1)
        {
            b.xPos = (*connections)[i];

        }if (i % 4 == 2)
        {
            b.yPos = (*connections)[i];
            drawConnection();
        }
    }
}

void MazeLoader::drawConnection(){
    if(a.xPos == b.xPos)
    {
        (*svgFile) << "<line stroke='white' stroke-width='";
        (*svgFile) << bufferWidth;
        (*svgFile) << "' x1='";
        (*svgFile) << a.xPos*bufferWidth;
        (*svgFile) << "' y1='";
        (*svgFile) << a.yPos*bufferHeight;
        (*svgFile) << "' x2='";
        (*svgFile) << a.xPos*bufferWidth;
        (*svgFile) << "' y2='";
        (*svgFile) << a.yPos*bufferHeight - bufferHeight;
        (*svgFile) << "'/>\n";
    }else{
        (*svgFile) << "<line stroke='white' stroke-width='";
        (*svgFile) << bufferHeight;
        (*svgFile) << "' x1='";
        (*svgFile) << a.xPos*bufferWidth;
        (*svgFile) << "' y1='";
        (*svgFile) << a.yPos*bufferHeight;
        (*svgFile) << "' x2='";
        (*svgFile) << a.xPos*bufferWidth - bufferWidth;
        (*svgFile) << "' y2='";
        (*svgFile) << a.yPos*bufferHeight;
        (*svgFile) << "'/>\n";
    }
}

void MazeLoader::binToInt(std::string binVal){
    for (int i = 0; i < (int)binVal.size(); ++i)
    {
        if (binVal[i] == '1')
        {
            result += (int)pow(2, i);
        }
    }
}
