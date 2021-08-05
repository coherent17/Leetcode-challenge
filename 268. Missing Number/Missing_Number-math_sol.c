#include <stdio.h>

int missingNumber(int *, int);

int main(){
    int nums[]={9,6,4,2,3,5,7,0,1};
    int number=missingNumber(nums, sizeof(nums)/sizeof(int));
    printf("%d\n", number);
    return 0;
}

//time complexity:O(n)
int missingNumber(int* nums, int numsSize){
    int sum=numsSize*(numsSize+1)/2;
    for(int i=0;i<numsSize;i++){
        sum-=nums[i];
    }
    return sum;
}