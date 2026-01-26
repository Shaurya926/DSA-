#include <iostream>
#include <cstdlib>
#define null 0
using namespace std;

struct node {
    int data;
    node *next, *prev;
};

node *first, *temp, *ttemp,*p;
void init() {
    first = temp = ttemp = null;
}
void createfirst(int val) {
    first = new node;
    first->data = val;
    first->next = null;
    first->prev = null;
}

void addnode(int val) {
    temp = first;
    while (temp->next != null) {
        temp = temp->next;
    }

    ttemp = new node;
    ttemp->data = val;
    ttemp->next = null;
    ttemp->prev = temp;

    temp->next = ttemp;
}
void swapsl()
{
    if(first==null || first->next==null)
    return;
    node* second=first->next;
    first->next=second->next;
    if(second->next!=null)
    second->next->prev=first;
    second->prev=null;
    second->next=first;
    first->prev=second;
    first=second;
}
void display() {
    temp = first;
    cout << "List: ";
    while (temp != null) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    init();
    createfirst(10);
    addnode(20);
    addnode(30);

    display();
    swapsl();
    display();

    return 0;
}

    