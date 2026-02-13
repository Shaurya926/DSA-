// CCreate stack of 5-5 size and merge them in third stack of 10-10 size in alternate manner.
#include <iostream>
using namespace std;
#define MAX 10
class Stack {
    int top;
    int arr[MAX];
public:

    Stack() { top = -1; }
    void push(int x);
    int pop();
    bool isEmpty();
};
void Stack::push(int x) {
    if (top >= MAX - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    arr[++top] = x;
}
int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    return arr[top--];
}
bool Stack::isEmpty() {
    return top == -1;
}
int main() {
    Stack stack1, stack2, mergedStack;
    int element;

    cout << "Enter 5 elements for Stack 1:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> element;
        stack1.push(element);
    }

    cout << "Enter 5 elements for Stack 2:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> element;
        stack2.push(element);
    }

    // Merging stacks in alternate manner
    for (int i = 0; i < 5; i++) {
        if (!stack1.isEmpty()) {
            mergedStack.push(stack1.pop());
        }
        if (!stack2.isEmpty()) {
            mergedStack.push(stack2.pop());
        }
    }

    cout << "Merged Stack elements in alternate manner:" << endl;
    while (!mergedStack.isEmpty()) {
        cout << mergedStack.pop() << " ";
    }
    cout << endl;

    return 0;
}