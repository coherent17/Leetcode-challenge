#include <stdio.h>

int removeDuplicates(int *, int);

int main(){
    int nums[]={0,0,1,1,1,2,2,3,3,4};
    int k=removeDuplicates(nums, sizeof(nums)/sizeof(int));
    printf("k=%d\n", k);
    for(int i=0;i<k;i++){
        printf("%d ",nums[i]);
    }
    return 0;
}

//time complexity:O(n)
int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0) return 0;
    int i=0;
    for(int j=1;j<numsSize;j++){
        if(nums[j]!=nums[i]){
            //move to the next space, and put nums[j] inside
            nums[++i]=nums[j];
        } 
    }
    return i+1;
}