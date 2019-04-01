//
// Created by allen on 19-4-1.
//

#ifndef ASTAR_NODE_H
#define ASTAR_NODE_H

#include <vector>

#define NOTSPOT 99
#define ROW 8
#define COL 8
enum dir{
    Up=0,
    Down,
    Left,
    Right
};
enum pos{
    X=0,
    Y
};
class node {
public:
    int x, y;
    int f, g, h;
    node(int x,int y);
    ~node();
    int neighbor[4][2];
    void getNeighbor();
};


#endif //ASTAR_ASTAR_H
