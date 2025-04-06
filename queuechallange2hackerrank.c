#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n; scanf("%d",&n);
    int queue[n];    int result[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&queue[i]);
        result[i] = -1;
    }

    for (int i =0; i < n; i++){
        for (int j=1; j < n; j++){
            if (queue[i] < queue[(i+j)%n]){
                result[i] = queue[(i+j)%n];
                break;
            }
        }
    }
    for (int i = 0; i<n; i++){
        printf("%d ",result[i]);
    }
    return 0;
}
