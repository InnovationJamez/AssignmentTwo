#include "GrowingTree.h"
#include "RecersiveBacktrack.h"
#include "PrimAlgorithm.h"

int main(int argc, char* argv[]) {
    GrowingTree treeObj(3,3);
    treeObj.buildLoop();
    return 0;
}

