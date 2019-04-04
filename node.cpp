//
// Created by allen on 19-4-1.
//

#include "node.h"

spot::spot() {

    this->x = 99;
    this->y = 99;
    this->f = 99;
    this->g = 0;
    this->h = 0;
}

spot::spot(int x, int y) {

    this->x = x;
    this->y = y;
    this->f = 99;
    this->g = 0;
    this->h = 0;
}

int spot::cal_F(spot prev, spot goal) {
    this->g = prev.g + 1;
    this->h = abs(this->x - goal.x) + abs(this->y - goal.y);
    this->f = this->g + this->h;
    return this->f;
}

void spot::getNeighbor() {
    neighbor[Up][X] = (this->y==0)?NOTSPOT:this->x;
    neighbor[Up][Y] = (this->y==0)?NOTSPOT:this->y - 1;
    neighbor[Down][X] = (this->y==COL-1)?NOTSPOT:this->x;
    neighbor[Down][Y] = (this->y==COL-1)?NOTSPOT:this->y + 1;
    neighbor[Left][X]=(this->x==0)?NOTSPOT:this->x-1;
    neighbor[Left][Y]=(this->x==0)?NOTSPOT:this->y;
    neighbor[Right][X] = (this->x==ROW-1)?NOTSPOT:this->x + 1;
    neighbor[Right][Y] = (this->x==ROW-1)?NOTSPOT:this->y;
}

linklist::linklist() {
    start = nullptr;
    small = nullptr;
}

void linklist::init() {
    spot value;
    struct node *s, *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = nullptr;
    if (start == nullptr) {
        temp->prev = nullptr;
        start = temp;
        small = temp;
    } else {
        s = start;
        while (s->next != nullptr)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }

}

void linklist::addBegin(spot value) {
    node *temp;
    temp = new(struct node);
    temp->prev = start;
    temp->info = value;
    temp->next = start->next;
    start->next = temp;

    cout << "element inserted at begin" << endl;
}

void linklist::addEnd(spot value) {

    node *temp, *q = start;
    temp = new(struct node);
    while (q->next != nullptr) {
        q = q->next;
    }
    temp->info = value;
    temp->prev = q;
    temp->next = nullptr;
    q->next = temp;

    cout << "element inserted at end" << endl;
}

spot *linklist::smallF() {
    node *q = start;
    while (q->next != nullptr) {
        q = q->next;
        if (q->info.f < small->info.f)
            small = q;
    }
    return &(small->info);

}

bool linklist::isEmpty() {
    return (start->next == nullptr);
}

bool linklist::isExist(spot value) {
    node *q = this->start;
    int a = 0;
    while (q->next != nullptr) {
        q = q->next;
        if ((q->info.x == value.x) && (q->info.y == value.y))
            a = 1;
    }
    return a == 1;

}

bool linklist::isEqual(spot value1, spot value2) {
    return ((value1.x == value2.x) && (value1.y == value2.y));
}

spot* linklist::search(spot value) {
    node *q=this->start;
    while(q->next!= nullptr)
    {
        q=q->next;
        if(this->isEqual(q->info,value))
            break;
    }
    return &(q->info);
}

void linklist::delThis(spot value) {
    node *q = this->start, *prev=start, *next;

    while (q->next != nullptr) {
        q = q->next;
        if (isEqual(q->info, value)) {
            break;
        }
    }
    if(q->next== nullptr)
    {
        q->prev->next=nullptr;
    }
    else
    {
        prev=q->prev;
        next=q->next;
        prev->next=next;
        next->prev=prev;
        cout<<endl;
    }

}

void linklist::delAfter(spot value) {
    node *temp, *q = start;
    while (q->next != nullptr) {
        if (isEqual(q->next->info, value)) {
            break;
        }
        q = q->next;
    }
    temp = q;
    temp->next = nullptr;
}

void linklist::printList() {
    node *q;
    q = start;
    while (q->next != nullptr) {
        q = q->next;
        cout << "X:" << q->info.x << "\tY:" << q->info.y << endl;
    }


}