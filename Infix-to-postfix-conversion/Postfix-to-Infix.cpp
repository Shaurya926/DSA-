#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToInfix(string postfix) {
    stack<string> st;

    for (char c : postfix) {
        if (isOperator(c)) {
            // Pop two operands from stack
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            // Combine them into an infix expression
            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        } else {
            // Operand: push as string
            st.push(string(1, c));
        }
    }

    // Final expression on stack
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    string infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;

    return 0;
}