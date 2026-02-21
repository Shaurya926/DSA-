//Create a stack of more size and convert this stack into circulaar linked list.
//taking under the consideration that the top most element of the 
// stack must be the last node of the circular linked list.
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

    // Free the allocated memory
    if (head) {
        Node* current = head->next;
        while (current != head) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete head;
    }
}
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.convertToCircularLinkedList();
    return 0;
}
