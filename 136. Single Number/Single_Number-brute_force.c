#include <stdio.h>
#include <stdbool.h>

int singleNumber(int *, int);

int main(){
    int nums[]={4,1,2,1,2};
    printf("%d",singleNumber(nums,sizeof(nums)/sizeof(int)));
    return 0;
}

int singleNumber(int* nums, int numsSize){
    int i,j;
    //compare with all element:double linear search  O(n^2)
    for(i=0;i<numsSize;i++){
        int count=0;
        for(j=0;j<numsSize;j++){
            if(nums[i]==nums[j]){
                count+=1;

                //find itself and someone has the same value
                //go to the next element and set count as 0
                if(count==2){
                    count=0;
                    break;
                }
            }
        }
        if(count==1) break;
    }
    return nums[i];
}