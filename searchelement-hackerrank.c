//Search Element In List
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n; scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++){
    scanf("%d",&arr[i]);
    }
    int t; scanf("%d",&t);
    for (int i =0; i < n; i++){
        if (arr[i]==t){
        printf("Found");
            return 0;
        }
        
    }
    printf("Not Found");
    return 0;
}
