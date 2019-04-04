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
    start.f=3;
    open.addEnd(start);
    spot *check=new spot(99,99);
    while (!open.isEmpty()) {
        spot *q=open.smallH();

        open.delThis(*q);
        close.addEnd(*q);

        q->getNeighbor();
        q->cal_F(start,goal);

        if(open.isEqual(*q,goal))
        {
            break;
        }
        spot neighbor[4];

        for (int i = 0; i < 4; ++i) {
            neighbor[i].x=q->neighbor[i][X];
            neighbor[i].y=q->neighbor[i][Y];


            if(neighbor[i].x==NOTSPOT)
                continue;

            neighbor[i].cal_F(*q,goal);


            if(open.isExist(neighbor[i]))
            {
                if(neighbor[i].h>=q->g)
                    continue;
            }
            else
                open.addEnd(neighbor[i]) ;

            if(close.isExist(neighbor[i]))
            {
                    continue;
            }
        }


    }
    open.printList();
    cout<<"next"<<endl;
    close.printList();

    return 0;
}
