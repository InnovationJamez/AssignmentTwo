#include "../HeaderFiles/GrowingTree.h"
#include "../HeaderFiles/RecursiveBacktrack.h"
#include "../HeaderFiles/PrimAlgorithm.h"
#include "../HeaderFiles/MazeLoader.h"

void BuildGrowingTree(const int* width, const int* height, std::string* binFileName);

void BuildRecursive(const int* width,const int* height, std::string* binFileName);

void BuildPrim(const int* width, const int* height, std::string* binFileName);

void LoadMaze( std::string* binFileName, std::string* SVGFileName);


int main() {
    const int height = 3, width = 3;
    std::string binFileName = "mazeFile.maze";
    std::string SVGFileName = "svgFile.svg";

	if(false)
    {
        BuildGrowingTree(&width, &height, &binFileName);
    }
	if (true)
    {
        BuildRecursive(&width, &height, &binFileName);
    }
	if (false)
    {
        BuildPrim(&width, &height, &binFileName);
    }
    if (true)
    {
        LoadMaze(&binFileName, &SVGFileName);
    }
    return 0;
}

void BuildGrowingTree(const int* width, const int* height, std::string* binFileName){
    GrowingTree treeObj(*width,*height, *binFileName);
    treeObj.addLocation();
    treeObj.buildLoop();
    treeObj.binaryMain();
}

void BuildRecursive(const int* width,const int* height, std::string* binFileName){
    RecursiveBacktrack recObj(*width,*height, *binFileName);
    recObj.buildLoop();
	recObj.binaryMain();
}

void BuildPrim(const int* width, const int* height, std::string* binFileName){
    PrimAlgorithm primObj(*width,*height, *binFileName);
    primObj.buildLoop();
}

void LoadMaze( std::string* binFileName, std::string* SVGFileName){
    MazeLoader loaderObj(*binFileName, *SVGFileName);
}