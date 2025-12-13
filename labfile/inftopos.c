#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100  // remove the semicolon here

char stack[MAX];
int top = -1;

// Push onto stack
void push(char x) {
    stack[++top] = x;
}

// Pop from stack
char pop() {
    return stack[top--];
}

// Peek top element
char peek() {
    return top == -1 ? '\0' : stack[top];
}

// Return operator precedence
int precedence(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

// Check if character is operator
int isOperator(char x) {
    return x=='+' || x=='-' || x=='*' || x=='/' || x=='^';
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int j = 0;
    char c;
    for (int i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (isalnum(c)) {  // Operand
            postfix[j++] = c;
        } 
        else if (c == '(') {
            push(c);
        } 
        else if (c == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        } 
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0'; // null terminate
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
