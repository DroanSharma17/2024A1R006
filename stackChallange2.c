#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

bool isEmpty(){
    return top == -1;
}
bool isFull(){
    return top == MAX_SIZE-1;
}
void push(int value){
    if (!isFull())
        stack[++top] = value;
}

void display(){
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}
void pop(){
    if (!isEmpty())
        top--;
}

int main() {
    int n; scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int v; scanf("%d", &v);
        push(v);
    }
    for (int i = 0; i < 2; i++){
        pop();
    }
    for (int i = 0; i < 4; i++) {
        int v; scanf("%d", &v);
        push(v);
    }
    pop();
    for (int i = 0; i < 2; i++) {
        int v;  scanf("%d", &v);
        push(v);
    }
    for (int i = 0; i < 3; i++) {
        pop();
    }
    display();
    return 0;
}
