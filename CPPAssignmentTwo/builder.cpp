#include "GrowingTree.h"
#include "RecersiveBacktrack.h"
#include "PrimAlgorithm.h"

void BuildRecersive(int* width, int* height){
    RecersiveBacktrack recObj(*width,*height);
    recObj.buildLoop();
}


void BuildGowingTree(int* width, int* height){
    GrowingTree treeObj(*width,*height);
    treeObj.addLocation();
    treeObj.buildLoop();
}

void BuildPrim(int* width, int* height){
    PrimAlgorithm primObj(*width,*height);
    primObj.buildLoop();
}



int main(int argc, char* argv[]) {
    int height, width;

    BuildGowingTree(&width, &height);
    BuildRecersive(&width, &height);
    BuildPrim(&width, &height);
    return 0;
}

