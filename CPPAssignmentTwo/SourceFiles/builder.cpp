#include "GrowingTree.h"
#include "RecursiveBacktrack.h"
#include "PrimAlgorithm.h"

void BuildGrowingTree(const int* width, const int* height){
    GrowingTree treeObj(*width,*height);
    treeObj.addLocation();
    treeObj.buildLoop();
    treeObj.binaryMain();
}

void BuildGrowingTreeNSolve(const int* width, const int* height){
    BuildGrowingTree(width, height);
    // solve
}

void BuildGrowingTreeNSolveNCreateSVG(const int* width, const int* height){
    BuildGrowingTree(width, height);
    // solve
    // create svg
}

void BuildRecursive(const int* width,const int* height){
    RecursiveBacktrack recObj(*width,*height);
    recObj.buildLoop();
}

void BuildRecursiveNSolve(const int* width,const int* height){
    BuildRecursive(width, height);
    // solve

}

void BuildRecursiveNSolveNCreateSVG(const int* width,const int* height){
    BuildRecursive(width, height);
    // solve
    // create svg

}

void BuildPrim(const int* width, const int* height){
    PrimAlgorithm primObj(*width,*height);
    primObj.buildLoop();
}

void BuildPrimNSolve(const int* width, const int* height){
    BuildPrim(width,height);
    // solve prim
}

void BuildPrimNSolveNCreateSVG(const int* width, const int* height){
    BuildPrim(width,height);
    // solve prim
    // create svg
}

void createSVG(){

    // create svg

}

int main(int argc, char* argv[]) {
    int height=5, width=5;

    BuildGrowingTree(&width, &height);

    return 0;
}

