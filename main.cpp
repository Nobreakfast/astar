#include <iostream>
#include "node.h"
#include <math.h>

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
    linklist open, close;
    open.init();
    close.init();
    spot start(1, 1), goal(1, 1);
    open.addEnd(start);
    while (!open.isEmpty()) {
        spot *q=open.smallF();
        if(open.isEqual(*q,goal))
            break;
        open.delThis(*q);
        close.addEnd(*q);
        q->cal_F(start,goal);
        q->getNeighbor();
        spot neighbor[4];
        for (int i = 0; i < 4; ++i) {
            neighbor[i].x=q->neighbor[i][X];
            neighbor[i].y=q->neighbor[i][Y];

            if(close.isExist(neighbor[i]))
                continue;

            neighbor[i].cal_F(*q,goal);

            if(!open.isExist(neighbor[i]))
                open.addEnd(neighbor[i]);
            else ;  //if the neighbor.f is larger than the neighbor.f in the openset
            // need to wirte a function in spot *linklist::search;
        }
    }

    return 0;
}
