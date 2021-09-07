#include <stdio.h>

int majorityElement(int *, int);

int main(){
    int nums[] = {2,2,1,1,1,2,2};
    printf("%d\n", majorityElement(nums, sizeof(nums) / sizeof(int)));
    return 0;
}

//time complexity: O(n^2), space complexity: O(1)
int majorityElement(int *nums, int numsSize){
    int maxCount = numsSize / 2;
    for (int i = 0; i < numsSize; i++){
        int count = 0;
        for (int j = 0; j < numsSize; j++){
            if (nums[i] == nums[j])
                count++;
            if (count > maxCount)
                return nums[j];
        }
    }
    return -1;
}