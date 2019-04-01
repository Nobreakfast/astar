//
// Created by allen on 19-4-1.
//

#include "node.h"
#include <vector>
std::vector<int> openset,closeset;
node::node(int x, int y) {
    this->x=x;
    this->y=y;
    this->f=0;
    this->h=0;
    this->g=0;
}
node::~node() {

}
void node::getNeighbor(){
    this->neighbor[Up][X]=this->x;
    this->neighbor[Up][Y]=this->y-1;
    this->neighbor[Down][X]=this->x;
    this->neighbor[Down][y]=this->y+1;
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
