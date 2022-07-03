int max(int a, int b){
    return a > b ? a : b;
}

int calculate(int  *nums, int index, bool isUp, int numsSize){
    int maxCount = 0;
    for(int i = index + 1; i < numsSize; i++){
        if((nums[index] < nums[i] && isUp) || nums[index] > nums[i] && !isUp){
            maxCount = max(maxCount, 1 + calculate(nums, i, !isUp, numsSize));
        }
    }
    return maxCount;
}

int wiggleMaxLength(int* nums, int numsSize){
    if(numsSize < 2) return numsSize;
    return 1 + max(calculate(nums, 0, true, numsSize), calculate(nums, 0, false, numsSize));
}