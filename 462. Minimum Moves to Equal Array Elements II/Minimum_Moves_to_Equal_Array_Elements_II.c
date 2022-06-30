int cmp(void *a, void *b){
    return *(int *)a - *(int *)b;
}

int minMoves2(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    
    int median = nums[numsSize / 2];
    int res = 0;
    for(int i = 0; i < numsSize; i++){
        res += abs(median - nums[i]);
    }
    return res;
}