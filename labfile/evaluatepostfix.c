#include <stdio.h>
#include <ctype.h>
#include <math.h>   // for pow()
#define MAX 100

int stack[MAX];
int top = -1;

// Push onto stack
void push(int x) {
    stack[++top] = x;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// Evaluate a postfix expression
int evaluatePostfix(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (isdigit(c)) {  // If operand, push to stack
            push(c - '0'); // Convert char to int
        } else {           // Operator
            int val2 = pop();
            int val1 = pop();
            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push((int)pow(val1, val2)); break;
            }
        }
    }
    return pop();  // Final result
}

int main() {
    char exp[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);

    return 0;
}
