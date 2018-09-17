#include "GrowingTree.h"
#include "RecersiveBacktrack.h"
#include "PrimAlgorithm.h"

int main(int argc, char* argv[]) {
    GrowingTree treeObj(3,3);
    treeObj.addLocation();
    treeObj.buildLoop();

    PrimAlgorithm primObj;
    primObj.buildLoop();

    return 0;
}

