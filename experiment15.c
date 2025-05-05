//Implement a Binary Tree using Linked List and develop functions to perform traversal, searching, insertion and deletion operations. 
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    struct TreeNode* left;
    int data;
    struct TreeNode* right;
} Node;

Node* createNode(int value){
    Node* node = (Node*)malloc(sizeof(Node));
    Node->data = value;
    Node->left = Node->right = NULL;
    return Node;
}

void insert(Node* root,int value){
    if (root == NULL)   return createNode(value);
    Node queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (){
        Node* temp = queue[front++];
        if (temp->left == NULL){
            temp->left = createNode(value);
            break;
        }
        else if (temp->right == NULL){
            temp->right = createNode(value);
            break;
        }
        else{
            queue[rear++] = temp->left;
            queue[rear++] = temp->right;
        }
    }
    return root;
}  
void preorder(Node* root){
    if (root == NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){

}
void inorder(Node* root){
    if (root == NULL)   return;
    inorder(root -> left);
    printf("%d ",root -> data);
    inorder (root -> right);
}
void postorder(Node* root){
    if (root == NULL)   return;
    postorder
}
void levelorder(Node* root){
    if (root == NULL)   return;
    Node queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear){
        Node* temp = queue[front++];
        printf("%d ",temp->data);
        if (temp->left != NULL)   queue[rear++] = temp->left;
        if (temp->right != NULL)  queue[rear++] = temp->right;
    }
}
Node* search(Node* root, int target){
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear){
        Node* temp = queue[front++];
        if (temp->data == value){
            return temp;
        }
        if (temp->left != NULL)   queue[rear++] = temp->left;
        if (temp->right != NULL)  queue[rear++] = temp->right;
    }
    return NULL;
}
Node* findDeepest(Node* root){
    if (root == NULL)   return NULL;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    Node* temp = NULL;
    while (front != rear){
        temp = queue[front++];
        if (temp->left != NULL)   queue[rear++] = temp->left;
        if (temp->right != NULL)  queue[rear++] = temp->right;
    }
    int i = (rear-2)/2;
    if (queue[i]-> left == temp)    queue[i]->left = NULL;
    else    queue[i]->right = NULL;
    
    return temp;
}
void delete(Node* root, int value){
    if (root == NULL)   return;
    Node* temp = search(root, value);
    if (temp == NULL)   printf("Element Not Found!!\n");
    else{
        Node* last = findDeepest(root);
        temp->data = last->data;
    }
}
int main(){
    int choice, val;
    while (1){
        printf("1. Insert\n");
        printf("2. Pre-order\n");
        printf("3. In-order\n");
        printf("4. Post-Order\n");
        printf("5. Level-Order\n");
        printf("6. Search\n");
        printf("8. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                break;
            case 2:
                preorder(root); break;
            case 3:
                inorder(root); break;
            case 4:
                postorder(root); break;
            case 5: 
                levelorder(root)    break;
            case 6:
                printf("Enter value to search: ");
                scanf("%d", &val);
                Node* result = search(root, val);
                if (result != NULL){
                    printf("Node found with value: %d\n", result->data);
                } else {
                    printf("Node not found.\n");
                }
                break;
            case 7: break;
            case 8: exit(0);
            default:    printf("Invalid Choice!!\n");
        }
        printf("\n");
    }
    return 0;
}
