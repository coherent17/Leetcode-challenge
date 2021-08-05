#include <stdio.h>
#include <stdbool.h>

bool inArray(int *, int, int);
int missingNumber(int *, int);

int main(){
    int nums[]={9,6,4,2,3,5,7,0,1};
    int number=missingNumber(nums, sizeof(nums)/sizeof(int));
    printf("%d\n", number);
    return 0;
}

//time complexity:O(n^2)
int missingNumber(int* nums, int numsSize){
    int i;
    for(i=0;i<numsSize;i++){
        if(!inArray(nums, numsSize, i)) break;
    }
    return i;
}

bool inArray(int *array, int length, int number){
    for(int i=0;i<length;i++){
        if(array[i]==number) return true;
    }
    return false;
}