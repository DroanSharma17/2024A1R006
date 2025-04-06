#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100
int queue[SIZE], front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (rear + 1) % SIZE == front;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = data;
    printf("Data inserted successfully\n");
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return data;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front];
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i = front;
    while (true) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Queue is full\n");
                    break;
                }
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                if (isEmpty()) {
                    printf("Queue is empty\n");
                    break;
                }
                printf("%d is dequeued\n", dequeue());
                break;
            case 3:
                if (isEmpty()) {
                    printf("Queue is empty\n");
                    break;
                }
                printf("Element at front: %d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        system("Pause");
    }
    return 0;
}
