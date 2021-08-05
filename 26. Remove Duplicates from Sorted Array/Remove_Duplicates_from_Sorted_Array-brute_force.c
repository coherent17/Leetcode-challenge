#include <stdio.h>
#include <stdbool.h>

bool inArray(int *, int, int);
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

//time complexity:O(n^2), space complexity:O(n)
int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0) return 0;
    int index=1;
    int non_repeat_element[numsSize];
    non_repeat_element[0]=nums[0];
    for(int i=1;i<numsSize;i++){
        if(!inArray(non_repeat_element, index, nums[i])){
            non_repeat_element[index]=nums[i];
            index+=1;
        }
    }

    //copy the element to nums1
    for(int i=0;i<index;i++){
        nums[i]=non_repeat_element[i];
    }
    return index;
}

bool inArray(int *array, int length, int number){
    for(int i=0;i<length;i++){
        if(array[i]==number) return true;
    }
    return false;
}
