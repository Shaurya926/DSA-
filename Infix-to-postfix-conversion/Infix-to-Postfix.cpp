#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   // for isalnum()
#include <string.h>  // for strlen()

#define MAX 100

// Stack implementation
struct Stack {
    int top;
    char items[MAX];
};

void push(struct Stack* s, char c) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = c;
}

char pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

char peek(struct Stack* s) {
    if (s->top == -1) return -1;
    return s->items[s->top];
}

// Function to check precedence of operators
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char* infix) {
    struct Stack s;
    s.top = -1;
    char postfix[MAX];
    int i, k = 0;

    for (i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        // If operand, add to postfix
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            push(&s, c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (s.top != -1 && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); // remove '('
        }
        // If operator
        else {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(c)) {
                postfix[k++] = pop(&s);
            }
            push(&s, c);
        }
    }

    // Pop remaining operators
    while (s.top != -1) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

// Driver code
int main() {
    char infix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);
    return 0;
}