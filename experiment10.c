//Implement a Stack using Linked List and develop functions to perform push and pop operations.
//15 April 2025
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
} Node;
Node* top = NULL;
void push (int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Stack Overflow!"); return;
    }
    newNode -> data = val;
    newNode -> next = top;
    top = newNode;
}
int pop(){
    if (top == NULL){
        printf("Stack Underflow!"); return -1;
    }
    Node* temp = top;
    top = top -> next;
    int a = temp -> data;
    free(temp);
    return a;
}
void show(){
    Node* temp = top;
    while (temp != NULL){
    printf("%d -> ", temp->data);
        temp = temp-> next;
    }
    printf("\n");
}
int peek(){
    return (top != NULL) ? top -> data : -1;
}
int main(){
    while (1){
        printf("1. Push \n2. Pop\n3. Show\n4.Peek\n5. Exit\n");
        int choice;
        printf("Enter your choice: "); scanf("%d",&choice);
        switch(choice){
            case 1:
            {
                int val; printf("Enter Value : ");
                scanf("%d",&val);
                push(val);
                break;
            }
            case 2:
            { 
                int a = pop();
                if (a != -1){
                printf("%d popped\n", a);
                }
                break;
            }
            case 3:
            show();
                break;
            case 4:
            {
                int val = peek();
                if (val == -1)  printf("Stack empty");
                else    printf("%d at top\n", val);
                break;
            }
            case 5:
                exit(0);
            default:
                printf("Invalid Choice!!\n");
        }
        system("Pause");
    }
}
