bool checkPossibility(int* nums, int numsSize){
    bool changed = false;
    
    for(int i = 0; i < numsSize - 1; i++){
        
        if(nums[i] <= nums[i + 1]) continue;
        
        if(changed) return false;
        
        if(i == 0 || nums[i + 1] >= nums[i - 1]){
            nums[i] = nums[i + 1];
        }
        else{
            nums[i + 1] = nums[i];
        }
        changed = true;
    }
    return true;
}