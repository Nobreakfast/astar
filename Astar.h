//
// Created by allen on 4/12/19.
//

#ifndef ASTAR_ASTAR_H
#define ASTAR_ASTAR_H

#include <iostream>
#include <math.h>
using namespace std;
#define NOTSPOT 99
#define ROW 8
#define COL 8
#define ROW 8

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

class node{
public:
    int x,y;
    int f,g,h;
    int neighbor[4][2];
    node *camefrom;
    node *prev= nullptr;
    node *next= nullptr;
    node();
    node(int a,int b);
    int cal_F();
    int cal_H(node value);
    int cal_G();
    void getNeighbor(char map[ROW][COL]);

};

class linklist {
public:
    node *start,*end;
    linklist();
    void add(node *value);
    void del(node *value);
    bool isExist(node *value);
    bool isEmpty();
    void printList();
    node *smallF();

};

class Astar {
public:
    char map[ROW][COL] = {
            {'0', '0', '0', '0', '0', '0', '0', '0'},
            {'0', '0', '0', '0', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '1', '0', '0', '0'},
            {'0', '0', '1', '1', '1', '0', '0', '0'},
            {'1', '1', '1', '0', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0', '0', '0', '0'},
            {'0', '0', '0', '0', '0', '0', '0', '0'},
    };
    node *start,*end;
    node spot[ROW][COL];
    node *neighbor[4];
    node stone;
    node *current;
    linklist open,close;
    int flag=1;
    Astar();
    Astar(int value[2][2]);
    bool isGoal();
    void calculate();
    void printPath();
};


#endif //ASTAR_ASTAR_H
