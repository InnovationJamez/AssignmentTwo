#include "../HeaderFiles/GrowingTree.h"
#include "../HeaderFiles/RecursiveBacktrack.h"
#include "../HeaderFiles/PrimAlgorithm.h"
#include "../HeaderFiles/MazeLoader.h"
#include "../HeaderFiles/BinaryGenerator.h"

void BuildGrowingTree(const int* width, const int* height,std::vector<std::vector<disposition>>* board);

void BuildRecursive(const int* width,const int* height,std::vector<std::vector<disposition>>* board);

void BuildPrim(const int* width, const int* height,std::vector<std::vector<disposition>>* board);

void LoadMaze( std::string* binFileName, std::string* SVGFileName);


int main() {
    const int height = 20, width = 20;
    std::string binFileName = "mazeFile.maze";
    std::string SVGFileName = "svgFile.svg";
    auto * board = new std::vector<std::vector<disposition>>();

//   BuildGrowingTree(&width, &height, board);
//   BuildRecursive(&width, &height, board);
   BuildPrim(&width, &height, board);

    BinaryGenerator genObj(board, &width, &height, &binFileName);
    genObj.binaryMain();

    delete board;

    LoadMaze(&binFileName, &SVGFileName);
    return 0;
}

void BuildGrowingTree(const int* width, const int* height,std::vector<std::vector<disposition>>* board){
    GrowingTree treeObj(width,height,board);
    treeObj.addLocation();
    treeObj.buildLoop();
}

void BuildRecursive(const int* width,const int* height,std::vector<std::vector<disposition>>* board){
    RecursiveBacktrack recObj(width,height,board);
    recObj.buildLoop();
}

void BuildPrim(const int* width, const int* height,std::vector<std::vector<disposition>>* board){
    PrimAlgorithm primObj(width,height,board);
    primObj.buildLoop();
}

void LoadMaze(std::string* binFileName, std::string* SVGFileName){
    MazeLoader loaderObj(binFileName, SVGFileName);
}
