//Implement a Queue using arrays and develop functions to perform enqueue and dequeue operaations
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100
int queue[SIZE], front = -1, rear = -1;
bool isEmpty() {
    return front == -1;
}
bool isFull() {
    return rear == SIZE - 1;
}
void enqueue(int data){
   queue[++rear] = data;
   if (front == -1){
    front = rear;
   }
   printf("Data inserted successfully\n");
}
int dequeue(){
    int data = queue[front];
    if (front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }
    return data;
}
int peek(){
    return queue[front];
}
int display(){
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main(){
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(isFull()){
                    printf("Queue is full\n");
                    break;
                }
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                if(isEmpty()){
                    printf("Queue is empty\n");
                    break;
                }
                printf("%d is dequeued\n", dequeue());
                break;
            case 3:
                printf("Element at front: %d", peek());
                break;
            case 4:
                if (isEmpty()){
                    printf("Queue is empty\n");
                    break;
                }
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
