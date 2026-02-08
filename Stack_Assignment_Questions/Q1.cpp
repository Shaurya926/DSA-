//Reverse a number using an array implementation of stack
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
    Stack stack;
    int number, digit;

    cout << "Enter a number to reverse: ";
    cin >> number;

    // Push each digit onto the stack
    while (number != 0) {
        digit = number % 10;
        stack.push(digit);
        number /= 10;
    }

    cout << "Reversed number: ";
    // Pop each digit from the stack to get the reversed number
    while (!stack.isEmpty()) {
        cout << stack.pop();
    }
    cout << endl;

    return 0;
}
