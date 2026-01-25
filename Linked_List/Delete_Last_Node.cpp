#include <iostream>
#include <cstdlib>
#define null 0
using namespace std;
struct node {
    int data;
    node *next;
};

node *first, *temp, *ttemp;
void init() {
    first = temp = ttemp = null;
}
void del_last()
{
    temp=first;
    while(temp->next!=first)
    {
        ttemp=temp;
        temp=temp->next;
    }
    ttemp->next=first;
    temp->next=null;
    delete temp;
}
void createfirst(int val) {
    first = new node;
    first->data = val;
    first->next = first;
}
void addnode(int val) {
    temp = first;
    while (temp->next != first) {
        temp = temp->next;
    }

    ttemp = new node;
    ttemp->data = val;
    ttemp->next = first;

    temp->next = ttemp;
}
void display() {
    temp = first;
    cout << "List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != first);
    cout << endl;
}
int main() {
    init();
    createfirst(10);
    addnode(20);
    addnode(30);
    display();
    del_last();
    display();
    return 0;
}