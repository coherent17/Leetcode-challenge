int max(int a, int b){
    return a > b ? a : b;
}

bool isInArray(int *nums, int target, int numsSize){
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == target) return true;
    }
    return false;
}

int longestConsecutive(int* nums, int numsSize){
    if(numsSize < 2) return numsSize;
    
    int ret = 1;
    
    for(int i = 0; i < numsSize; i++){
        int count = 1;
        int curr = nums[i];
        while(isInArray(nums, curr+1, numsSize)){
            count++;
            curr++;
        }
        ret = max(ret, count);
    }
    return ret;
}