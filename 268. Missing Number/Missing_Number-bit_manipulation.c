#include <stdio.h>

int missingNumber(int *, int);

int main(){
    int nums[]={9,6,4,2,3,5,7,0,1};
    int number=missingNumber(nums, sizeof(nums)/sizeof(int));
    printf("%d\n", number);
    return 0;
}

//time complexity:O(n)
//use XOR:
//since: a⊕0=a, a⊕a=0
//if we XOR all of the index and the element of the array, then we can get the missing number
//ex:array=[0,1,3]
//(0⊕1⊕3)⊕(0⊕1⊕2)⊕3=(0⊕0)⊕(1⊕1)⊕(3⊕3)⊕2=2
int missingNumber(int* nums, int numsSize){
    int answer=0;
    int i;
    for(i=0;i<numsSize;i++){
        answer^=i^nums[i];
    }
    return answer^i;
}