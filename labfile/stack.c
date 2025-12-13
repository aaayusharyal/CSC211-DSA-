#include <stdio.h>
#define MAX_SIZE 50

// Define the stack structure
struct stack {
    int arr[MAX_SIZE];
    int top;
} s1;

// Initialize the stack
void init(struct stack *s) {
    s->top = -1;  // top = -1 means stack is empty
}

// Check if stack is empty
int isempty(struct stack *s) {
    return (s->top == -1);
}

// Check if stack is full
int isfull(struct stack *s) {
    return (s->top == MAX_SIZE - 1);
}

// Push an element onto the stack
void PUSH(struct stack *s, int num) {
    if (isfull(s)) {
        printf("Stack Overflow\n");
    } else {
        s->arr[++(s->top)] = num; // increment top first, then assign value
        printf("Push success: %d\n", num);
    }
}

// Pop an element from the stack
void POP(struct stack *s) {
    if (isempty(s)) {
        printf("Stack Underflow\n");
    } else {
        int popped = s->arr[(s->top)--]; // get the top element, then decrement top
        printf("Popped element: %d\n", popped);
    }
}

// Peek the top element of the stack without removing it
void PEEK(struct stack *s) {
    if (isempty(s)) {
        printf("Stack is empty\n");
    } else {
        printf(" %d\n", s->arr[s->top]);
    }
}


int main() {
    init(&s1);
    if(isempty(&s1))
    {
        printf("Stack Empty\n");
    }
    else
    {printf("Not Empty\n");}
    PUSH(&s1, 10);
    if(isfull(&s1))
    {
        printf("Stack full\n");
    }
    else printf("Not full\n");
    POP(&s1);
    PEEK(&s1);
    return 0;
}
