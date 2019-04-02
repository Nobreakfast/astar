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
    node *present = &start;
    node spot[ROW][COL];
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            spot[i][j].init(i, j);
        }
    }
    int *x = &start.x;
    int *y = &start.y;
    node *U, *D, *L, *R;
    node *small = new node();
    int temp;
    while (((present->x != end.x) || (present->y != end.y))) {
        temp = 99;
        present->getNeighbor();
        small=present;
        if ((present->neighbor[Up][X] < ROW+1) && (present->neighbor[Up][Y] < COL+1)) {
            U = &spot[present->neighbor[Up][X]][present->neighbor[Up][Y]];
            U->cal_(*present, end);
            if (U->f < temp) small = U;
        }
        if ((present->neighbor[Down][X] < ROW+1) && (present->neighbor[Down][Y] < COL+1)) {
            D = &spot[present->neighbor[Down][X]][present->neighbor[Down][Y]];
            D->cal_(*present, end);
            if (D->f < temp) small = D;
        }
        if ((present->neighbor[Left][X] < ROW+1) && (present->neighbor[Left][Y] < COL+1)) {
            L = &spot[present->neighbor[Left][X]][present->neighbor[Left][Y]];
            L->cal_(*present, end);
            if (L->f < temp) small = L;
        }
        if ((present->neighbor[Right][X] < ROW+1) && (present->neighbor[Right][Y] < COL+1)) {
            R = &spot[present->neighbor[Right][X]][present->neighbor[Right][Y]];
            R->cal_(*present, end);
            if (R->f < temp) small = R;
        }
        present = small;
        cout << "UP:" << U->f << "\tDown:" << D->f << "\tLeft:" << L->f << "\tRight:" << R->f << endl;
        cout << "small:" << small->f << "\tX:" << small->x << "\tY:" << small->y << endl;
    }

    return 0;
}
//node *small=new node();
//        small->f = 99;
//        present->getNeighbor();
//        up.init(*present, Up);
//        down.init(*present, Down);
//        left.init(*present, Left);
//        right.init(*present, Right);
//
//        up.cal_(*present, end);
//        down.cal_(*present, end);
//        left.cal_(*present, end);
//        right.cal_(*present, end);
//
//        cout << "UP:" << up.f << "\tDown:" << down.f << "\tLeft:" << left.f << "\tRight:" << right.f << endl;
//
//        if (up.f < small->f) small = &up;
//        if (down.f < small->f) small = &down;
//        if (left.f < small->f) small = &left;
//        if (right.f < small->f) small = &right;
//
//        cout << "small:" << small->f <<"\tX:"<<small->x<<"\tY:"<<small->y<<  endl;
//
//
//
//        present= small;