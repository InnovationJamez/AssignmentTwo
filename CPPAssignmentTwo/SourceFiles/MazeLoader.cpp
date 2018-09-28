//
// Created by lehoej on 9/21/2018.
//

#include "../HeaderFiles/MazeLoader.h"

MazeLoader::MazeLoader(std::string bin, std::string svg)
:binFileName(bin),SVGFileName(svg)
{
    openBinFile();
    readBinFile();
    closeBinFile();
}

MazeLoader::~MazeLoader(){
    delete connections;
    svgFile->close();
    delete svgFile;
};

void MazeLoader::openBinFile(){
    binFile->open("MazeFiles/" + binFileName);
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
void MazeLoader::storeConnections(){

}
void MazeLoader::closeBinFile(){
    binFile->close();
    delete binFile;
}
void MazeLoader::openSVG(){

}
void MazeLoader::startSVG(){
    svgFile->open("svgFile");
}
void MazeLoader::drawMaze(){

}
void MazeLoader::drawConnection(){

}
void MazeLoader::closeSVG(){
    svgFile->close();
    delete svgFile;
}
void MazeLoader::binToInt(std::string binVal){
    for (int i = 0; i < (int)binVal.size(); ++i)
    {
        if (binVal[i] == '1')
        {
            result += (int)pow(2, i);
        }
    }
    binFile->close();
    delete binFile;
}
