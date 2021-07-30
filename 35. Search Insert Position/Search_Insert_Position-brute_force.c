#include <stdio.h>

int searchInsert(int*, int, int);

int main(){
    int nums[4]={1,3,5,6};
    int index;
    int target=5;
    index=searchInsert(nums, 4, target);
    printf("%d\n",index);
    return 0;
}

int searchInsert(int* nums, int numsSize, int target){
    int i;
    for(i=0;i<numsSize;i++){
        if(target<=nums[i]) return i;
    }
    return numsSize;
}