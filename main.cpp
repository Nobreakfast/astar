#include <iostream>
#include "node.h"
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    int map[8][8] = {
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0},
            {0, 1, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
    };
    node start(1, 1);
    node end(7, 7);
    start.getNeighbor();
    for (int i = 0; i < 4; i++) {
        cout << i << "\tX:" << start.neighbor[i][X] << "\tY:" << start.neighbor[i][Y] << endl;
    }

    std::vector<int> openset, closeset;
    node *present=&start;
    node up,down,left,right;

    while (((present->x != end.x)||(present->y!=end.y))) {
        node *small=new node();
        small->f = 99;
        present->getNeighbor();
        up.init(*present, Up);
        down.init(*present, Down);
        left.init(*present, Left);
        right.init(*present, Right);

        up.cal_(*present, end);
        down.cal_(*present, end);
        left.cal_(*present, end);
        right.cal_(*present, end);

        cout << "UP:" << up.f << "\tDown:" << down.f << "\tLeft:" << left.f << "\tRight:" << right.f << endl;

        if (up.f < small->f) small = &up;
        if (down.f < small->f) small = &down;
        if (left.f < small->f) small = &left;
        if (right.f < small->f) small = &right;

        cout << "small:" << small->f <<"\tX:"<<small->x<<"\tY:"<<small->y<<  endl;



        present= small;
    }

    return 0;
}