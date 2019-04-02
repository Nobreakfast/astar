#include <iostream>
#include "node.h"
#include <math.h>
#include <stack>

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
    node start(7, 6); start.f=99;
    node end(7, 7);

    stack<node> open, close;
    open.push(start);
    open.push(start);
    node *small_f_in_stack=new node(1,1);
    node *q = new node();
    small_f_in_stack=&start;
    while (!open.empty()) {
        q=small_f_in_stack;
        open.pop();
        q->getNeighbor();
        node up(q->neighbor[Up][X],q->neighbor[Up][Y]);
        node down(q->neighbor[Down][X],q->neighbor[Down][Y]);
        node left(q->neighbor[Left][X],q->neighbor[Left][Y]);
        node right(q->neighbor[Right][X],q->neighbor[Right][Y]);
        if(up.isGoal(end)) {
            cout<<"M ARRIVED!\tX:"<<up.x<<"\tY:"<<up.y<<endl;
            break;
        }
        if(down.isGoal(end)) {
            cout<<"M ARRIVED!\tX:"<<down.x<<"\tY:"<<down.y<<endl;
            break;
        }
        if(left.isGoal(end)) {
            cout<<"M ARRIVED!\tX:"<<left.x<<"\tY:"<<left.y<<endl;
            break;
        }
        if(right.isGoal(end)) {
            cout<<"M ARRIVED!\tX:"<<right.x<<"\tY:"<<right.y<<endl;
            break;
        }
        up.cal_(*q,end);
        down.cal_(*q,end);
        left.cal_(*q,end);
        right.cal_(*q,end);

    }

    return 0;
}