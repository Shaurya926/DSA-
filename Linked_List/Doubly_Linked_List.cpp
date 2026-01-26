#include <iostream>
using namespace std;
 struct Node{
    int data;
    Node* next;
    Node* prev;
 };
    Node* head = NULL;
     //Insert at the end of the doubly linked list
     void insert(int val){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;
        if(head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
     }
        //Display the doubly linked list
        void display(){
            Node* temp = head;
            cout << "Doubly Linked List: ";
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        int main(){
            insert(10);
            insert(20);
            insert(30);
            display();
            return 0;
        }