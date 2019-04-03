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
    linklist open;
    spot point1;
    point1.x=1;
    point1.y=2;
    spot point2;
    point2.x=3;
    point2.y=4;
    open.init(point1);
    open.addBegin(point2);
    open.addEnd(point2);
    open.addEnd(point2);
    open.addEnd(point2);
    open.addEnd(point2);
    open.addEnd(point2);
    open.addEnd(point1);
    open.delThis(point1);
    open.printList();
    return 0;
}
