#include <stdio.h>

int arrayNesting(int* nums, int numsSize){
    int result = 0;
    for (int i = 0; i < numsSize;i++){

        int temp = nums[i], count = 0;
        temp = nums[temp];
        count++;

        //it will finally back to the element we start
        while(temp!=nums[i]){
            temp = nums[temp];
            count++;
        }
        result = (result > count) ? result : count;
    }
    return result;
}

int main(){
    int nums[] = {5, 4, 0, 3, 1, 6, 2};
    int result = arrayNesting(nums, sizeof(nums) / sizeof(int));
    printf("%d\n", result);
    return 0;
}