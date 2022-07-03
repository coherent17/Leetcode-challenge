int wiggleMaxLength(int* nums, int numsSize){
    int up = 1;
    int down = 1;
    
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[i - 1]) continue;
        else if(nums[i] > nums[i - 1]) up = down + 1;
        else down = up + 1;
    }
    return up > down ? up : down;
}