// Check if a string is a palindrome using an array implementation of stack
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100
class Stack {
    int top;
    char arr[MAX];
public:
    Stack() { top = -1; }
    void push(char x);
    char pop();
    bool isEmpty();
};
void Stack::push(char x) {
    if (top >= MAX - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    arr[++top] = x;
}
char Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return '\0';
    }
    return arr[top--];
}
bool Stack::isEmpty() {
    return top == -1;
}
int main() {
    Stack stack;
    string str;

    cout << "Enter a string to check for palindrome: ";
    cin >> str;

    // Push each character onto the stack
    for (char ch : str) {
        stack.push(ch);
    }

    bool isPalindrome = true;
    // Pop each character from the stack and compare with the original string
    for (char ch : str) {
        if (ch != stack.pop()) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }

    return 0;
}
