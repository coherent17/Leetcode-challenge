int wiggleMaxLength(int* nums, int numsSize){
    
    int dp_up[numsSize];
    int dp_down[numsSize];
    
    dp_up[0] = 1;
    dp_down[0] = 1;
    
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[i - 1]){
            dp_down[i] = dp_down[i - 1];
            dp_up[i] = dp_up[i - 1];
        }
        else if(nums[i] < nums[i - 1]){
            dp_down[i] = dp_up[i - 1] + 1;
            dp_up[i] = dp_up[i - 1];
        }
        else{
            dp_up[i] = dp_down[i - 1] + 1;
            dp_down[i] = dp_down[i - 1];
        }
    }
    int result = dp_up[numsSize - 1] > dp_down[numsSize - 1] ? dp_up[numsSize - 1] : dp_down[numsSize - 1];
    return result;
}