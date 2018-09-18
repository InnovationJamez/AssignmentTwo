#include "GrowingTree.h"
#include "RecursiveBacktrack.h"
#include "PrimAlgorithm.h"

void BuildGrowingTree(const int* width, const int* height){
    GrowingTree treeObj(*width,*height);
    treeObj.addLocation();
    treeObj.buildLoop();
}

void BuildRecursive(const int* width,const int* height){
    RecursiveBacktrack recObj(*width,*height);
    recObj.buildLoop();
}

void BuildPrim(const int* width, const int* height){
    PrimAlgorithm primObj(*width,*height);
    primObj.buildLoop();
}

int main(int argc, char* argv[]) {
    int height, width;

    BuildGrowingTree(&width, &height);
    BuildRecursive(&width, &height);
    BuildPrim(&width, &height);

    return 0;
}

