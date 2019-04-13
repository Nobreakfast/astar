#include <iostream>
#include <math.h>
#include "Astar.h"

using namespace std;

int main() {
    int addr[2][2] = {{1, 1},
                      {7, 7}};
    Astar astar(addr);
    astar.calculate();
    astar.printPath();
    return 0;
}