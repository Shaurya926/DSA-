#include <iostream>
using namespace std;

// Queue implementation using array.

#define MAX 5
struct Queue {
    int data[MAX]; //array to store queue elements.
    int front, rear;
};

//created global variables.
Queue *P,Q1;
//Fist init function called to initialize front and rear.
void init(){
    P = &Q1;
     //Initialize pointer to point to Q1.
    P->front = P->rear = -1;
    //-1 indicates empty queue.
}

int Full(){
    if(P->rear == MAX - 1) 
    //When rear reaches max size.
    // When rear is at last index, queue is full than the condition is true and return 1 end of the function.
        return 1;
    else
    //Otherwise return 0.
        return 0;
}

//Function to check whether queue is empty or not.
int Empty(){
    if(P->front == -1)
    //When front is -1, it means queue is empty.
    // So return 1.
    //or the condition is false return 0.
        return 1;
    else
        return 0;
}

//Function to insert element in the queue.
void Enqueue(int x){
    if(Full()==1)
    return;
    if(P->front==-1)
     //Every first insertion when queue is empty.
    //When front is -1, it means the queue is empty.
    //front and rear both are in undefined state.
        P->front=P->rear=0;
    else
        P->rear++; //Increment rear to point to next position.
    P->data[P->rear]=x; // P->data[P->rear] means inserting element at rear position.
}

int Dequeue(){
    int x;
    if(Empty()==1)
        return -1;
    x=P->data[P->front];
    if(P->front==P->rear)
    //When only one element is present in the queue front and rear both point to same index.
    //After deletion queue will be empty.
        P->front=P->rear=-1;
    else
        P->front++;
    //Return the deleted element.
    return x;
}

void Display(){
    if(Empty()==1)
        return;
    for(int i=P->front;i<=P->rear;i++)
        cout<<P->data[i]<<" ";
    cout<<endl;
}

int main(){
    init();
    Enqueue(10);// First calling to Enqueue function.
    Enqueue(20);
    Enqueue(30);
    Display();
    cout<<Dequeue()<<endl;
    Display();
    Enqueue(40);
    Enqueue(50);
    Enqueue(60);
    Display();
    return 0;
}