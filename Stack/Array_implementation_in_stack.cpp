#include <iostream>
using namespace std;
#define MAX 100
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
    cout << x << " pushed to stack" << endl;
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
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " popped from stack" << endl;
    return 0;
}