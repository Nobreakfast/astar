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
    node start(1, 1);
    node end(7, 7);

    stack<node> open, close;


    node *q = new node();
    while (!open.empty()) {
        q->f = 99;

    }

    return 0;
}