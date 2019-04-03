//
// Created by allen on 19-4-1.
//

#include "node.h"
linklist::linklist() {
    start= nullptr;
    small= nullptr;
}
void linklist::init(spot  value) {
    struct node *s, *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = nullptr;
    if (start == nullptr)
    {
        temp->prev = nullptr;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != nullptr)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}
void linklist::addBegin(spot value) {
    node *temp;
    temp=new(struct node) ;
    temp->prev= start;
    temp->info=value;
    temp->next=start->next;
    start->next=temp;

    cout<<"element inserted at begin"<<endl;
}
void linklist::addEnd(spot value) {

    node *temp,*q=start;
    temp=new(struct node);
    while(q->next!=nullptr)
    {
        q=q->next;
    }
    temp->info=value;
    temp->prev=q;
    temp->next= nullptr;
    q->next=temp;

    cout<<"element inserted at end"<<endl;
}
//node* linklist::smallF() {
//
//}
bool linklist::isEmpty() {
    return (start== nullptr);
}
bool linklist::isExist(spot value) {
return true;
}
void linklist::search(spot value) {

}
void linklist::delThis(node value) {

}
void linklist::delAfter(node value) {

}
void linklist::printList() {
    node* q;
    q=start;
    while(q->next!= nullptr)
    {
        q=q->next;
        cout<<"X:"<<q->info.x<<"\tY:"<<q->info.y<<endl;
    }


}