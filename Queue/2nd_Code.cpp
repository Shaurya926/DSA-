#include <iostream>
using namespace std;

struct LQueue {
    int data;
    LQueue* next;
};

LQueue *front, *rear;

void init(){
    front = rear = NULL;
}

void Enqueue(int x){
    LQueue* temp = new LQueue();
    if(temp == NULL){
        cout << "Memory allocation failed!" << endl;
        return;
    }
    temp->data = x;
    temp->next = NULL;

    if(front == NULL)   // empty queue
        front = rear = temp;
    else {
        rear->next = temp;
        rear = temp;
    }
}

int Dequeue(){
    if(front == NULL)
        return -1;   // empty queue

    int x = front->data;
    LQueue* temp = front;

    if(front == rear)
        front = rear = NULL;
    else
        front = front->next;

    delete temp;
    return x;
}

int main(){
    init();
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);

    cout << Dequeue() << endl;  // 10
    cout << Dequeue() << endl;  // 20
    cout << Dequeue() << endl;  // 30
}