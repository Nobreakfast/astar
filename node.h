//
// Created by allen on 19-4-1.
//

#ifndef ASTAR_NODE_H
#define ASTAR_NODE_H

#include <iostream>
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
    spot(){
        this->x=0;
        this->y=0;
        this->f=0;
        this->g=0;
        this->h=0;
    };
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

    void init(spot value);

    void addBegin(spot value);

    void addEnd(spot value);
//
//    node* smallF();

    bool isEmpty();

    bool isExist(spot value);
    bool isEqual(spot value1,spot value2);
    void search(spot value);

    void delThis(spot value);

    void delAfter(spot value);

    void printList();

};

#endif //ASTAR_ASTAR_H
