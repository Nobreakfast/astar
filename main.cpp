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
    spot start(1, 1), goal(2, 2);
    start.f=3;
    open.addEnd(start);
    open.printList();
    cout<<"next"<<endl;
    open.delThis(start);
    open.printList();
//    while (!open.isEmpty()) {
//        spot *q=open.smallF();
//        open.delThis(start);
//
////        if(open.isEqual(*q,goal))
////            break;
//
//        q->getNeighbor();
//        q->cal_F(start,goal);
//
//        open.delThis(*q);
//        close.addEnd(*q);
//        spot neighbor[4];
//
//        for (int i = 0; i < 4; ++i) {
//            neighbor[i].x=q->neighbor[i][X];
//            neighbor[i].y=q->neighbor[i][Y];
//
//
//            if(!open.isEqual(neighbor[i],goal))
//            {
//                    break;
//            }
//
//            neighbor[i].cal_F(*q,goal);
//
//            if(open.isExist(neighbor[i]))
//            {
//                spot *exist=open.search(neighbor[i]);
//                if(exist->f<=neighbor[i].f)
//                    continue;
//            }
//
//            if(close.isExist(neighbor[i]))
//            {
//                spot *exist=close.search(neighbor[i]);
//                if(exist->f<=neighbor[i].f)
//                    continue;
//                else
//                    open.addEnd(neighbor[i]);
//            }
//        }
//        close.addEnd(*q);
//    }
//    open.printList();
//    close.printList();

    return 0;
}
