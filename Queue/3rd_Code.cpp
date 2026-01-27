#include <iostream>
using namespace std;
// Circular Queue implementation in C++

#define MAX 5
class CircularQueue {
private:
    int front, rear;
    int arr[MAX];       
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }
    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }
    bool isEmpty() {
        return front == -1;
    }
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = element;
        cout << element << " enqueued to queue\n";
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int element = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        cout << element << " dequeued from queue\n";
        return element;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};
int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();
    cq.dequeue();
    cq.display();
    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60);
    cq.display();
    cq.enqueue(70); // This should show queue is full
    return 0;
}