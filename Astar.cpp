//
// Created by allen on 4/12/19.
//

#include "Astar.h"

node::node() {
    x = 99;
    y = 99;
    f = 99;
    h = 99;
    g = 99;
    camefrom=nullptr;
    prev = nullptr;
    next = nullptr;
    for (auto i:neighbor) {
        for (int j = 0; j < 2; ++j) {
            i[j] = NOTSPOT;
        }
    }
}

node::node(int a, int b) {
    x = a;
    y = b;
    f = 99;
    h = 99;
    g = 99;
    camefrom=nullptr;
    prev = nullptr;
    next = nullptr;
    for (auto i:neighbor) {
        for (int j = 0; j < 2; ++j) {
            i[j] = NOTSPOT;
        }
    }
}

int node::cal_F() {
    f=h + g;
    return f;
}

int node::cal_H(node value) {
    h=abs(x - value.x) + abs(y - value.y);
    return h;
}

int node::cal_G() {
    g=prev->g + 1;
    return g;
}

void node::getNeighbor(char map[ROW][COL]) {
    neighbor[Up][X] = ((map[x][y - 1] == '1') || (y == 0)) ? NOTSPOT : x;
    neighbor[Up][Y] = ((map[x][y - 1] == '1') || (y == 0)) ? NOTSPOT : y - 1;
    neighbor[Down][X] = ((map[x][y + 1] == '1') || (y == COL - 1)) ? NOTSPOT : x;
    neighbor[Down][Y] = ((map[x][y + 1] == '1') || (y == COL - 1)) ? NOTSPOT : y + 1;
    neighbor[Left][X] = ((map[x - 1][y] == '1') || (x == 0)) ? NOTSPOT : x - 1;
    neighbor[Left][Y] = ((map[x - 1][y] == '1') || (x == 0)) ? NOTSPOT : y;
    neighbor[Right][X] = ((map[x + 1][y] == '1') || (x == ROW - 1)) ? NOTSPOT : x + 1;
    neighbor[Right][Y] = ((map[x + 1][y] == '1') || (x == ROW - 1)) ? NOTSPOT : y;
}

linklist::linklist() {
    start = new node();
    end = new node();
    start->next = end;
    start->prev = nullptr;
    end->next = nullptr;
    end->prev = start;
}

void linklist::add(node *value) {
    node *endprev = end->prev;
    endprev->next = value;
    value->next = end;
    value->prev=endprev;
    end->prev=value;
}

void linklist::del(node *value) {
    node *q = start, *valueprev, *valuenext;
    while (q != end) {
        if (q == value)
            break;
        q = q->next;
    }
    if (q != end) {
        valueprev = q->prev;
        valuenext = q->next;
        valueprev->next = valuenext;
        valuenext->prev = valueprev;
    } else
        cout << "delete error! value.x=" << value->x << "\tvalue.y=" << value->y << endl;
}

bool linklist::isExist(node *value) {
    node *q = start;
    while (q != end) {
        if (q == value)
            break;
        q = q->next;
    }
    return q != end;
}

bool linklist::isEmpty() {
    return start->next == end;
}

void linklist::printList() {
    node *q = start;
    while (q->next != end) {
        q = q->next;
        cout << "X:" << q->x << "\tY:" << q->y << endl;
    }
}

node *linklist::smallF() {
    node *q = start, *small = start;
    while (q != end) {
        if (q->f <= small->f)
            small = q;
        q=q->next;
    }
    return small;
}

Astar::Astar() {

}

Astar::Astar(int value[2][2]) {
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j) {
            spot[i][j].x = i;
            spot[i][j].y = j;
        }
    start = &spot[value[0][0]][value[0][1]];
    end = &spot[value[1][0]][value[1][1]];
    open.add(start);
    start->cal_H(*(end));
    start->g = 0;
    start->cal_F();
}

bool Astar::isGoal() {
    return current == end;
}

void Astar::calculate() {
    while (!open.isEmpty()) {
        current = open.smallF();
        if (isGoal()) break;

        open.del(current);
        close.add(current);

        current->getNeighbor(map);

        if (current->neighbor[Up][X] != NOTSPOT)
            neighbor[Up] = &spot[current->neighbor[Up][X]][current->neighbor[Up][Y]];
        else
            neighbor[Up] = &stone;

        if (current->neighbor[Down][X] != NOTSPOT)
            neighbor[Down] = &spot[current->neighbor[Down][X]][current->neighbor[Down][Y]];
        else
            neighbor[Down] = &stone;

        if (current->neighbor[Left][X] != NOTSPOT)
            neighbor[Left] = &spot[current->neighbor[Left][X]][current->neighbor[Left][Y]];
        else
            neighbor[Left] = &stone;

        if (current->neighbor[Right][X] != NOTSPOT)
            neighbor[Right] = &spot[current->neighbor[Right][X]][current->neighbor[Right][Y]];
        else
            neighbor[Right] = &stone;

        for (auto i:neighbor) {
            if (i == &stone)
                continue;
            if (close.isExist(i))
                continue;
            int test = current->g + 1;
            if ((open.isExist(i)) && (test >= i->g)) {
                continue;
            }
            i->g = test;
            i->cal_H(*end);
            i->cal_F();
            if (!open.isExist(i)) {
                open.add(i);
            }
            i->camefrom=current;
        }
    }
    if(open.isEmpty())
    {
        cout<<"it does not have a path to End:"<<end->x<<"\t"<<end->y<<endl;
        flag=0;
    }
    else{
        cout<<"finished"<<endl;
        end=current;
        flag=1;
    }
}

void Astar::printPath() {
    if(flag==0)
        return;
    node *q=end;
    while(q!=start){
        cout<<"X:"<<q->x<<"\tY:"<<q->y<<endl;
        q=q->camefrom;
        map[q->x][q->y]='*';
    }
    cout<<"X:"<<q->x<<"\tY:"<<q->y<<endl;
    map[start->x][start->y]='#';
    map[end->x][end->y]='#';

    for(auto i:map){
        for(int j=0;j<COL;++j)
            cout<<i[j]<<"\t";
        cout<<endl;
    }
}
