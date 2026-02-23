// A singly linked list contains mixed data of alphabets and integers.
// Convert the singly linked list into two stacks such that one stack
// contains only alphabets and the other stack contains all the other value.
#include <iostream>
using namespace std;
#define MAX 100
class Stack {
    int top;
    int arr[MAX];
public:
    Stack() { top = -1; }
    bool isFull() { return top == MAX - 1; }
    bool isEmpty() { return top == -1; }
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
    void convertToCircularLinkedList();
};
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
void Stack::convertToCircularLinkedList() {
    if (isEmpty()) {
        cout << "Stack is empty, cannot convert to circular linked list.\n";
        return;
    }
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = top; i >= 0; i--) {
        Node* newNode = new Node(arr[i]);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = head; // Making it circular

    // Display the circular linked list
    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    stack.convertToCircularLinkedList();

    return 0;
}
