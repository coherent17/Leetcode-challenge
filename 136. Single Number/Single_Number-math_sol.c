#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool inArray(int *, int, int);
int singleNumber(int *, int);

int main(){
    int nums[]={4,1,2,1,2};
    printf("%d",singleNumber(nums,sizeof(nums)/sizeof(int)));
    return 0;
}


//assume the array contain a,b,c three element:  array[]=[a,b,c,b,a]
//want to find out who is the one appear only once
//store the non-repeat element set(a,b,c)
//since 2*(a+b+c)-(a+b+c+b+a)=c
//return the answer of 2*sumofset-sumofarray 

int singleNumber(int* nums, int numsSize){
    int *non_repear_element_set=(int *)malloc((numsSize/2+1)*sizeof(int));
    int set_index=0;//control the index (or length) of the non_repear_element_set
    int sumofSet=0;
    int sumofNums=0;
    for(int i=0;i<numsSize;i++){
        if(!inArray(non_repear_element_set,nums[i],set_index)){
            non_repear_element_set[set_index]=nums[i];
            set_index+=1;
            sumofSet+=nums[i];
        }
        sumofNums+=nums[i];
    }
    return 2*sumofSet-sumofNums;
}

//check is the element number is in the array?
bool inArray(int *array, int number,int length){
    for(int i=0;i<length;i++){
        if(array[i]==number) return true;
    }
    return false;
}