//
// Created by allen on 4/12/19.
//

#include "Astar.h"

node::node() {
    this->x = 99;
    this->y = 99;
    this->f = 99;
    this->h = 99;
    this->g = 99;
    this->camefrom=nullptr;
    this->prev = nullptr;
    this->next = nullptr;
    for (auto i:this->neighbor) {
        for (int j = 0; j < 2; ++j) {
            i[j] = NOTSPOT;
        }
    }
}

node::node(int a, int b) {
    this->x = a;
    this->y = b;
    this->f = 99;
    this->h = 99;
    this->g = 99;
    this->camefrom=nullptr;
    this->prev = nullptr;
    this->next = nullptr;
    for (auto i:this->neighbor) {
        for (int j = 0; j < 2; ++j) {
            i[j] = NOTSPOT;
        }
    }
}

int node::cal_F() {
    this->f=this->h + this->g;
    return this->f;
}

int node::cal_H(node value) {
    this->h=abs(this->x - value.x) + abs(this->y - value.y);
    return this->h;
}

int node::cal_G() {
    this->g=this->prev->g + 1;
    return this->g;
}

void node::getNeighbor(char map[ROW][COL]) {
    neighbor[Up][X] = ((map[x][y - 1] == '1') || (this->y == 0)) ? NOTSPOT : this->x;
    neighbor[Up][Y] = ((map[x][y - 1] == '1') || (this->y == 0)) ? NOTSPOT : this->y - 1;
    neighbor[Down][X] = ((map[x][y + 1] == '1') || (this->y == COL - 1)) ? NOTSPOT : this->x;
    neighbor[Down][Y] = ((map[x][y + 1] == '1') || (this->y == COL - 1)) ? NOTSPOT : this->y + 1;
    neighbor[Left][X] = ((map[x - 1][y] == '1') || (this->x == 0)) ? NOTSPOT : this->x - 1;
    neighbor[Left][Y] = ((map[x - 1][y] == '1') || (this->x == 0)) ? NOTSPOT : this->y;
    neighbor[Right][X] = ((map[x + 1][y] == '1') || (this->x == ROW - 1)) ? NOTSPOT : this->x + 1;
    neighbor[Right][Y] = ((map[x + 1][y] == '1') || (this->x == ROW - 1)) ? NOTSPOT : this->y;
}

linklist::linklist() {
    start = new node();
    end = new node();
    this->start->next = end;
    this->start->prev = nullptr;
    this->end->next = nullptr;
    this->end->prev = start;
}

void linklist::add(node *value) {
    node *endprev = this->end->prev;
    endprev->next = value;
    value->next = this->end;
    value->prev=endprev;
    this->end->prev=value;
}

void linklist::del(node *value) {
    node *q = start, *valueprev, *valuenext;
    while (q != this->end) {
        if (q == value)
            break;
        q = q->next;
    }
    if (q != this->end) {
        valueprev = q->prev;
        valuenext = q->next;
        valueprev->next = valuenext;
        valuenext->prev = valueprev;
    } else
        cout << "delete error! value.x=" << value->x << "\tvalue.y=" << value->y << endl;
}

bool linklist::isExist(node *value) {
    node *q = start;
    while (q != this->end) {
        if (q == value)
            break;
        q = q->next;
    }
    return q != this->end;
}

bool linklist::isEmpty() {
    return this->start->next == this->end;
}

void linklist::printList() {
    node *q = start;
    while (q->next != this->end) {
        q = q->next;
        cout << "X:" << q->x << "\tY:" << q->y << endl;
    }
}

node *linklist::smallF() {
    node *q = start, *small = start;
    while (q != this->end) {
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
            this->spot[i][j].x = i;
            this->spot[i][j].y = j;
        }
    this->start = &spot[value[0][0]][value[0][1]];
    this->end = &spot[value[1][0]][value[1][1]];
    this->open.add(this->start);
    this->start->cal_H(*(this->end));
    this->start->g = 0;
    this->start->cal_F();
}

bool Astar::isGoal() {
    return this->current == this->end;
}

void Astar::calculate() {
    while (!this->open.isEmpty()) {
        this->current = this->open.smallF();
        if (this->isGoal()) break;

        this->open.del(current);
        this->close.add(current);

        this->current->getNeighbor(this->map);

        if (this->current->neighbor[Up][X] != NOTSPOT)
            this->neighbor[Up] = &spot[this->current->neighbor[Up][X]][this->current->neighbor[Up][Y]];
        else
            this->neighbor[Up] = &this->stone;

        if (this->current->neighbor[Down][X] != NOTSPOT)
            this->neighbor[Down] = &spot[this->current->neighbor[Down][X]][this->current->neighbor[Down][Y]];
        else
            this->neighbor[Down] = &this->stone;

        if (this->current->neighbor[Left][X] != NOTSPOT)
            this->neighbor[Left] = &spot[this->current->neighbor[Left][X]][this->current->neighbor[Left][Y]];
        else
            this->neighbor[Left] = &this->stone;

        if (this->current->neighbor[Right][X] != NOTSPOT)
            this->neighbor[Right] = &spot[this->current->neighbor[Right][X]][this->current->neighbor[Right][Y]];
        else
            this->neighbor[Right] = &this->stone;

        for (auto i:this->neighbor) {
            if (i == &stone)
                continue;
            if (this->close.isExist(i))
                continue;
            int test = current->g + 1;
            if ((open.isExist(i)) && (test >= i->g)) {
                continue;
            }
            i->g = test;
            i->cal_H(*this->end);
            i->cal_F();
            if (!this->open.isExist(i)) {
                this->open.add(i);
            }
            i->camefrom=current;
        }
    }
    if(open.isEmpty())
    {
        cout<<"it does not have a path to End:"<<this->end->x<<"\t"<<this->end->y<<endl;
        flag=0;
    }
    else{
        cout<<"finished"<<endl;
        this->end=this->current;
        flag=1;
    }
}

void Astar::printPath() {
    if(this->flag==0)
        return;
    node *q=this->end;
    while(q!=this->start){
        cout<<"X:"<<q->x<<"\tY:"<<q->y<<endl;
        q=q->camefrom;
        this->map[q->x][q->y]='*';
    }
    cout<<"X:"<<q->x<<"\tY:"<<q->y<<endl;
    this->map[this->start->x][this->start->y]='#';
    this->map[this->end->x][this->end->y]='#';

    for(auto i:this->map){
        for(int j=0;j<COL;++j)
            cout<<i[j]<<"\t";
        cout<<endl;
    }
}
