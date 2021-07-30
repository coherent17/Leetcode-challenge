#include <stdio.h>
#include <stdlib.h>

int* twoSum(int*, int, int, int*);

int main(){
    int nums[4]={2,7,11,15};
    int returnSize;
    int *result;
    result=twoSum(nums,4,9,&returnSize);
    printf("%d %d\n",result[0],result[1]);
    return 0;
}

// input arguments: array, length of the array, target value, the return array length (could be 2 or 0)
// return: the address of the result (array)

/*
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

}*/

//brute force: time complexity O(n^2)
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int* result=(int*)malloc(2*sizeof(int));
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                result[0]=i;
                result[1]=j;  
                *returnSize=2;
                return result;  
            }
        }
    }
    return NULL;
}