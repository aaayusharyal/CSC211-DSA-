#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = MAX - 1;
int rear  = MAX - 1;

/* Check if queue is empty */
int isEmpty()
{
    return (front == rear);
}

/* Check if queue is full */
int isFull()
{
    return ((rear + 1) % MAX == front);
}

/* Insert element */
void enqueue(int item)
{
    if (isFull())
    {
        printf("Circular Queue Overflow\n");
        return;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = item;
    printf("%d inserted\n", item);
}

/* Delete element */
void dequeue()
{
    if (isEmpty())
    {
        printf("Circular Queue Underflow\n");
        return;
    }

    front = (front + 1) % MAX;
    printf("%d deleted\n", queue[front]);
}

/* Peek front element */
void peek()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    int index = (front + 1) % MAX;
    printf("Front element: %d\n", queue[index]);
}

/* Display queue elements */
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Circular Queue elements:\n");
    int i = (front + 1) % MAX;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    peek();
    dequeue();
    display();

    return 0;
}
