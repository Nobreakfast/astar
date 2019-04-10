//
// Created by allen on 19-4-1.
//

#ifndef ASTAR_NODE_H
#define ASTAR_NODE_H

#include <iostream>
#include <math.h>

using namespace std;
#define NOTSPOT 99
#define ROW 8
#define COL 8

enum dir {
    Up = 0,
    Down,
    Left,
    Right
};
enum pos {
    X = 0,
    Y
};


class spot {
public:
    int x, y;
    int f, g, h;
    int neighbor[4][2];
    int map[ROW][COL] = {
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
    };
    spot();
    spot(int x,int y);
    int cal_F(spot prev,spot goal);
    void getNeighbor();
};

struct node{
    spot info;
    node *prev= nullptr;
    node *next= nullptr;
};


class linklist {
public:
    node *start;
    node *small;
    linklist();

    void init();

    void addBegin(spot value);

    void addEnd(spot value);

    spot* smallF();

    bool isEmpty();

    bool isExist(spot value);
    bool isEqual(spot value1,spot value2);
    spot* search(spot value);
    spot* getEnd();

    void delThis(spot value);

    void delAfter(spot value);

    void printList();
    spot *smallH();

};

#endif //ASTAR_ASTAR_H
