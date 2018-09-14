//
// Created by lehoej on 9/14/2018.
//

#ifndef CPPASSIGNMENTTWO_GROWINGTREE_H
#define CPPASSIGNMENTTWO_GROWINGTREE_H


class GrowingTree {
private:
    stack<int, int> mazeStack;
public:
    // constructor maybe do something
    GrowingTree();

    // de-constructor possibly use to deallocate the memory taken up by the object
    ~GrowingTree();

    // growing tree loop
    void growingTreeMain();

    // check surounding cells
    bool neighborChk(int coordX, int coordY);
    
    // pick a direction to move
    void pathChooser(int coordX, int coordY);

    // adding location to the top of tha stack
    void addingOnTree(int coordX, int coordY);

    // pop one location off the top of the stack
    void backTrack(int coordX, int coordY);
};


#endif //CPPASSIGNMENTTWO_GROWINGTREE_H
