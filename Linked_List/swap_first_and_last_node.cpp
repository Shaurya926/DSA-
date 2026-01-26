#include <iostream>
using namespace std;
// Swap first and last node of linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
void swapFirstAndLast(Node** head) {
    if (*head == nullptr || (*head)->next == nullptr) {
        return; // No swap needed for empty or single node list
    }

    Node* first = *head;
    Node* second = first->next;
    Node* prev = nullptr;
    Node* current = first;

    // Traverse to the last node
    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }
    Node* last = current;

    // If there are only two nodes
    if (first->next == last) {
        last->next = first;
        first->next = nullptr;
        *head = last;
        return;
    }

    // Swap first and last nodes
    prev->next = first; // Link previous node to first
    last->next = second; // Link last node to second
    first->next = nullptr; // First node becomes the last node
    *head = last; // Update head to point to the new first node
}
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    swapFirstAndLast(&head);

    cout << "List after swapping first and last nodes: ";
    printList(head);

    return 0;
}