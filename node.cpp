//
// Created by allen on 19-4-1.
//

#include "node.h"

linklist::linklist() {
    start = nullptr;
    small = nullptr;
}

void linklist::init(spot value) {
    struct node *s, *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = nullptr;
    if (start == nullptr) {
        temp->prev = nullptr;
        start = temp;
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

//node* linklist::smallF() {
//
//}
bool linklist::isEmpty() {
    return (start == nullptr);
}

bool linklist::isExist(spot value) {
    node *q = this->start;
    int a = 0;
    while (q->next != nullptr) {
        if ((q->info.x == value.x) && (q->info.y == value.y))
            a = 1;
        q = q->next;
    }
    return a == 1;

}

bool linklist::isEqual(spot value1, spot value2) {
    return ((value1.x == value2.x) && (value1.y == value2.y));
}

void linklist::search(spot value) {

}

void linklist::delThis(spot value) {
    node *temp, *q = start, *prev, *next;
    while (q->next != nullptr) {
        if (isEqual(q->next->info, value)) {
            break;
        }
        q = q->next;
    }
    temp=q->next;
    next=temp->next;
    prev=temp->prev;
    prev->next=next;
    if(next!= nullptr)
        next->prev=prev;

}

void linklist::delAfter(spot value) {

}

void linklist::printList() {
    node *q;
    q = start;
    while (q->next != nullptr) {
        q = q->next;
        cout << "X:" << q->info.x << "\tY:" << q->info.y << endl;
    }


}