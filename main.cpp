#include <iostream>
#include "node.h"
#include <math.h>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    linklist open, close;
    open.init();
    close.init();
    spot start(1, 1), goal(7, 7);
    start.f=12;
    start.h=12;
    start.g=0;
    open.addEnd(start);
    spot map[ROW][COL];
    spot* neighbor[4];
    for(int i=0;i<ROW;++i){
        for(int j=0;j<COL;++j){
            map[i][j].g=99;
            map[i][j].f=99;
            map[i][j].x=i;
            map[i][j].y=j;
        }
    }
    while (!open.isEmpty()) {


        spot *q=open.smallF();

        if(open.isEqual(*q,goal))
        {
            break;
        }

        open.delThis(*q);
        close.addEnd(*q);

        q->getNeighbor();


        neighbor[0]=&map[q->neighbor[Up][X]][q->neighbor[Up][Y]];
        neighbor[1]=&map[q->neighbor[Down][X]][q->neighbor[Down][Y]];
        neighbor[2]=&map[q->neighbor[Left][X]][q->neighbor[Left][Y]];
        neighbor[3]=&map[q->neighbor[Right][X]][q->neighbor[Right][Y]];

        for (auto i:neighbor) {
            if(i->x==NOTSPOT)
                continue;
            if (close.isExist(*i))
                continue;
            int test=q->g+1;
            if(!open.isExist(*i)){
                open.addEnd(*i);
            }
            else if(test>=i->g)
                continue;
            i->g=test;
            i->f=i->g+abs(i->x-goal.x)+abs(i->y-goal.y);
        }
    }
    open.printList();
    cout<<"next"<<endl;
    close.printList();
    return 0;
}
