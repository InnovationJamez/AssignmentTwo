#include "GrowingTree.h"
#include "RecursiveBacktrack.h"
#include "PrimAlgorithm.h"
#include "unistd.h"

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
    int height=5, width=5;

    BuildGrowingTree(&width, &height);
    BuildRecursive(&width, &height);
    BuildPrim(&width, &height);

    return 0;
}

