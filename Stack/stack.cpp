//stack implementation using linked list
#include <iostream>
using namespace std;

struct stack {
    int data;
    stack *next;
};
stack *top, *temp, *ttemp;
void init() {
    top = temp = ttemp = NULL;
}
void push(int x){
    temp = new stack;
    if(temp == NULL)
    return;
temp->data = x;
temp->next = top;
top=temp;
}
int pop(){
    int x;
if(top == NULL)
    return -1;
x = top->data;
ttemp = top;
top = top->next;
temp = NULL;
delete ttemp;
return x;
}
int main() {
    init();
    push(10);
    push(20);
    push(30);
    std::cout << pop() << std::endl;
    std::cout << pop() << std::endl;
    std::cout << pop() << std::endl;
    return 0;
}