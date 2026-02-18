//Create a linked list in a sorted order. Write a function to insert a new node in the sorted way.
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class LinkedList {
    Node* head;
public:
    LinkedList() { head = nullptr; }
    void insertSorted(int val);
    void display();
};  
void LinkedList::insertSorted(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr || head->data >= val) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < val) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}
void LinkedList::display() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}
int main() {
    LinkedList list;
    int n, val;

    cout << "Enter the number of elements to insert: ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertSorted(val);
    }

    cout << "Linked List in sorted order:" << endl;
    list.display();

    return 0;
}