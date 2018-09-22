//
// Created by lehoej on 9/21/2018.
//

#ifndef CPPASSIGNMENTTWO_COMMANDLINEOPTIONS_H
#define CPPASSIGNMENTTWO_COMMANDLINEOPTIONS_H

#include <boost/program_options.hpp>
#include <string>
using namespace boost::progrram_options

// -----------------------------------------------------------------------
// Command Line Options
// [-h|--help]                      show help menu
// [-gg|--gg] ARG (int)             generate w/ growing tree method
// [-gp|--gp] ARG (int)             generate w/ Prim’s algorithm
// [-gr|--gr] ARG (int)             generate w/ recursive backing algorithm
// [-pm|--pm] ARG (int)             solve w/ Maze-routing algorithm
// [-pm|--sb] ARG (std::string)     store binary file name
// [-sv|--sv] ARG (std::string)     store svg file name
// ------------------------------------------------------------------------

enum BUILD_OPTIONS{
    GROWING_TREE = 1,
    PRIM_ALGORITHM = 2,
    RECERSIVE_BACKTRACK = 3
};


class CommandLineOptions {
private:
    BUILD_OPTIONS CHOICE;
    CommandLineOptions(const CommandLineOptions &rhs);
    CommandLineOptions &operstor=(const (CommandLineOptions &rhs));
    po::options_description myOptions;
    std::string myInputFile:
    int width, height;
    std::string binFileName;
    std::string svgFileName;
    bool GG_Flag;
    bool GP_Flag;
    bool GR_Flag;
    bool SB_Flag;
    bool SV_Flag;
protected:
    void setup();
    bool vallidateFiles();
public:
    enum statusReturnEnum{
        OPTS_SUCCESS,
        OPTS_VERSION,
        OPTS_FAILURE
    };
    CommandLineOptions();
    ~CommandLineOptions();
    statusReturnEnum = parse(int argc, char* argv);
    inline const int getWidth();
    inline const int getHeight();
    inline const std::string getBinFileName();
    inline const std::string getSVGFileName();
    inline bool getGGFlag();
    inline bool getGPFlag();
    inline bool getGRflag();
    inline bool getSBFlag();
    inline bool getSVFlag();

};


#endif //CPPASSIGNMENTTWO_COMMANDLINEOPTIONS_H
