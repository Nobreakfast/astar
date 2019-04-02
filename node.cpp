//
// Created by allen on 19-4-1.
//

#include "node.h"
#include <vector>
#include <math.h>
std::vector<int> openset,closeset;
node::node(int x, int y) {
    this->x=x;
    this->y=y;
    this->f=0;
    this->h=0;
    this->g=0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            this->neighbor[i][j]=0;
        }
    }
}
node::node() {
    this->x=0;
    this->y=0;
    this->f=0;
    this->h=0;
    this->g=0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            this->neighbor[i][j]=0;
        }
    }
}
node::~node() {

}
void node::getNeighbor(){
    this->neighbor[Up][X]=this->x;
    this->neighbor[Up][Y]=this->y-1;
    this->neighbor[Down][X]=this->x;
    this->neighbor[Down][Y]=this->y+1;
    this->neighbor[Left][X]=this->x-1;
    this->neighbor[Left][Y]=this->y;
    this->neighbor[Right][X]=this->x+1;
    this->neighbor[Right][Y]=this->y;
    if((this->x<1))
    {
        this->neighbor[Left][X]=NOTSPOT;
        this->neighbor[Left][Y]=NOTSPOT;
    }
    if((this->x>ROW-1))
    {
        this->neighbor[Right][X]=NOTSPOT;
        this->neighbor[Right][Y]=NOTSPOT;
    }
    if(this->y<1)
    {
        this->neighbor[Up][X]=NOTSPOT;
        this->neighbor[Up][Y]=NOTSPOT;
    }
    if(this->y>COL-1)
    {
        this->neighbor[Down][X]=NOTSPOT;
        this->neighbor[Down][Y]=NOTSPOT;
    }
}
void node::cal_(node last,node end) {
    this->g=last.g+1;
    this->h=abs(this->x-end.x)+abs(this->y-end.y);
    this->f=this->g+this->h;
}
void node::init(node last,dir udlr) {
    this->x=last.neighbor[udlr][X];
    this->y=last.neighbor[udlr][Y];
    this->f=0;
    this->h=0;
    this->g=0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            this->neighbor[i][j]=0;
        }
    }
}

void node::init(int x, int y) {
    this->x=x;
    this->y=y;
    this->f=0;
    this->h=0;
    this->g=0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            this->neighbor[i][j]=0;
        }
    }

}

void node::init() {
    this->x=0;
    this->y=0;
    this->f=0;
    this->h=0;
    this->g=0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            this->neighbor[i][j]=0;
        }
    }
}
bool node::isGoal(node point) {
    return ((this->x==point.x )&& (this->y==point.y));
}