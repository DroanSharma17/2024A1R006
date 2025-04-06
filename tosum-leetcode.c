int* twoSum(int* nums, int n, int target, int* rSize) {
    int *arr=calloc(sizeof(int),2); // 2 integer ke array ki memory allocate ki
    *rSize=2; //number of elements in returned array
    for(int i=0;i<n-1;i++){
        for(int j= i+1 ; j < n; j++){
            if((nums[i]+nums[j])==target){
                arr[0]=i;
                arr[1]=j;
                return arr;
            }
        }
    }
    return arr;
}
