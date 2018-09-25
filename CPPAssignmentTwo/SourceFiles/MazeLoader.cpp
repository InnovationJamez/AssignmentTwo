//
// Created by lehoej on 9/21/2018.
//

#include "../HeaderFiles/MazeLoader.h"

MazeLoader::MazeLoader(std::string bin, std::string svg)
:binFileName(bin),SVGFileName(svg)
{

}

MazeLoader::~MazeLoader(){
    delete connections;
}

void MazeLoader::openBinFile(){
    binFile->open("binFile");
}
void MazeLoader::readBinFile(){

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
void MazeLoader::endSVG(){

}
void MazeLoader::closeSVG(){
    svgFile->close();
    delete svgFile;
}
