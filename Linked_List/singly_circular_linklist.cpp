#include <iostream>
#include <cstdlib>
#define null 0
using namespace std;

struct scll
{
    int data;
    scll *next;
};
scll *first, *temp, *ttemp, *createFirst,*createtemp;
void createfirst()
{
    first = new scll;
    cout << "Enter data for first node: ";
    cin >> first->data;
    first->next = first;
}
void addnode()
{
    temp = first;
    while (temp->next != first)
    {
        temp = temp->next;
    }
    ttemp = new scll;
    cout << "Enter data for new node: ";
    cin >> ttemp->data;
    ttemp->next = first;
    temp->next = ttemp;
}
void display()
{
    temp = first;
    cout << "list:";
    do
    {
        createtemp->data;
        temp = temp->next;
    }while (temp != first);
    cout << endl;
}
    int main() {
    createfirst();
    addnode();
    addnode();
    display();
    return 0;
}

