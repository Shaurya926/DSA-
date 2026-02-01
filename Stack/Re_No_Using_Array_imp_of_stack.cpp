#include <iostream>
using namespace std;

#define MAX 20

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s;
    int num, digit, reversed = 0;

    cout << "Enter a number: ";
    cin >> num;

    // Push digits into stack
    while (num > 0) {
        digit = num % 10;
        s.push(digit);
        num /= 10;
    }

    // Pop digits to reverse number
    while (!s.isEmpty()) {
        reversed = reversed * 10 + s.pop();
    }

    cout << "Reversed number: " << reversed << endl;

    return 0;
}