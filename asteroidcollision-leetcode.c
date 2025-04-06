//Leetcode #735
bool positive(int x) {
    return x > 0;
}

int* asteroidCollision(int* asteroids, int n, int* returnSize) {
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) {
        int ast = asteroids[i];

        while (top >= 0 && positive(stack[top]) && !positive(ast)) {
            if (stack[top] == -ast) {
                top--;  //destroyed
                ast = 0; //destroyed
                break;
            } else if (stack[top] > -ast) {
                ast = 0; //smaller one destroyed
                break;
            } else {
                top--;//smaller one destroyed
            }
        }

        if (ast != 0) {
            stack[++top] = ast;
        }
    }

    *returnSize = top + 1;
    return stack;
}
