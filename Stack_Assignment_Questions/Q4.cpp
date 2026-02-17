// Enter a string and check for the non-alphabatical characters appearance in that string using stack
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

    cout << "Enter a string: ";
    cin >> str;

    // Push each character onto the stack
    for (char ch : str) {
        stack.push(ch);
    }

    cout << "Non-alphabetical characters in the string are: ";
    // Pop each character from the stack and check for non-alphabetical characters
    while (!stack.isEmpty()) {
        char ch = stack.pop();
        if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))) {
            cout << ch << " ";
        }
    }
    cout << endl;

    return 0;
}
