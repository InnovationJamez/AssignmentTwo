//
// Created by lehoej on 9/21/2018.
//

#include "CommandLineOptions.h"

CommandLineOptions::CommandLineOptions(){

}

CommandLineOptions::~CommandLineOptions(){

}

CommandLineOptions::statusReturnEnum parse(int argc, char* argv[]);

const int CommandLineOptions::getWidth(){return width;}
const int CommandLineOptions::getHeight(){return height;}
inline bool CommandLineOptions::getGGFlag(){return GG_Flag;}
inline bool CommandLineOptions::getGPFlag(){return GP_Flag;}
inline bool CommandLineOptions::getGRflag(){return GR_Flag;}
inline bool CommandLineOptions::getSBFlag(){return SB_Flag;}
inline bool CommandLineOptions::getSVFlag(){return SV_Flag;}

const std::string CommandLineOptions::getBinFileName(){
    static const std::string emptyString;
    return (binFileName.empty())? emptyString : binFileName;
}

const std::string CommandLineOptions::getSVGFileName(){
    static const std::string emptyString;
    return (svgFileName.empty())? emptyString : svgFileName;
}

